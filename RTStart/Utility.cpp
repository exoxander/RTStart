#include "Utility.h"

//---------------< fVector >-----------------
float fVector::returnDistance() {//fix this later
	float x2 = x * x;
	float y2 = y * y;
	return sqrt(x2 + y2);
}
void fVector::normalize() {
	float temp = returnDistance();
	x /= temp;
	y /= temp;
	z /= temp;
}

fVector fVector::returnNormal() {
	fVector temp = fVector(x, y, z);
	temp.normalize();
	return temp;
}

//---------------------< doubly linked List >--------------------------
template <typename T> void List<T>::add(shared_ptr<bin<T>> _bin) {
	_bin->ID = count;
	count++;

	//if first item in List
	if (!head) {
		head = _bin;
		tail = head;
	}
	else {//if 1 + Nth item
		if (tail) {
			tail->next = _bin;
			_bin->prev = tail;
			tail = _bin;
		}
		else {
			//throw some error
			bool doNothing = true;
		}
	}
}

template <typename T> void List<T>::add(T _item) {
	add(make_shared<bin<T>>(bin<T>(_item)));
}

template<typename T> void List<T>::remove(shared_ptr<bin<T>> _bin, bool del){
	//if only
	if (tail == _bin && head == _bin) {
		head = nullptr;
		tail = nullptr;
	}
	//if head
	else if (head == _bin) {
		_bin->next->prev = nullptr;
		head = _bin->next;
	}
	//if tail
	else if (tail == _bin) {
		tail->prev->next = nullptr;
		tail = _bin->prev;
	}
	//if middle
	else {
		_bin->prev->next = _bin->next;
		_bin->next->prev = _bin->prev;
	}
	if (del) {
		delete& _bin;
	}
}

template<typename T> shared_ptr<bin<T>> List<T>::findByBinID(int _id)
{
	shared_ptr<bin<T>> currentBin = head;
	while (currentBin) {
		if (currentBin->ID == _id) {
			return currentBin;
		}
		else {
			currentBin = currentBin->next;
		}
	}

	//if not found
	return nullptr;
}

template<typename T> shared_ptr<bin<T>> List<T>::findByItem(T _item)
{
	shared_ptr<bin<T>> currentBin = head;
	while (currentBin) {
		if (currentBin->item == _item) {
			return currentBin;
		}
		else {
			currentBin = currentBin->next;
		}
	}

	//if not found
	return nullptr;
}
