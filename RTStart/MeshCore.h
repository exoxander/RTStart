#pragma once
#include "Utility.h"


struct polygon {
	int a = 0;
	int b = 0;
	int c = 0;
};

class Mesh {
private:
	void buildDefault();

public:
	//each fVector represents a vertex in the meshes local space
	fVector* vertecies;
	polygon* polygons;

	//default
	Mesh() { vertecies = new fVector[4]; polygons = new polygon[2]; buildDefault(); }
	//specify size
	Mesh(int _v, int _p) { vertecies = new fVector[_v]; polygons = new polygon[_p]; }
	//specify full mesh
	Mesh(fVector* _vertecies, polygon* _polygons) { vertecies = _vertecies; polygons = _polygons; }
};