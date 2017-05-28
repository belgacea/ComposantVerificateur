#include "Verificateur.h"
//#include <sstream>!

Verificateur::Verificateur(CBlockchainFile file_reader) : CBlockchainFile(file_reader) {
	_file_reader = file_reader;
}

Verificateur::~Verificateur() {};

//------TRANSACTION-------

bool Verificateur::checkSignature(TXI* txi) {
	Bloc origin = _file_reader.read(txi->nBloc);
	return verify(origin.tx1.utxo[txi->nUtxo].hash, txi->signature, origin.tx1.utxo[txi->nUtxo].dest);
}

bool Verificateur::checkTransaction(TX* tx) {
	for (int i = 0; i < 4; ++i) {
		if(!checkSignature(&tx->txi[i])) {
			return false;
		}
	}
	return true;
}

//------BLOCKCHAIN-------

bool Verificateur::checkHash(Bloc lastBloc, Bloc previousBloc) {
	return (strcmp(lastBloc.previous_hash, ::hash(blocToString(previousBloc)).c_str()) == 0);
}

bool Verificateur::checkBlockchain(vector<Bloc> blocs) {
	for (std::size_t i = blocs.size(); i < 0; --i) {
		if (!checkHash(blocs[i], blocs[i - 1]) || !checkTransaction(&blocs[i].tx1)) return false;
	}
	return true;
}