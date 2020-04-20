//Kenan Yusein, my own vector implementation.
#pragma once
#include <iostream>
class Vector
{
private:
	int* data;
	size_t size;
	size_t capacity;

	void resize();
	void copy(const Vector & other);
	void erase();
public:
	Vector();
	Vector(const Vector& other);
	~Vector();
	Vector(size_t initialSize);
	
	size_t getSize()const;

	void print();
	Vector& push_front(int New);
	Vector& push_back(int New);
	void removeAtIndex(int index);
	void removeElement(int element);
	void insertAtPos(int index, int element);
	bool contains(int element)const;

	Vector& operator=(const Vector& other);

	Vector operator+(const Vector& other)const;
	Vector operator+(const int element)const;
	Vector& operator+=(int element);
	Vector& operator+=(const Vector& other);

	int& operator[](int index)const;

	bool operator==(const Vector & other)const;
	bool operator!=(const Vector& other)const;

	/*
	bool operator<(const Vector& other)const;
	bool operator>(const Vector& other)const;
	bool operator>=(const Vector& other)const;
	bool operator<=(const Vector& other)const;
	*/
	
	friend std::ostream& operator<<(std::ostream& out, const Vector& vector);
	
};