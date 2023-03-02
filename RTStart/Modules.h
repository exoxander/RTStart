#pragma once
#include "GameObjectsCore.h"


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
	bool circle;

	SimpleColliderModule() :Module(0, ModuleType::simpleCollider) {};
	SimpleColliderModule(unsigned long _parent) :Module(_parent, ModuleType::simpleCollider) {};
};
//--------------< Mesh Module >-----------------

//--------------< Sprite Module >---------------

//--------------< UI Module >----------------