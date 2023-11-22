//
// Created by Marilyn Dufour on 2023-11-19.
//

#ifndef CODE_HASHTABLE_HASH_H
#define CODE_HASHTABLE_HASH_H
#include "string"

class Hash {
public:
    Hash();
    // différenentes fonctions de hachage possibles
    size_t hash(const std::string &key, int typedeHachage);

    // Opérations principales
    void addItem(std::string name, std::string drink);
    void removeItem(std::string name);
    bool findItem(std::string name);

    // setters
    void setTypeHachage(int num) {
        m_typedeHachage = num;
    }

    // Opérations secondaires
    int numberOfItemsInIndex(int index);
    void findDrink(std::string name);
    // Opérations d'Affichage
    void printTable();
    void printItemsInIndex(int index);
    void printTypedeHachage(int num);

private:
    static const int m_tableSize = 4; // Static means that it can be accessed without instantiating a class. This is good for constants.
    int m_typedeHachage = 1;
    struct item {
        std::string name;
        std::string drink;
        item* next;
    };
    item* hashTable[m_tableSize]; // Contient 10 pointeurs qui pointent sur des éléments de type item (struct au dessus)
};


#endif //CODE_HASHTABLE_HASH_H
