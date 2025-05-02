/** \brief Ce fichier doit contenir l'ensemble des implémentations
relatives à la classe vecteur et aux fonctionnalités la concernant */

#include <assert.h>
#include <iostream>
#include "vecteur.h"

Vecteur::Vecteur(int nbDimension, float initValue) {
    assert(nbDimension > 0 && "Vecteur::Vecteur : nbDimension doit etre > 0");
    m_taille = nbDimension;
    m_tableau = new float[nbDimension];
    std::cout << "Vecteur dimensions : " << m_taille << std::endl << "Les papiers sont en regle pour initialiser le vecteur" << std::endl;
    for (int i = 0; i < nbDimension; i++) {
        m_tableau[i] = initValue;
    }
}

Vecteur::Vecteur(const Vecteur & v) {
    m_taille = v.m_taille;
    m_tableau = new float[m_taille];
    std::cout << "Vecteur dimensions : " << m_taille << std::endl << "Les papiers sont en regle pour initialiser le vecteur" << std::endl;
    for (int i = 0; i < m_taille; i++) {
        m_tableau[i] = v.m_tableau[i];
    }
}

float & Vecteur::operator[](int index) {
    assert(index < m_taille && "Vecteur::operator[] : index hors limite");
    return m_tableau[index];
}


const float &Vecteur::operator[](int i) const {
    assert(i < m_taille && "Vecteur::operator[] : index hors limite");
    return m_tableau[i];
}


float Vecteur::get(int index) const {
    assert(index < m_taille && "Vecteur::get : index hors limite");
    return m_tableau[index];
}

void Vecteur::set(int index, float value) {
    assert(index < m_taille && "Vecteur::set : index hors limite");
    m_tableau[index] = value;
}

int Vecteur::dimensions() const {
    return m_taille;
}

Vecteur::~Vecteur() {
    delete[]  m_tableau;

    std::cout << "Les papiers sont en regle pour detruire le vecteur, le notaire a signer l'acte de deces" << std::endl;

}

/**
 * @brief Affiche le vecteur
 * @param v le vecteur à afficher
 * @param out le flux de sortie
 */
void afficherVecteur(const Vecteur * v, std::ostream & out) {
    std::cout << "Vecteur : ";
    for (int i = 0; i < v->dimensions(); i++) {
        out << v->get(i) << " ";
    }
}

/**
 * @brief Lit un vecteur depuis un flux d'entrée
 * @param in le flux d'entrée
 * @return le vecteur lu
 */
Vecteur * lireVecteur(std::istream &in) {
    std::cout << "Donnez la taille du vecteur : ";
    int dims;
    in >> dims;

    auto * vec_a_remplir = new Vecteur(dims);

    for(int i = 0; i < dims; i++) {
        std::cout << "\nValeur " << i << " : ";
        float val;
        in >> val;
        vec_a_remplir->set(i, val);

        std::cout << "\n";
    }

    return vec_a_remplir;
}

/**
 * @brief Additionne deux vecteurs
 * @param v1 le premier vecteur
 * @param v2 le second vecteur
 * @return le vecteur résultat
 */
Vecteur add(const Vecteur * v1, const Vecteur * v2){

    assert((v1->dimensions() == v2->dimensions()) && "Vecteur::add : les vecteurs n'ont pas la meme dimensions");
    Vecteur v3(v1->dimensions());
    for (int i = 0; i < v1->dimensions(); i++) {
        v3.set(i, v1->get(i) + v2->get(i));
    }
    return v3;
}


Vecteur & Vecteur::operator=(const Vecteur & v) {
    if (this != &v) {
        delete[] m_tableau;
        m_taille = v.m_taille;
        m_tableau = new float[m_taille];
        for (int i = 0; i < m_taille; i++) {
            m_tableau[i] = v.m_tableau[i];
        }
    }
    return *this;
}

Vecteur Vecteur::operator+(const Vecteur &v) const {
    assert((m_taille == v.m_taille) && "Vecteur::operator+ : les vecteurs n'ont pas la meme dimensions");
    return add(this, &v);
}

/**
 * @brief Surcharge de l'opérateur *
 * @param v1  le premier vecteur
 * @param v2  le second vecteur
 * @return  le produit scalaire des deux vecteurs
 */
float operator*(const Vecteur &v1, const Vecteur &v2) {
    assert((v1.dimensions() == v2.dimensions()) && "Vecteur::operator* : les vecteurs n'ont pas la meme dimensions");
    float res = 0;
    for (int i = 0; i < v1.dimensions(); i++) {
        res += v1.get(i) * v2.get(i);
    }
    return res;
}

std::ostream & operator<<(std::ostream & out, const Vecteur & v) {
    afficherVecteur(&v, out);
    return out;
}

std::istream & operator>>(std::istream & in, Vecteur & v) {
    for (int i = 0; i < v.dimensions(); ++i) {
        float value;
        in>>value;
        v.set(i, value);
    }

    return in;
}

