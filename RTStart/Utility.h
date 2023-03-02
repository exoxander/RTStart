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
	float z;

	fVector() { x = 0; y = 0; z = 0; };
	fVector(float _x, float _y, float _z) { x = _x; y = _y; z = _z; };

	void add(fVector _input) { x += _input.x; y += _input.y; z += _input.z; };
	void add(float _x, float _y, float _z) { x += _x; y += _y; z += _z; };

	void subtract(fVector _input) { x -= _input.x; y -= _input.y; z -= _input.z; };
	void subtract(float _x, float _y, float _z) { x -= _x; y -= _y; z -= _z; };

	void multiply(fVector _input) { x *= _input.x; y *= _input.y; z *= _input.z; };
	void multiply(float _x, float _y, float _z) { x *= _x; y *= _y; z *= _z; }
	void multiply(float _input) { x *= _input; y *= _input; z *= _input; };

	void divide(fVector _input) { x /= _input.x; y /= _input.y; z /= _input.z; };
	void divide(float _x, float _y, float _z) { x /= _x; y /= _y; z /= _z; }
	void divide(float _input) { x /= _input; y /= _input; z /= _input; };

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

//---------------------< 2x List >--------------------------------
template <typename T> class List {
private:
	int count;
	shared_ptr<bin<T>> head;
	shared_ptr<bin<T>> tail;

public:
	//default constructor
	List<T>() { count = 0; head = nullptr; tail = nullptr; };

	//copy constructor, shallow
	//List<T>(const List<T> _list) { count = _list.count; head = _list.head; tail = _list.tail; };

	//deep copy of lists
	List<T> copy();

	//adds a bin<T> to the end of the List
	void add(shared_ptr<bin<T>> _bin);

	//overload, makes a bin* and calls add(shared_ptr<bin<T>>)
	void add(T _item);

	//removes a specified bin from the List
	void remove(shared_ptr<bin<T>> _bin, bool del = false);

	//find in List
	shared_ptr<bin<T>> findByBinID(int _id);
	shared_ptr<bin<T>> findByItem(T _item);

	//insert

	//swap

	//removebyid

	//remove by item

};

