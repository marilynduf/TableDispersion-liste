/**
 * \brief Classe hashTable
 */

#ifndef CODE_HASHTABLE_HASHTABLE_H
#define CODE_HASHTABLE_HASHTABLE_H
#include "string"

class HashTable {
public:
    /* constructeurs ************************************/
    HashTable();
    /* fonctions de hachages ****************************/
    static size_t hash(const std::string &key, int typedeHachage);
    /* opérations principales ***************************/
    void addItem(std::string name, std::string drink);
    void removeItem(std::string name);
    bool findItem(std::string name);
    /* setters *****************************************/
    void setTypeHachage(int num) { m_typedeHachage = num; }
    /* opérations secondaires **************************/
    int numberOfItemsInIndex(int index);
    void findDrink(std::string name);
    /* affichage ***************************************/
    void printTable();
    void printItemsInIndex(int index);
    static void printTypedeHachage(int num);

private:
    static const int m_tableSize = 4; // Static means that it can be accessed without instantiating a class. This is good for constants.
    int m_typedeHachage = 1;
    struct item {
        std::string name;
        std::string drink;
        item* next;
    };
    item* hashTable[m_tableSize]{}; // Contient 10 pointeurs qui pointent sur des éléments de type item (struct au dessus)
};

#endif //CODE_HASHTABLE_HASHTABLE_H
