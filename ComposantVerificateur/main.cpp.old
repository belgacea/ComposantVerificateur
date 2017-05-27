#include "bloc.h"
#include "Verificateur.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

#define DEST1_OK "som1"
#define DEST2_OK "qlq1"
#define DEST3_KO ""
#define DEST4_KO "som1else"
static int blocNumber = 0;
static int txiNumber = 0;

float randomAmount(int max) {
	return rand() % (max)+1.0;
}

int randomTX(int max) {
	return rand() % (max)+1;
}

TX getTX(bool valid) {
	TX tx;
	TXI txi[4];
	UTXO utxo[2];
	int nTXI = randomTX(4);
	int nUTXO = randomTX(2);
	if (valid) {
		//valid tx
		for (int i = 0; i < nTXI; i++) {
			txi[i] = TXI(blocNumber, txiNumber, rand() % 1);
			txiNumber++;
			strcpy((char*)txi[i].signature, ""); //TODO signature
		}
		for (int j = 0; j < nUTXO; j++) {
			utxo[j] = UTXO(randomAmount(100), DEST2_OK);
			strcpy((char*)utxo[j].hash, ""); //TODO hash
		}
	}
	else {
		//TODO invalid tx cases
		for (int i = 0; i < nTXI; i++) {
			txi[i] = TXI(blocNumber, txiNumber, 3);
			txiNumber++;
			strcpy((char*)txi[i].signature, ""); //TODO signature
		}
		for (int j = 0; j < nUTXO; j++) {
			utxo[j] = UTXO(-1.0, DEST3_KO);
			strcpy((char*)utxo[j].hash, ""); //TODO hash
		}
	}
	return tx;
}

TXM getTXM(bool valid) {
	TXM txm;
	UTXO utxo;
	if (valid) {
		//valid txm
		utxo.montant = 1.0;
		strcpy((char*)utxo.dest, DEST1_OK);
	}
	else {
		//invalid txm cases
		utxo.montant = 0.0;
		strcpy((char*)utxo.dest, DEST4_KO);
	}
	txm.utxo[1] = utxo;
	return txm;
}

//TODO Genesis
Bloc getCoinBase(bool valid) {
	TX firstTX; // vide
	TXM firstTXM; // positif
	//TODO TXs
	Bloc coinbase = Bloc(0, &firstTX, &firstTXM);
	coinbase.num = 0;
	coinbase.nonce = 0; //TODO nonce ?
	strcpy(coinbase.hash, strToChar("")); //TODO hash
										  //TODO invalid coinbase cases with TXs
	blocNumber++;
	return coinbase;
}

Bloc getBloc(bool valid) {
	if (blocNumber = 0) {
		return getCoinBase(valid);
	}
	TX tx = getTX(valid);
	TXM txm = getTXM(valid);
	Bloc bloc = Bloc(blocNumber, &tx, &txm);
	bloc.nonce = 0; //TODO nonce ?
	strcpy(bloc.hash, strToChar("")); //TODO hash
									  //TODO previous hash
	blocNumber++;
	return bloc;
}

int testCheckBlocOK() {
	Bloc testCoinbase = getBloc(true);
	bool validCoinbase = checkBloc(&testCoinbase);
	Bloc testBloc = getBloc(true);
	bool validBloc = checkBloc(&testBloc);
	return validCoinbase && validBloc;
}

int testCheckBlocKO() {
	Bloc testCoinbase = getBloc(false);
	bool validCoinbase = checkBloc(&testCoinbase);
	Bloc testBloc = getBloc(false);
	bool validBloc = checkBloc(&testBloc);
	return validCoinbase && validBloc;
}

//TODO recursive verification ?

int main(int argc, char* argv[]) {
	if (argc < 1) {
		srand(time(NULL));
		try {
			if (strcmp(argv[0], "OK")) {
				testCheckBlocOK();
			}
			else {
				testCheckBlocKO();
			}
		}
		catch (const string & err) {
			cerr << err;
		}
	}
	return 0;
}