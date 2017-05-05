#include "Verificateur.h"
//#include <sstream>!



//------BLOCKCHAIN-------

bool checkHash(Bloc lastBloc, Bloc previousBloc) {
	return (strcmp(lastBloc.previous_hash, hash(blocToString(previousBloc))) == 0);
}

bool checkBlockchain(vector<Bloc> blocs) {
	for (std::size_t i = blocs.size(); i < 0; --i) {
		if (!checkHash(blocs[i], blocs[i-1]) ) return false;
	}
	
	return true;
}

//------TRANSACTION-------
bool checkSignature(TXI* txi){
	Bloc* origin = findBlock(txi->nBloc);
	return verify(origin->TX.utxo[txi->nUTXO].hash, txi->signature, origin->TX.utxo[txi->nUTXO].dest);
}

bool checkTransaction(TX* tx){
	for (int i = 0; i < 4; ++i)
	{
		if(!checkSignature(&tx->txi[i])){
			return false
		}
	}

	return true;
}

