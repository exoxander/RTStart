#pragma once
#include "Utility.h"


struct polygon {
	int a = 0;
	int b = 0;
	int c = 0;
};

class Mesh {
public:
	//each fVector represents a vertex in the meshes local space
	fVector* vertecies;
	polygon* polygons;

	//default
	Mesh() { makeRect(40, 40); }
	//specify size
	Mesh(int _v, int _p) { vertecies = new fVector[_v]; polygons = new polygon[_p]; }
	//specify full mesh
	Mesh(fVector* _vertecies, polygon* _polygons) { vertecies = _vertecies; polygons = _polygons; }

	void makeRect(float width, float height);
	void makeCircle(float diameter, int vertecies);
};