// codice fuff.. file di appoggio x routines in via di sviluppo
//#include "stdafx.h"

#include "SharedFunctions.h"
#include "ModelItemsDeclare.h"


#pragma warning (disable:4018)

template <class T>
void printAllMap(std::map<long,T*> m){
	for (auto item : m)
		if(item->second) std::cout << item->first << " => " << item->second->toString() ;
}

template <class T>
void printAllMapPairKey(std::map<std::pair<long,long>,T*> m){
	for (auto item : m)
		if(item->second) std::cout << "<" << item->first.first << "-" << item->first.second << "> => " << item->second->toString() ;
}

void getRidOfLNK4221__exportModel() {}
