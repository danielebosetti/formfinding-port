#pragma once

class Beam;
class Plate;
class PlateProperty;
class BeamProperty;
class LoadPattern;


typedef std::pair <long, long> longPair;
typedef std::pair < std::pair <long, long>, std::string > bmDistLoadGkey;
typedef std::pair<long, Beam*> mapElement_Beam;
typedef std::pair<long, Node*> mapElement_Node;

typedef std::pair<long, BeamProperty*> mapElement_BeamProperty;
typedef std::pair<long, Plate*> mapElement_Plate;
typedef std::pair<long, PlateProperty*> mapElement_PlateProperty;

typedef std::pair<long, LoadPattern*> mapElement_LoadPattern;

typedef std::pair<longPair, PlPressure*> mapElement_PlatePressure;


