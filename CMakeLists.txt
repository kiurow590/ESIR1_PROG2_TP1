cmake_minimum_required(VERSION 3.14)
project(ESIR1_PROG2_TP1)

set(CMAKE_CXX_STANDARD 20)

# Étape 1 : Inclure FetchContent
include(FetchContent)

# Étape 2 : Télécharger et rendre disponible GTest
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
        DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

# Optionnel : désactiver les tests internes de GTest
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

# Étape 3 : Ajouter les exécutables
add_executable(ESIR1_PROG2_TP1 main.cpp memory.cxx vecteur.cpp vecteur.h)

add_executable(ESIR1_PROG2_TP1_TEST
        memory.cxx vecteur.cpp vecteur.h
        tests/test_common.cc tests/test_common.h
        tests/test_vecteur_p1.cc tests/test_vecteur_p2.cc tests/test_main.cc
)

# Étape 4 : Lier GoogleTest à ton exécutable de tests
target_link_libraries(ESIR1_PROG2_TP1_TEST gtest gtest_main)
