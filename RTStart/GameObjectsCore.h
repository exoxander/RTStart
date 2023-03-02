#pragma once
#include "Utility.h"

//custom Lists for iterating and finding
class GameObjectList :List<GameObject> {
public:
	bool has(unsigned long _ID);
	shared_ptr<GameObject> get(unsigned long _ID);
	void destroy(unsigned long _ID);
};

class ModuleList :List<Module> {
	bool has(ModuleType type);
	shared_ptr<Module> get(ModuleType _type);
	void destroy(ModuleType _type);
};

//-----------------< Game Object Hash Table >-----------------------
class GameObjectHashTable {
private:
	//Prime number used for array size, hash function is just ID mod p
	const int p = 4093;

	//table is an array of lists, on hash collision, push to back
	GameObjectList* table = new GameObjectList[p];

public:
	//add a given object to the table
	void add(GameObject _object);
	//remove the object from the table 
	void destroy(GameObject _object);
	shared_ptr<GameObject> get(unsigned long _ID);
};

/*
-----------------------< Module >----------------------------
moduels provide various modular pieces for a gameobject
*/
enum class ModuleType {
	none,
	physics,
	mesh,
	sprite,
	ui,
	simpleCollider
};

class Module {
public:
	unsigned long parent;
	ModuleType type;

	Module() { parent = 0; type = ModuleType::none; };
	Module(unsigned long _parent, ModuleType _type) { parent = _parent; type = _type; };
};

//------------------< Game Object >--------------------------
class GameObject {
private:
	//must be unique, ID of 0 means error
	//readonly after creation
	//max value ~4.2 billion
	unsigned long ID;
	//max value ~18 quintillion?
	//__int64 ID;
public:
	//any old string, probably used for debug info
	std::string name;

	//a list of all modules assigned to this object
	ModuleList modules;
	unsigned long getID() { return ID; };

	//default constructor
	GameObject() { ID = 0; name = "Default_Object"; };

	//genereic constructor
	GameObject(int _ID, std::string _name = "Unnamed_Object") { ID = _ID; name = _name; };
};