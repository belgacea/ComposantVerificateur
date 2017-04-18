#pragma once
#ifndef Hasheur_h
#define Hasheur_h

using namespace std;
#include <string>
#include "Bloc.h"

/**
* Prend en entrée une chaine de caractères
* Retourne le hash de la chaine de caractères en entrée en utilisant l'algorithme SHA-256 (256 bits en sortie)
*/
string hash(string chaine);

/**
* Prend en entrée une chaine de caractères et un hash (chaine de caractères)
* Vérifie que le hash de la chaine correspond bien au hash en entrée
*/
bool checkHash(string chaine, string hash);

/**
* Prend en entrée un bloc
* Retourne une chaine de caractères contenant les données du bloc dans un format quelconque
*/
string blocToString(Bloc bloc);

/*
* Prend en entrée une transaction
* Retourne une chaine de caractères contenant les données de la transaction dans un format quelconque
*/
string TXIToString(TXI transaction);
string UTXOToString(UTXO transaction);

#endif