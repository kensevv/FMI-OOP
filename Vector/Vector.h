//Kenan Yusein, my own vector implementation.
#pragma once
#include <iostream>

template <class T>
class Vector
{
private:
	T * data;
	size_t size;
	size_t capacity;

	void resize();
	void copy(const Vector<T>& other);
	void erase();
public:
	Vector();
	Vector(const Vector<T>& other);
	~Vector();
	Vector(size_t initialSize);
	
	size_t getSize()const;

	void print();
	Vector<T>& push_front(const T& New);
	Vector<T>& push_back(const T& New);
	void removeAtIndex(int index);
	void removeElement(const T& element);
	void insertAtPos(int index, const T& element);
	bool contains(const T& element)const;

	Vector<T>& operator=(const Vector<T>& other);

	Vector<T> operator+(const Vector<T>& other)const;
	Vector<T> operator+(const T& element)const;
	Vector<T>& operator+=(const T& element);
	Vector<T>& operator+=(const Vector<T>& other);

	T& operator[](int index)const;

	bool operator==(const Vector<T>& other)const;
	bool operator!=(const Vector<T>& other)const;

	/*
	bool operator<(const Vector& other)const;
	bool operator>(const Vector& other)const;
	bool operator>=(const Vector& other)const;
	bool operator<=(const Vector& other)const;
	*/
	
};

template <class T>
std::ostream& operator << (std::ostream& stream, const Vector<T>& v);