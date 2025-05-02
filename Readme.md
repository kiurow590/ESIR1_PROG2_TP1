# Projet Vecteur

## Description
Ce projet implémente une classe `Vecteur` en C++ permettant d'effectuer diverses opérations sur des vecteurs, notamment :
- L'indexation avec surcharge de l'opérateur `[]`
- L'addition de vecteurs
- Le produit scalaire
- Les opérations d'entrée/sortie

Le projet inclut également des tests unitaires pour valider les fonctionnalités de la classe `Vecteur`.

## Fonctionnalités
- **Surcharge d'opérateurs** : Supporte les opérateurs `[]`, `+`, et `*`.
- **Assertions** : Vérifie la validité des index avec des contrôles à l'exécution.
- **Tests unitaires** : Tests complets utilisant des macros comme `ASSERT` et `EXPECT`.

## Prérequis
- **Compilateur** : Un compilateur C++ supportant C++11 ou une version ultérieure.
- **Système de build** : CMake.
- **Framework de tests** : Google Test.

## Instructions de compilation
1. Clonez le dépôt :
   ```bash
   git clone https://github.com/kiurow590/ESIR1_PROG2_TP1
   cd ESIR1_PROG2_TP1
   ```

2. Créez un dossier de build et configurez le projet :
   ```bash
   mkdir build
   cd build
   cmake ..
   ```

3. Compilez le projet :
   ```bash
   make
   ```

## Exécution des tests
Pour exécuter les tests unitaires :
```bash
./tests/test_vecteur
```

## Structure des fichiers
- `src/` : Contient l'implémentation de la classe `Vecteur`.
- `tests/` : Contient les tests unitaires pour la classe `Vecteur`.
- `.gitignore` : Spécifie les fichiers et dossiers à ignorer dans le contrôle de version.

## Licence
Ce projet est sous licence MIT. Consultez le fichier `LICENSE` pour plus de détails.
