#include "vecteur.h"

#include <map>
#include <iostream>

using namespace std;

/**
 * \brief Question 3
 */
void demanderEtAfficherVecteur() {
    Vecteur *vecteur(lireVecteur());
    afficherVecteur(vecteur);
    std::cout << "Entrez l'index de l'element a modifier : ";
    int index;
    std::cin >> index;
    std::cout << "Entrez la nouvelle valeur de l'element : ";
    float value;
    std::cin >> value;
    vecteur->set(index, value);
    afficherVecteur(vecteur);

    delete vecteur;

}

/**
 * \brief Question 4
 */
void calculerSomme2Vecteur() {

    Vecteur *vecteur1(lireVecteur());
    afficherVecteur(vecteur1);
    Vecteur *vecteur2(lireVecteur());
    afficherVecteur(vecteur2);

    Vecteur v3(add(vecteur1, vecteur2));
    afficherVecteur(&v3);
    delete vecteur1;
    delete vecteur2;
}

/**
 * \brief Question 7
 */
void affectationVecteur() {
    Vecteur vecteur1(Vecteur(3, 2));
    Vecteur v2(vecteur1);
    afficherVecteur(&v2);

}

/**
 * \brief Question 8
 */
void additionAvecOperateur() {
    Vecteur vecteur1(Vecteur(3, 2));
    Vecteur vecteur2(Vecteur(3, 4));
    Vecteur vecteur3(vecteur1 + vecteur2 + vecteur1);
    afficherVecteur(&vecteur3);

}

/**
 * \brief Question 9
 */
void produitScalaire() {
    Vecteur vecteur1(Vecteur(3, 2));
    Vecteur vecteur2(Vecteur(3, 4));
    float produit(vecteur1 * vecteur2);
    std::cout << "Le produit scalaire est : " << produit << std::endl;

}

/** \brief Programme principal */
int main() {
    cout << "question 3" << endl;
    // question 3
    demanderEtAfficherVecteur();

    cout << "question 4" << endl;
    // question 4
    calculerSomme2Vecteur();

    cout << "question 7" << endl;
    // question 7
    affectationVecteur();

    cout << "question 8" << endl;
    // question 8
    additionAvecOperateur();

    cout << "question 9" << endl;
    // question 9
    produitScalaire();

    //cout << "question 10" << endl;
    //// question 10
    Vecteur v6(Vecteur(3));
    //std::cin >> v6;
    //cout << v6;

    cout << "question 11" << endl;
    // question 11
    v6[1] = 5;
    cout << v6[1];
    return 0;
}
