#include "Verificateur.h"
//#include <sstream>

using namespace std;

//------UTILS-------

string charToStr(char* c) {
	string r(c);
	return r;
}

/*
string charToStr(char c[]) {
	string r(c);
	return r;
}

string charToStr(unsigned char* c) {
	string r(reinterpret_cast<char*>(c));
	return r;
}

string charToStr(unsigned char c[]) {
	string r(reinterpret_cast<char*>(c));
	return r;
}

*/

//------TRANSACTION-------
bool checkTXITypes(TXI* txi) {
	//TODO Check usefull & Add missing verification
	return strcmp(typeid(txi->nBloc).name(), "unsigned int") &&
		strcmp(typeid(txi->nTx).name(), "unsigned int") &&
		strcmp(typeid(txi->nUtxo).name(), "unsigned int") &&
		strcmp(typeid(txi->signature).name(), "unsigned char") &&
		sizeof(txi->signature) == HASH_SIZE ;
}

bool checkTXI(TXI *txi){
	bool validTXI = ((sizeof(txi) / sizeof(*txi)) <= 4); // verify that there is exactly 4 TXI ==> not empty input

	if (!validTXI){ 
		throw string(MALFORMED);
		return false;
	}

	int i = 0;
	bool validTXITypes = true;
	while (validTXITypes && i < 4) {
		validTXITypes = checkTXITypes(&txi[i]);
		i++;
	}
	if (!validTXITypes){
	 throw string(MALFORMED);
	 return false;
	}
	
	return true;
}

bool checkUTXOTypes(UTXO* utxo) {
	//TODO Check usefull & Add missing verification
	return strcmp(typeid(utxo->montant).name(), "float") &&
		strcmp(typeid(utxo->dest).name(), "unsigned char") &&
		strcmp(typeid(utxo->hash).name(), "unsigned char");
}

bool checkUTXO(UTXO* utxo){
	bool validUTXO = ((sizeof(utxo) / sizeof(*utxo)) == 2); // verify that there is exactly 2 UTXO ==> not empty input

	if (!validUTXO){ 
		throw string(MALFORMED);
		return false;
	}

	int i = 0;
	bool validUTXOTypes = true;
	while (validUTXOTypes && i < 2) {
		validUTXOTypes = checkUTXOTypes(&utxo[i]);
		i++;
	}

	if (!validUTXOTypes){
	 throw string(MALFORMED);
	 return false;
	}
	
	return true;
}


bool checkSignature(TX *tx){
	//TODO Add missing verification

	bool validSignature = true;
	bool validHash = true;
	char* transaction[2];

	for (int i = 0; i < 4; i++) {
		string pubKey = "test"; //TODO where is the public key ?
		validSignature = verify(TXIToString(tx->txi[i]), charToStr(tx->txi[i].signature), pubKey);
		if (validSignature) {
			strcat(strcat(transaction[tx->txi[i].nUtxo]," "), TXIToString(tx->txi[i]));
		}
		else {
			throw string(INVALID);
			return false;
		}
	}

	for (int j = 0; j < 2; j++) {
		strcat(strcat(transaction[j], " "), UTXOToString(tx->utxo[j]));
		string UTXOhash = ::hash(transaction[j]);
		validHash = checkHash(UTXOhash, charToStr(tx->utxo[j].hash));
		if (!validHash) {
			throw string(INVALID);
			return false;
		}
	}
	return true;
}


bool checkTX(TX* tx){
	return checkTXI(tx->txi) && checkUTXO(tx->utxo);
}

bool checkTransaction(TX* tx){
	//TODO Add missing verification
	return checkSignature(tx) && checkTX(tx);
}

//------BLOC-------
bool checkNonce(unsigned int nonce)
{
	string str = charToStr(nonce);
	if (str.size(str) == 4) return true;
	else 
		printf( "Nonce is not of 4 bytes!" );
	return false;
}
bool checkNum(int num) 
{
	if (((bloc->previous bloc)->num) < num )
	return true;
	else 
		printf("This num is smaller than the num of previous bloc! \n" );
	return false;
}
bool verifyHash(char* hash)
{
	string str = charToStr(*hash);
	if (str.size() == 64) return true;
	else
		printf("%s:  This hash is not of 64 bytes! \n", hash );
	return false;
}

bool checkBlocTypes(Bloc* bloc) {
	return strcmp(typeid(bloc->nonce).name(), "unsigned int") &&
		strcmp(typeid(bloc->num).name(), "int") &&
		verifyHash(bloc->hash) &&
		verifyHash(bloc->previous_hash)&& 
		checkNum (bloc->num)&&
		checkNonce (bloc->nonce);
}


bool checkBloc(Bloc* bloc) {
	//TODO Add missing verification
	return checkBlocTypes(bloc) &&
		checkNonce(bloc->nonce) &&
		checkNum(bloc->num);
}




//bool verifyHash(char* hash) {
//	string str = charToStr(hash);
//	return str.size() == 64;
//}




