#pragma once
class Model_Reduced
{
public:
	Model_Reduced();
	~Model_Reduced();

	Model_Reduced(const Model_Reduced& model);

	std::string modelNAME;

	std::map<long, Node*> nodes;
	std::map<long, Beam*> beams;
	std::map<long, Plate*> plates;

	std::vector<Restraint*> restraints;

	std::vector<Node*> nodes_restrained;
	std::vector<Node*> nodes_free;


	//COPIA PARAMETRI MODEL
	// mettiamo qui tutte le LINES da copiare "pari-pari"
	char **linesToCopy;
	// sectionFirstLine[i] è l'indice in linesToCopy delle prima linea da copiare uguale
	long *sectionFirstLine;
	// sectionLinesCount[i] è il numero di linee che compongono la sezione i-esima
	long *sectionLinesCount;
	long sectionsCount;

	void exportSectionToStream(int i, std::ostream& ofs);

	void clearModel();

	void printModelSummary();

	void writeCommentsToFiles(std::string basePathOut);

	void initRestrainedSets();
	void linkNodesToBeams();
	void updateNodePositions();
	void initBeamLengths();
	void initAdjacentSetsForNodes();


	Node* getCorrespondingNodeInThisModel(Node* n);
};

