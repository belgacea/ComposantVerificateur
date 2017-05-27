#include "Bloc.h"

TX::TX() {}
TX::~TX() {}

TX::TX(TXI* txi, UTXO* utxo) {
	*this->txi = *txi;
	*this->utxo = *utxo;
}

TXI::TXI() {}
TXI::~TXI() {}

TXI::TXI(unsigned int nBloc, unsigned int nTx, unsigned int nUtxo) {
	this->nBloc = nBloc;
	this->nTx = nTx;
	this->nUtxo = nUtxo;
}

TXI::TXI(unsigned int nBloc, unsigned int nTx, unsigned int nUtxo, char* signature) {
	this->nBloc = nBloc;
	this->nTx = nTx;
	this->nUtxo = nUtxo;
	strcpy_s(this->signature, signature);
}

TXM::TXM() {}
TXM::~TXM() {}

TXM::TXM(UTXO* utxo) {
	*this->utxo = *utxo;
}

UTXO::UTXO() {}
UTXO::~UTXO() {}

UTXO::UTXO(float montant, char* dest) {
	this->montant = montant;
	strcpy_s(this->dest, dest);
}

UTXO::UTXO(float montant, char* dest, char* hash) {
	this->montant = montant;
	strcpy_s(this->dest, dest);
	strcpy_s(this->hash, hash);
}

Bloc::Bloc() {}
Bloc::~Bloc() {}

Bloc::Bloc(int num, TX* tx1, TXM* tx0) {
	this->num = num;
	//this->nonce = nonce;
	this->tx1 = *tx1;
	this->tx0 = *tx0;
}

Bloc::Bloc(int num, unsigned int nonce, TX* tx1, TXM* tx0) {
	this->num = num;
	this->nonce = nonce;
	this->tx1 = *tx1;
	this->tx0 = *tx0;
}

Bloc::Bloc(int num, unsigned int nonce, TX* tx1, TXM* tx0, char* previous_hash) {
	this->num = num;
	this->nonce = nonce;
	this->tx1 = *tx1;
	this->tx0 = *tx0;
	strcpy_s(this->previous_hash, previous_hash);
}

Bloc::Bloc(int num, unsigned int nonce, TX* tx1, TXM* tx0, char* previous_hash, char* hash) {
	this->num = num;
	this->nonce =  nonce;
	this->tx1 = *tx1;
	this->tx0 = *tx0;
	strcpy_s(this->previous_hash, previous_hash);
	strcpy_s(this->hash, hash);
}