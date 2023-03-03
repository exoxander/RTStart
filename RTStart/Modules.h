#pragma once
#include "GameObjectsCore.h"
#include "MeshCore.h"

//--------------< Physics Module >-----------------
class PhysicsModule :Module {
public:
	fVector position;
	fVector velocity;
	float mass;

	PhysicsModule() :Module(0, ModuleType::physics) {};
	PhysicsModule(unsigned long _parent) :Module(_parent, ModuleType::physics) {};
};

//--------------< Simple Collider >--------------
class SimpleColliderModule :Module {
public:
	fVector dimension;
	bool isCircle;//set false to use as rectangle
	bool isTrigger;

	SimpleColliderModule() :Module(0, ModuleType::simpleCollider) {};
	SimpleColliderModule(unsigned long _parent) :Module(_parent, ModuleType::simpleCollider) {};
};
//--------------< Mesh Module >-----------------
class MeshModule :Module {
public:
	Mesh mesh;
	bool isCollider;
	bool isTrigger;

	MeshModule() :Module(0, ModuleType::mesh) {};
	MeshModule(unsigned long _parent) :Module(_parent, ModuleType::mesh) {};
	MeshModule(unsigned long _parent, Mesh _mesh) :Module(_parent, ModuleType::mesh) { mesh = _mesh; };
};
//--------------< Sprite Module >---------------
class SpriteModule :Module {
public:
	iVector frameSize;
	iVector imageSize;
	int frames;
	float frameSpeed;
};
//--------------< UI Module >----------------