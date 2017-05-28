#pragma once
#ifndef Verificateur_h
#define Verificateur_h

#ifdef Verificateur_EXPORTS
	#define Verificateur_API __declspec(dllexport)
#else
	#define Verificateur_API __declspec(dllimport)
#endif

#include <string>
#include <vector>
#include "Hasheur.h"
#include "Signature.h"
#include "BlockchainFile.h"
#include "Bloc.h"

class Verificateur_API Verificateur {
private:
	CBlockchainFile _file_reader;
	bool checkSignature(TXI* txi);
	bool checkTransaction(TX *transaction);
	bool checkHash(Bloc lastBloc, Bloc previousBloc);
public:
	Verificateur::Verificateur(CBlockchainFile file_reader);
	Verificateur::~Verificateur();
	bool checkBlockchain(std::vector<Bloc> blocs);
};


#endif
