#include <iostream>
#include <string>

#include "hashTable.h"
using namespace std;

int main() {

    int typeDeHachage;
    std::cout << "Entrez type de hachage: ";
    std::cin >> typeDeHachage;

    HashTable hashObj;
    hashObj.setTypeHachage(typeDeHachage);
    hashObj.printTypedeHachage(typeDeHachage);
    hashObj.addItem("Pipo", "Martini");
    hashObj.addItem("Réjean", "Thé");
    hashObj.addItem("Petrolia", "Cheval vert");
    hashObj.addItem("Bobépine", "Chocolat chaud");

    hashObj.removeItem("Bobépine");
    hashObj.findItem("Pipo");

    /** printTabble() *******************************************/
    std::cout << "HASHTABLE LIST------------------"<< std::endl;
    std::cout << "--------------------------------"<< std::endl;
    hashObj.printTable();

    std::cout << "printItemsInIndex------------------"<< std::endl;
    hashObj.printItemsInIndex(3);

    std::string name;

    while(name != "exit") {
        std::cout << "Remove : ";
        std::cin >> name;
        if (name != "exit") {
//          hashObj.findDrink(name);
            hashObj.removeItem(name);
        }
    }
    return 0;
}
