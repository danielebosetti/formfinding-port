#pragma once

#include <map>
#include <vector>
#include <iostream>
#include <fstream>

template <class T>
void writeAllMapToStream(std::map<long, T*>& m, std::ostream& ofs) {
	for (auto it = m.begin(); it != m.end(); ++it)
		//		if(it->second) std::cout << it->first << " => " << it->second->toString() ;
		if (it->second) it->second->exportToStream(ofs);
}

template <class S, class T>
void writeAllMapToStream2(std::map<S, T*>& m, std::ostream& ofs) {
	for (auto it = m.begin(); it != m.end(); ++it)
		if (it->second) it->second->exportToStream(ofs);
}

template <class T>
void writeAllVectorToStream(std::vector<T*>& v, std::ostream& os) {
	for (unsigned long i = 0; i<v.size(); i++)
		if (v[i]) v[i]->exportToStream(os);
}

template <class T>
void writeAllMapToFile(std::map<long, T*>& m, const char* fileName) {
	std::cout << "\n export " << fileName << " ";
	std::ofstream ofs;
	ofs.open(fileName, std::ofstream::out);
	writeAllMapToStream<T>(m, ofs);
	ofs.close();
}

template <class S, class T>
void writeAllMapToFile2(std::map<S, T*>& m, const char* fileName) {
	std::cout << "\n export " << fileName << " ";
	std::ofstream ofs;
	ofs.open(fileName, std::ofstream::out);
	writeAllMapToStream2<S, T>(m, ofs);
	ofs.close();
}



template <class T>
void writeAllVectorToFile(std::vector<T*>& v, const char* fileName) {
	std::cout << "\n export " << fileName << " ";
	std::ofstream ofs;
	ofs.open(fileName, std::ofstream::out);

	//	for (unsigned long i=0; i<v.size(); i++)
	////		if(it->second) std::cout << it->first << " => " << it->second->toString() ;
	//		if (v[i]) v[i]->exportToStream(ofs);
	writeAllVectorToStream<T>(v, ofs);
	ofs.close();
}

