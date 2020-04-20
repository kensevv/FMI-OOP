#include "Vector.h"

void Vector::resize()
{
	this->capacity = capacity * 2;
	int* newBuffer = new int[capacity];
	for (int i = 0; i < size; i++)
	{
		newBuffer[i] = this->data[i];
	}
	delete[] this->data;
	this->data = newBuffer;
}

void Vector::copy(const Vector& other)
{
	this->size = other.size;
	this->capacity = other.capacity;
	this->data = new int[capacity];
	for (int i = 0; i < this->size; i++)
	{
		this->data[i] = other.data[i];
	}
}

void Vector::erase()
{
	delete[] this->data;
}

Vector::Vector()
{
	this->size = 0;
	this->capacity = 8;
	this->data = new int[capacity];
}

Vector::Vector(const Vector& other)
{
	copy(other);
}

Vector::~Vector()
{
	erase();
}

Vector::Vector(size_t initialSize)
{
	this->size = initialSize;
	this->capacity = initialSize;
	this->data = new int[capacity];
}

void Vector::print()
{
	for (int i = 0; i < this->size; i++)
	{
		std::cout << this->data[i] << " ";
	}
}

Vector& Vector::push_front(int New)
{
	if (this->size == this->capacity - 1) resize();

	int* newBuffer = new int[this->size+1];
	for (int i = 0; i < this->size; i++)
	{
		newBuffer[i+1] = this->data[i];
	}
	newBuffer[0] = New;
	delete[] this->data;
	this->data = newBuffer;
	this->size++;

	return *this;
}

Vector& Vector::push_back(int New)
{
	if (this->size == this->capacity - 1) resize();

	int* newBuffer = new int[this->size + 1];
	for (int i = 0; i < this->size; i++)
	{
		newBuffer[i] = this->data[i];
	}
	newBuffer[size] = New;
	delete[] this->data;
	this->data = newBuffer;
	this->size++;

	return *this;
}

size_t Vector::getSize() const
{
	return this->size;
}

void Vector::removeAtIndex(int index)
{

	for (int i = index; i < this->size - 1; i++)
	{
		this->data[i] = this->data[i + 1];
	}
	this->size--;
}

void Vector::removeElement(int element)
{
	int index;
	for (int i = 0; i < this->size; i++)
	{
		if (this->data[i] == element) index = i;
	}
	removeAtIndex(index);
}

void Vector::insertAtPos(int index, int element)
{
	if (this->size == this->capacity) resize();

	int* newBuffer = new int[size + 1];

	for (int i = 0; i < index-1; i++)
	{
		newBuffer[i] = this->data[i];
	}
	newBuffer[index-1] = element;
	for (int i = index; i < this->size+1; i++)
	{
		newBuffer[i] = this->data[i-1];
	}
	this->size++;
	delete[]this->data;
	this->data = newBuffer;
}

bool Vector::contains(int element)const
{
	for (int i = 0; i < this->size; i++)
	{
		if (this->data[i] == element) return true;
	}

	return false;
}

Vector& Vector::operator=(const Vector& other)
{
	if (this != &other)
	{
		erase();
		copy(other);
	}
	return *this;
}

Vector Vector::operator+(const Vector& other) const
{
	Vector result(*this);
	for (int i = 0; i < other.size; i++)
	{
		result.push_back(other.data[i]);
	}
	return result;
}

Vector Vector::operator+(const int element) const
{
	Vector result(*this);
	result.push_back(element);
	return result;
}

Vector& Vector::operator+=(int element)
{
	// vector = vector + element
	this->push_back(element);
	return *this;
}

Vector& Vector::operator+=(const Vector& other)
{
	// vector = vector + otherVector;
	*this = *this + other;
	return *this;
}

int& Vector::operator[](int index) const
{
	return this->data[index];
}

bool Vector::operator==(const Vector& other)const
{
	if (this->size == other.size)
	{
		for (int i = 0; i < this->size; i++)
		{
			if (!contains(other.data[i])) return false;
		}
		for (int i = 0; i < this->size; i++)
		{
			if (!other.contains(this->data[i])) return false;
		}
		return true;
	}
	return false;
}

bool Vector::operator!=(const Vector& other)const
{
	return !(*this == other);
}

std::ostream& operator<<(std::ostream& out, const Vector& vector)
{
	out << "[ ";
	for (int i = 0; i < vector.getSize(); i++)
	{
		out << vector[i] << " ";
	}
	out << "] ";

	return out;
}
