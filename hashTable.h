/**
 * \brief Classe hashTable
 */
#ifndef CODE_HASHTABLE_HASHTABLE_H
#define CODE_HASHTABLE_HASHTABLE_H
#include <string>
#include <vector>
using namespace std;

class HashTable {
public:
    /* constructeurs *********************************************/
    HashTable();

    /* fonctions de hachages ************************************/
    static size_t hash(const string &key, int typedeHachage);
    /* opérations principales ***************************/
    void addItem(string name, std::string drink);
    void removeItem(string name);
    bool findItem(string name);
    void findDrink(string name) const;
    /* setters *****************************************/
    void setTypeHachage(int num) { m_typedeHachage = num; }
    /* opérations secondaires **************************/
    int numberOfItemsInIndex(int index);

    /* affichage ***************************************/
    void printTable();
    void printItemsInIndex(int index);
    static void printTypedeHachage(int num);

private:
    static const int m_tableSize = 4; // Static means that it can be accessed without instantiating a class. This is good for constants.
    int m_typedeHachage = 1;
    struct item {
        string name;
        string drink;
        item* next{};
    };
    item* hashTable[m_tableSize]{}; // Contient 10 pointeurs qui pointent sur des éléments de type item (struct au dessus)

};

#include "hashTable.cpp"

#endif //CODE_HASHTABLE_HASHTABLE_H
