#pragma once
#include <memory>
#include <string>
#include <vector>
using std::shared_ptr;
using std::make_shared;

//--------------------< fVector >---------------------
struct fVector {
	float x;
	float y;
	fVector(float _x, float _y) { x = _x; y = _y; };
	void add(fVector _input) { x += _input.x; y += _input.y; };
	void add(float _x, float _y) { x += _x; y += _y; };
	void subtract(fVector _input) { x -= _input.x; y -= _input.y; };
	void subtract(float _x, float _y) { x -= _x; y -= _y; };
	void multiply(fVector _input) { x *= _input.x; y *= _input.y; };
	void multiply(float _input) { x *= _input; y *= _input; };
	float returnDistance();
	void normalize();
	fVector returnNormal();
};

//--------------------< iVector >---------------------
struct iVector {
	int x;
	int y;
	iVector(int _x, int _y) { x = _x; y = _y; };
	void add(iVector _input) { x += _input.x; y += _input.y; };
	void add(int _x, int _y) { x += _x; y += _y; };
	void subtract(iVector _input) { x -= _input.x; y -= _input.y; };
	void subtract(int _x, int _y) { x -= _x; y -= _y; };
};

//---------------------< bin >----------------------------
template <typename T> struct bin {
	T item;
	int ID;
	shared_ptr<bin<T>> next;
	shared_ptr<bin<T>> prev;
};

//---------------------< 2x list >--------------------------------
template <typename T> class list {
private:
	int count;
	shared_ptr<bin<T>> head;
	shared_ptr<bin<T>> tail;

public:
	//default constructor
	list<T>() { count = 0; head = nullptr; tail = nullptr; };

	//copy constructor, shallow
	list<T>(list<T> _list) { count = _list.count; head = _list.head; tail = _list.tail; };

	//deep copy of lists
	list<T> copy();

	//adds a bin<T> to the end of the list
	void add(shared_ptr<bin<T>> _bin);

	//overload, makes a bin* and calls add(shared_ptr<bin<T>>)
	void add(T _item);

	//removes a specified bin from the list
	void remove(shared_ptr<bin<T>> _bin, bool del = false);

	//find in list
	shared_ptr<bin<T>> findByID(int _id);
	shared_ptr<bin<T>> findByItem(T _item);

	//insert

	//swap

	//removebyid

	//remove by item

};

class GameObjectHashTable {
private:
	//Prime number used for array size, hash function is just mod on ID
	const int p = 4093;

	//table is an array of lists, on hash collision, push to back
	list<GameObject>* table = new list<GameObject>[p];

public:
	//add a given object to the list
	void add(GameObject _object);
	//remove the object from the list 
	void destroy(GameObject _object);
	GameObject* get(unsigned long _ID);
};

class GameObject {
private:
	//must be unique, ID of 0 means error
	//readonly after creation
	unsigned long ID;
public:
	//any old string, probably used for debug info
	std::string name;
	unsigned long getID() { return ID; };

	//default constructor
	GameObject() { ID = 0; name = "Default_Object"; };

	//genereic constructor
	GameObject(int _ID, std::string _name = "Unnamed_Object") { ID = _ID; name = _name; };

	//extend with physics info
	//extend with mesh info
	//extend with sprite info
	//extend with user interfaceable
};