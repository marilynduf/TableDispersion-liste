/**
 * \brief Implementation Classe Personne
 */

#include "Personne.h"
/**
 * \brief Constructeur par defaut
 */
Personne::Personne() {
    m_name = "empty";
    m_drink = "empty";
}
/**
 * \brief Constructeur
 * \param[in] string name
 * \param[in] string drink
 */
Personne::Personne(const string& name, const string& drink) : m_name(name), m_drink(drink) {}
/**
 * \fn void Personne::setName(const string& name)
 * \brief set le nom d'une peronne
 * \param[in] string name
 */
void Personne::setName(const string& name) {
    m_name = name;
}
/**
 * \fn void Personne::setName(const string& name)
 * \brief retourne le nom d'une peronne
 * \param[in] string name
 */
string Personne::getName() {
    return m_name;
}