/** \brief Ce fichier doit contenir la déclaration de la classe vecteur
    Attention, elle ne doit contenir aucune implémentation de méthode / fonction
*/

#ifndef VECTEUR_H
#define VECTEUR_H

#include <cstddef>
#include <iosfwd>
#include <iostream>

// Déclaration de la classe vecteur
class Vecteur {
private :
    // attributs
    float *m_tableau; // tableau de flottants
    int m_taille; // dimensions du vecteur

public :
    /*
     * \brief Destructeur
     */
    ~Vecteur();

    /**
     * \brief Constructeur par dimensions et valeur initiale
     * \param nbDimension La dimensions du vecteur : 3 par défaut
     * \param initValue La valeur initiale des éléments du vecteur : 0 par défaut
     * \return Le vecteur initialisé
     */
    explicit Vecteur(int nbDimension = 3, float initValue = 0);

    /**
     * \brief Constructeur par copie
     * \param v Le vecteur à copier
     */
    Vecteur(const Vecteur &v);

    /**
     * \brief Accesseur en écriture
     * \param index L'index de l'élément à modifier
     * \return La valeur de l'élément
     */
    float &operator[](int index);

    /**
     * \brief Accesseur en lecture
     * @param i L'index de l'élément à accéder
     */
    const float &operator[](int i) const;

    /**
     * \brief Accesseur en lecture taille du vecteur
     * @param index L'index de l'élément à accéder
     * @return La valeur de l'élément
     */
    [[nodiscard]] float get(int index) const;

    /**
     * \brief Accesseur en écriture
     * \param index L'index de l'élément à modifier
     * \param value La nouvelle valeur de l'élément
     */
    void set(int index, float value);

    /**
     * Getter de la dimensions du vecteur
     * @return La dimensions du vecteur
     */
    [[nodiscard]] int dimensions() const;


    /**
     * \brief Opérateur d'affectation
     * \param v Le vecteur à affecter
     * \return Le vecteur affecté
     */
    Vecteur &operator=(const Vecteur &v);

    /**
     * \brief Opérateur d'addition
     * \param v Le vecteur à ajouter
     * \return Le vecteur résultat de l'addition
     */
    Vecteur operator+(const Vecteur &v) const;

private :
    // méthodes privées d'implémentation (si besoin)

};

/**
 * \brief Affiche le vecteur sur le flux de sortie
 * @param v Le vecteur à afficher
 * @param out  Le flux de sortie
 */
void afficherVecteur(const Vecteur *v, std::ostream &out = std::cout);

/**
 * \brief Lit un vecteur sur le flux d'entrée
 * @param in Le flux d'entrée
 * @return Le vecteur lu
 */
Vecteur *lireVecteur(std::istream &in = std::cin);

/**
 * \brief Additionne deux vecteurs
 * @param v1 vecteur 1
 * @param v2    vecteur 2
 * @return  Le vecteur résultat de l'addition
 */
Vecteur add(const Vecteur *v1, const Vecteur *v2);

/**
 * \brief calcule le produit scalaire de deux vecteurs
 * @param v1 vecteur 1
 * @param v2    vecteur 2
 * @return  Le produit scalaire
 */
float operator*(const Vecteur &v1, const Vecteur &v2);

/**
 * \brief Affiche le vecteur sur le flux de sortie
 * @param out Le flux de sortie
 * @param v Le vecteur à afficher
 * @return Le flux de sortie
 */
std::ostream &operator<<(std::ostream &out, const Vecteur &v);

/**
 * \brief Lit un vecteur sur le flux d'entrée
 * @param in Le flux d'entrée
 * @param v Le vecteur lu
 * @return Le flux d'entrée
 */
std::istream &operator>>(std::istream &in, Vecteur &v);


#endif
