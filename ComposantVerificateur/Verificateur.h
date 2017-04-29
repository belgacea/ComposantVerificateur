#pragma once
#ifndef Verificateur_h
#define Verificateur_h

#include <string>
#include "Hasheur.h"
#include "Signature.h"
//#include "File.h"
#include "Bloc.h"

#define INVALID "REJECT_INVALID"
#define MALFORMED "REJECT_MALFORMED"
#define OBSOLETE "REJECT_OBSOLETE"
#define DUPLICATE "REJECT_DUPLICATE"
#define NONSTANDARD "REJECT_NONSTANDARD"
#define DUST "REJECT_DUST"
#define INSUFFICIENTFEE "REJECT_INSUFFICIENTFEE"
#define CHECKPOINT "REJECT_CHECKPOINT"

	bool checkBlockchain(std::vector<Bloc> blocs);
	bool checkTransaction(TX *transaction);
	bool checkBloc(Bloc* bloc);

	//-----UTILS-------

	char* strToChar(string str);
	string charToStr(char* c);

#endif