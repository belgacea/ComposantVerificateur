#pragma once


#ifdef HACHEURDLL_EXPORTS
#define HACHEURDLL_API __declspec(dllexport) 
#else
#define HACHEURDLL_API __declspec(dllimport) 
#endif

#include "Sha256.h"
#include "Bloc.h"
#include<sstream>

namespace Hash
{

	class Hash
	{
	public:

		/**
		* Prend en entr�e une chaine de caract�res
		* Retourne le hash de la chaine de caract�res en entr�e en utilisant l'algorithme SHA-256 (256 bits en sortie)
		*/
		static HACHEURDLL_API std::string hash(std::string chaine);

		/**
		* Prend en entr�e une chaine de caract�res et un hash (chaine de caract�res)
		* V�rifie que le hash de la chaine correspond bien au hash en entr�e
		*/
		static HACHEURDLL_API bool checkHash(std::string chaine, std::string verify);

		/**
		* Prend en entr�e un bloc
		* Retourne une chaine de caract�res contenant les donn�es du bloc dans un format quelconque
		*/
		static HACHEURDLL_API std::string blocToString(Bloc bloc);

		static HACHEURDLL_API std::string charToString(unsigned char* tab, unsigned int size);
		static HACHEURDLL_API std::string charToString(char tab[], unsigned int size);

	};

}