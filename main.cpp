#include <iostream>

#include "hashTable.h"
#include "Personne.h"

int main() {
    Personne personne1;
    Personne personne2("Petrolio", "Cappuccino");
    personne1.setName("Petra");
    personne1.setName("Petra");
    std::cout << personne1.getName() << std::endl;
    std::cout << personne2.getName() << std::endl;
    HashTable hashObj;
    int typeDeHachage;
    std::cout << "Entrez type de hachage: ";
    std::cin >> typeDeHachage;

    hashObj.setTypeHachage(typeDeHachage);
    hashObj.printTypedeHachage(typeDeHachage);
    hashObj.addItem("abc", "Pinacolada");
    hashObj.addItem("cba", "Mulet");
    hashObj.addItem("Alex", "Négroni");
    hashObj.addItem("Valérie", "Daquiri");
//    hashObj.addItem("Laurie", "Martini");
//    hashObj.addItem("Annie", "Thé");
//    hashObj.addItem("Martin", "Cheval vert");
//    hashObj.addItem("Andréanne", "Chocolat chaud");
//    hashObj.addItem("Oliver", "Mocktail");
//    hashObj.addItem("Mo", "Pas de drink pour Mo");

    /** printTabble() *******************************************/
    std::cout << "HASHTABLE LIST------------------"<< std::endl;
    std::cout << "--------------------------------"<< std::endl;
    hashObj.printTable();

//    std::cout << "printItemsInIndex------------------"<< std::endl;
//    hashObj.printItemsInIndex(3);

    std::string name;


    while(name != "exit") {
        std::cout << "Remove : ";
        std::cin >> name;
        if (name != "exit") {
//            hashObj.findDrink(name);
            hashObj.removeItem(name);
        }
    }

//    /** printTabble() *******************************************/
//    std::cout << "HASHTABLE LIST------------------"<< std::endl;
//    std::cout << "--------------------------------"<< std::endl;
//    hashObj.printTable();

    std::cout << "printItemsInIndex------------------"<< std::endl;
    hashObj.printItemsInIndex(3);


    return 0;
}
