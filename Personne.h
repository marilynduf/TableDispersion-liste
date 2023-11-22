/**
 * \brief Classe Personne
 */

#ifndef CODE_HASHTABLE_PERSONNE_H
#define CODE_HASHTABLE_PERSONNE_H
#include <string>
using namespace std;

class Personne {
public:
    /* constructeurs ************************************/
    Personne();
    explicit Personne(const string& name, const string& drink);
    /* setters *****************************************/
    void setName(const string& name);
    /* getters *****************************************/
    string getName();

private:
    string m_name;
    string m_drink;
};


#endif //CODE_HASHTABLE_PERSONNE_H
