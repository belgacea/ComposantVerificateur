#pragma once
#ifndef Signature_h
#define Signature_h

#include <string>

/**
* G�nere la paire de cl� (cl� priv�e, cl� publique) et renvoi faux en cas d'echec, vrai sinon
*/
bool generate(std::string** privateKey, std::string** publickey);


/**
* G�nere la signature relative � une transaction et une cl� priv� afin depouvoir authentifier la transacrtion effectu� par
* le detenteur de la cl� priv�.
* data repr�sente un array d'octets � signer et privKey la cl�e priv�e.
*/
std::string sign(std::string data, std::string privKey);


/**
* Permet de v�rifier la v�racit� de la signature.
* Grace � la cl� publique, on pourra s'assurer que la transaction effectu� est bien valide et � �t� �mise par telle
* personne.
* data repr�sente l'array d'octets associ�s � la signature et pubKey la cl�e publique du signataire.
*/
bool verify(std::string data, std::string signature, std::string pubKey);


#endif