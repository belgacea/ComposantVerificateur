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

Verificateur_API bool checkSignature(TXI* txi);
Verificateur_API bool checkTransaction(TX *transaction);
Verificateur_API bool checkHash(Bloc lastBloc, Bloc previousBloc);
Verificateur_API bool checkBlockchain(std::vector<Bloc> blocs);

#endif
