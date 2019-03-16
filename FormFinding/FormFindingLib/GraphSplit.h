#pragma once
#include "stdafx.h"

class GraphSplit
{
public:
	Model* model;

	std::vector<Node*> nodeList;
	std::map<Node*, long> nodeColorMap;

	Node* stack[10000];
	long iStack;

	void pushNode(Node* b);
	Node* popNode();

	void initWithModel(Model *m);
	void clearRigidGroups();
	void computeRigidGroups();

	// cicla su tutto il model, trova le beams che sono rigid, e setta a TRUE l'attributo rigid_link
	void initColors();

	void goBFS(Node *n);

	GraphSplit(void);
	~GraphSplit(void);
};

