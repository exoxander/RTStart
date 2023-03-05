#pragma once
#include "GameObjectsCore.h"
#include "MeshCore.h"

//----------------< Effect Module >------------------
// this module is particularly versetile, likely to have an expansive list of child classes
class Effect :Module {
	//can effect only trigger once in the objects lifetime?
	bool canReactivate;
	//can effect activate multiple times in a single step?
	bool canMultiActivate;
	bool isActive;
};
//----------------< Trigger Module >------------------
class Trigger : Module {
public:
	//does trigger only fire once in the objects lifetime?
	bool canRetrigger;
	//can the trigger fire multiple times per step?
	bool canMultiTrigger;
	bool isTriggered;

	//each step, send all "triggered" modules to a list (hash table?) search for active triggers there.
	//store as the module IDs
	int* triggers;
	int* effects;
};

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
	bool isCollider;//set false to use as rectangle

	SimpleColliderModule() :Module(0, ModuleType::simpleCollider) {};
	SimpleColliderModule(unsigned long _parent, bool _circle = true) :Module(_parent, ModuleType::simpleCollider) {isCollider = _circle; };
};

//--------------< Mesh Module >-----------------
class MeshModule :Module {
public:
	Mesh mesh;
	bool isCollider;

	MeshModule() :Module(0, ModuleType::mesh) {};
	MeshModule(unsigned long _parent, bool _trigger = false, bool _circle = true) :Module(_parent, ModuleType::mesh) { isCollider = _circle; };
	MeshModule(unsigned long _parent, Mesh _mesh, bool _collider = true) :Module(_parent, ModuleType::mesh) { mesh = _mesh; isCollider = _collider;};
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