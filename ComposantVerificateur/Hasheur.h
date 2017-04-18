#pragma once
#ifndef Hasheur_h
#define Hasheur_h

using namespace std;
#include <string>
#include "Bloc.h"

/**
* Prend en entr�e une chaine de caract�res
* Retourne le hash de la chaine de caract�res en entr�e en utilisant l'algorithme SHA-256 (256 bits en sortie)
*/
string hash(string chaine);

/**
* Prend en entr�e une chaine de caract�res et un hash (chaine de caract�res)
* V�rifie que le hash de la chaine correspond bien au hash en entr�e
*/
bool checkHash(string chaine, string hash);

/**
* Prend en entr�e un bloc
* Retourne une chaine de caract�res contenant les donn�es du bloc dans un format quelconque
*/
string blocToString(Bloc bloc);

/*
* Prend en entr�e une transaction
* Retourne une chaine de caract�res contenant les donn�es de la transaction dans un format quelconque
*/
string TXIToString(TXI transaction);
string UTXOToString(UTXO transaction);

#endif