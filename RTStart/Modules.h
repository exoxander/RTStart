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
	//should the effect be cleaned up after its done
	bool removeOnComplete;
	bool isActive;
	bool isComplete;

	Effect() 
		:Module(0, ModuleType::effect) {
		canReactivate = false; canMultiActivate = false; removeOnComplete = false; isActive = false; isComplete = false;
	};
	Effect(unsigned long _parent, bool _reactivate, bool _multiActivate, bool _remove) 
		:Module(_parent, ModuleType::effect) {
		canReactivate = false; canMultiActivate = false; removeOnComplete = _remove; isActive = false; isComplete = false;
	};
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
	int* effects;

	Trigger() :Module(0, ModuleType::trigger) { canRetrigger = false; canMultiTrigger = false; isTriggered = false; };
	Trigger(unsigned long _parent, bool _reTrigger, bool _multiTrigger, int* _effects = nullptr) 
		:Module(0, ModuleType::trigger) {
		canRetrigger = _reTrigger; canMultiTrigger = _multiTrigger; effects = _effects; isTriggered = false;
	};
};

//--------------< Physics Module >-----------------
class PhysicsModule :Module {
public:
	fVector position;
	fVector velocity;
	float mass;

	PhysicsModule() :Module(0, ModuleType::physics) {};
	PhysicsModule(unsigned long _parent) :Module(_parent, ModuleType::physics) {};
	PhysicsModule(unsigned long _parent, fVector _pos = fVector(), fVector _vel = fVector(), float _mass = 64)
		:Module(_parent, ModuleType::physics){position = _pos; velocity = _vel; mass = _mass;};
};

//--------------< Simple Collider >--------------
class SimpleColliderModule :Module {
public:
	fVector dimension;
	bool isCollider;//set false to use as trigger

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