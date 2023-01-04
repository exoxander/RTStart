#pragma once
#include <memory>
using std::shared_ptr;
using std::make_shared;
struct dVector {
	double x;
	double y;
	dVector(double _x, double _y) { x = _x; y = _y; };
	void add(dVector _input) { x += _input.x; y += _input.y; };
	void add(double _x, double _y) { x += _x; y += _y; };
	void subtract(dVector _input) { x -= _input.x; y -= _input.y; };
	void subtract(double _x, double _y) { x -= _x; y -= _y; };
	void multiply(dVector _input) { x *= _input.x; y *= _input.y; };
	void multiply(double _input) { x *= _input; y *= _input; };
	double returnDistance();
	void normalize();
	dVector returnNormal();
};

//--------------------< iVector >---------------------

//---------------------< bin >----------------------------
template <typename T> struct bin {
	T item;
	int ID;
	shared_ptr<bin<T>> next;
	shared_ptr<bin<T>> prev;
};

//---------------------< 2x list >--------------------------------
template <typename T> struct list {
	int count;
	shared_ptr<bin<T>> head;
	shared_ptr<bin<T>> tail;

	//default constructor
	list<T>() { count = 0; head = nullptr; tail = nullptr; };

	//copy constructor
	list<T>(list<T> _list) { count = _list.count; head = _list.head; tail = _list.tail; };

	//adds a bin<T> to the end of the list
	template <typename T> void add(shared_ptr<bin<T>> _bin);

	//overload, makes a bin* and calls add(shared_ptr<bin<T>>)
	template <typename T> void add(T _item);

	//removes a specified bin from the list
	template <typename T> void remove(shared_ptr<bin<T>> _bin, bool del = false);

	//find in list
	template <typename T>shared_ptr<bin<T>> findByID(int _id);
	template <typename T> shared_ptr<bin<T>> findByItem(T _item);

};