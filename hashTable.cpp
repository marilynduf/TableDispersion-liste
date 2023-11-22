//
// Created by Marilyn Dufour on 2023-11-19.
//

#include "hashTable.h"
#include <iostream>

/**
 * \brief Construteur
 * \param nom
 */
HashTable::HashTable() {
    for (int i = 0; i < m_tableSize; ++i) {
        hashTable[i] = new item;
        hashTable[i]->name = "empty";
        hashTable[i]->drink = "empty";
        hashTable[i]->next = nullptr;
    }
};

/**
 * \brief Fonction de hachage 1 (clé est string)
 * \description :
 *      1. Ne supporte pas la permutation. ex.: 'stop', 'tops' (La somme des des codes ASCII sera toujours la même indice donc collision)
 *      2. Ne peut pas générer un entier de plus de d*255 ex.: 'stop' = 4 (4 char) donc 4*255. (resultat : dispersion pas uniforme ce qui cause des collisions)
 * \param key
 */
size_t HashTable::hash(const std::string &key, int typedeHachage) {
    size_t hash = 0; // type size_t car peut contenir de grande valeur (tjrs positives)
    switch (typedeHachage) {

        /*******************************************************************
         Trivial.. pas suggéré (ne considère PAS la position des caractères)
        ********************************************************************/
        case 1:
            for (auto i : key) {
                hash += i;
            }
            std::cout << key <<": " <<  hash << std::endl;
            return hash % m_tableSize;

        /*******************************************************************
         Polynomial (considère la position des caractères)
        ********************************************************************/
        case 2:
            for (auto i : key) {
                hash += 37 * hash + i;
            }
            std::cout << key <<": " <<  hash << std::endl;
            return hash % m_tableSize;

        /** Default *********************************************/
        default: std::cout <<"Pas de type de hachage" <<  hash << std::endl;
    }

}

/**
 * \brief Fonction de hachage 2 - Polynomial - (clé est string)
 * \description :
 *      1. Ne supporte pas la permutation. ex.: 'stop', 'tops' (La somme des des codes ASCII sera toujours la même indice donc collision)
 *      2. Ne peut pas générer un entier de plus de d*255 ex.: 'stop' = 4 (4 char) donc 4*255. (resultat : dispersion pas uniforme ce qui cause des collisions)
 * \param key
 */

int HashTable::numberOfItemsInIndex(int index) {
    int count = 0;
    if (hashTable[index]->name == "empty") {
        return count;
    }
    else {
        count++;
        item* ptr = hashTable[index];
        while(ptr->next != nullptr) {
            count++;
            ptr = ptr->next;
        }
    }
    return count;
}

void HashTable::printTable() {
    int number;
    for (int i = 0; i < m_tableSize; ++i) {
        number = numberOfItemsInIndex(i);
        std::cout << "index: " << i << std::endl;
        std::cout << "name: " << hashTable[i]->name << std::endl;
        std::cout << "drink: " << hashTable[i]->drink << std::endl;
        std::cout << "items in bucket: " << number << std::endl;
        std::cout << "----------------------"<< std::endl;
    }
}

void HashTable::printItemsInIndex(int index) {
    int numberOfitems = numberOfItemsInIndex(index);
    if (!numberOfitems) {
        std::cout << "Ce bucket est vide" << std::endl;
    }
    else {

        std::cout << "Nombre d'items: " << numberOfitems << std::endl;
        std::cout << "-----------------------------" << std::endl;
        item* ptr = hashTable[index];
        do {
            std::cout << "nom: " << ptr->name << std::endl;
            std::cout << "drink: " << ptr->drink << std::endl;
            std::cout << "-----------------------------" << std::endl;
            ptr = ptr->next;
        } while (ptr != nullptr);
    }
}

void HashTable::printTypedeHachage(int num) {
    std::string msg = "type de hachage: ";
    switch (num) {
        case 1:
            std::cout << msg << "Trivial (pas bon)"<< std::endl;
            break;
        case 2:
            std::cout <<  msg << "Polynomial"<< std::endl;
            break;
        default: std::cout << "Pas de type"<< std::endl;
    }
}

void HashTable::addItem(std::string name, std::string drink) {
    int index = hash(name, m_typedeHachage);
    if (hashTable[index]->name == "empty") {
        hashTable[index]->name = name;
        hashTable[index]->drink = drink;
    }
    else {
        item* ptr = hashTable[index];
        item* newItem = new item;
        newItem->name = name;
        newItem->drink = drink;
        newItem->next = nullptr;

        while(ptr->next != nullptr) {
            ptr = ptr->next;
        }
        ptr->next = newItem;
    }
}

void HashTable::findDrink(std::string name) {
    int hashIndex = hash(name, m_typedeHachage);
    std::string drink = "";
    item* ptr = hashTable[hashIndex];
    while(ptr != nullptr) {
        if (ptr->name == name) {
            drink = ptr->drink;
            break;
        }
        ptr = ptr->next;
    }
    if (drink.empty()) {
        std::cout << "There's no " << "«"<< name << "»"<< std::endl;
    }
    else std::cout << drink << std::endl;
}

bool HashTable::findItem(std::string name) {
    int hashIndex = hash(name, m_typedeHachage);
    bool estDansTable = false;
    item* ptr = hashTable[hashIndex];
    while(ptr != nullptr) {
        if (ptr->name == name) {
            estDansTable = true;
            return estDansTable;
        }
        ptr = ptr->next;
    }
    return estDansTable;
}

void HashTable::removeItem(std::string name) {
    int index = hash(name, m_typedeHachage);
    item* delPtr;

    if (hashTable[index]->name == "empty" && hashTable[index]->drink == "empty") {
        std::cout << name << " was not found in the bucket is empty" << std::endl;
    }

    else if (hashTable[index]->name == name && hashTable[index]->next == nullptr) {
        hashTable[index]->name = "empty";
        hashTable[index]->drink = "empty";
        std::cout << name << "'s item has been removed" << std::endl;
    }

    else if (hashTable[index]->name == name) {
        delPtr = hashTable[index];
        hashTable[index] = hashTable[index]->next;
        delete delPtr;
        std::cout << name << "'s item has been removed" << std::endl;
    }

    else {
        item* ptr1 = hashTable[index]->next;
        item* ptrBefore = hashTable[index];

        while(ptr1 != nullptr && ptr1->name != name) {
            ptrBefore = ptr1;
            ptr1 = ptr1->next;
        }
        if (ptr1 == nullptr) {
            std::cout << name << " was not found in the bucket is empty" << std::endl;
        }
        else {
            delPtr = ptr1;
            ptrBefore->next = ptr1->next;
            delete delPtr;
            std::cout << name << "'s item has been removed" << std::endl;
        }
    }
}
