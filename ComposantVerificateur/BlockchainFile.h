// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the BLOCKCHAINFILE_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// BLOCKCHAINFILE_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef BLOCKCHAINFILE_EXPORTS
#define BLOCKCHAINFILE_API __declspec(dllexport)
#else
#define BLOCKCHAINFILE_API __declspec(dllimport)
#endif

#include <string>

#include "Json.h"
#include "Bloc.h"

using json = nlohmann::json;

// This class is exported from the BlockchainFile.dll
class BLOCKCHAINFILE_API CBlockchainFile {
private:
	std::string _file;
	void write(std::string str);

	json toJson(TXI txi);
	json toJson(UTXO utxo);
	json toJson(TX tx);
	json toJson(TXM txm);
	json toJson(Bloc bloc);
	json toJson(std::vector<Bloc> blocs);

	std::vector<Bloc> parse(std::string blocsJson);
	Bloc parseBloc(json j);
	TXM parseTxm(json j);
	TX parseTx(json j);
	UTXO parseUtxo(json j);
	TXI parseTxi(json j);

public:
	// Constructeur : emplacement du fichier JSON à utiliser pour stocker la Blockchain
	CBlockchainFile(std::string file);

	// Charge tous les blocs de la chaine
	std::vector<Bloc> readAll();

	// Charge un bloc de la chaine
	Bloc read(int index);

	// Trouve le bloc associé au hash passé en paramètre, throw une exception si pas de bloc
	Bloc findBloc(std::string hash);

	// Insert le bloc en s'assurant que le hash précédent est correct, throw une exception sinon
	void insert(Bloc bloc);
};