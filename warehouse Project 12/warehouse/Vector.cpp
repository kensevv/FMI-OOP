#include "Vector.h"

template <class T>
void Vector<T>::resize()
{
	this->capacity = capacity * 2;
	T* newBuffer = new T[capacity];
	for (int i = 0; i < size; i++)
	{
		newBuffer[i] = this->data[i];
	}
	delete[] this->data;
	this->data = newBuffer;
}

template <class T>
void Vector<T>::copy(const Vector<T>& other)
{
	this->size = other.size;
	this->capacity = other.capacity;
	this->data = new T[capacity];
	for (int i = 0; i < this->size; i++)
	{
		this->data[i] = other.data[i];
	}
}

template <class T>
void Vector<T>::erase()
{
	delete[] this->data;
}

template <class T>
Vector<T>::Vector()
{
	this->size = 0;
	this->capacity = 8;
	this->data = new T[capacity];
}

template <class T>
Vector<T>::Vector(const Vector<T>& other)
{
	copy(other);
}

template <class T>
Vector<T>::~Vector()
{
	erase();
}

template <class T>
Vector<T>::Vector(size_t initialSize)
{
	this->size = initialSize;
	this->capacity = initialSize;
	this->data = new T[capacity];
}

template <class T>
void Vector<T>::print()
{
	for (int i = 0; i < this->size; i++)
	{
		std::cout << this->data[i] << " ";
	}
}

template <class T>
Vector<T>& Vector<T>::push_front(const T& New)
{
	if (this->size == this->capacity - 1) resize();

	T* newBuffer = new T[this->size + 1];
	for (int i = 0; i < this->size; i++)
	{
		newBuffer[i + 1] = this->data[i];
	}
	newBuffer[0] = New;
	delete[] this->data;
	this->data = newBuffer;
	this->size++;

	return *this;
}

template <class T>
Vector<T>& Vector<T>::push_back(const T& New)
{
	if (this->size == this->capacity - 1) resize();

	T* newBuffer = new T[this->size + 1];
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

template <class T>
size_t Vector<T>::getSize() const
{
	return this->size;
}

template <class T>
void Vector<T>::removeAtIndex(int index)
{

	for (int i = index; i < this->size - 1; i++)
	{
		this->data[i] = this->data[i + 1];
	}
	this->size--;
}

template <class T>
void Vector<T>::removeElement(const T& element)
{
	int index;
	for (int i = 0; i < this->size; i++)
	{
		if (this->data[i] == element) index = i;
	}
	removeAtIndex(index);
}

template <class T>
void Vector<T>::insertAtPos(int index, const T& element)
{
	if (this->size == this->capacity) resize();

	T* newBuffer = new T[size + 1];

	for (int i = 0; i < index - 1; i++)
	{
		newBuffer[i] = this->data[i];
	}
	newBuffer[index - 1] = element;
	for (int i = index; i < this->size + 1; i++)
	{
		newBuffer[i] = this->data[i - 1];
	}
	this->size++;
	delete[]this->data;
	this->data = newBuffer;
}

template <class T>
bool Vector<T>::contains(const T& element)const
{
	for (int i = 0; i < this->size; i++)
	{
		if (this->data[i] == element) return true;
	}

	return false;
}

template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
	if (this != &other)
	{
		erase();
		copy(other);
	}
	return *this;
}

template <class T>
Vector<T> Vector<T>::operator+(const Vector<T>& other) const
{
	Vector<T> result(*this);
	for (int i = 0; i < other.size; i++)
	{
		result.push_back(other.data[i]);
	}
	return result;
}

template <class T>
Vector<T> Vector<T>::operator+(const T& element) const
{
	Vector<T> result(*this);
	result.push_back(element);
	return result;
}

template <class T>
Vector<T>& Vector<T>::operator+=(const T& element)
{
	// vector = vector + element
	this->push_back(element);
	return *this;
}

template <class T>
Vector<T>& Vector<T>::operator+=(const Vector<T>& other)
{
	// vector = vector + otherVector;
	*this = *this + other;
	return *this;
}

template <class T>
T& Vector<T>::operator[](int index) const
{
	return this->data[index];
}

template <class T>
bool Vector<T>::operator==(const Vector<T>& other)const
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

template <class T>
bool Vector<T>::operator!=(const Vector<T>& other)const
{
	return !(*this == other);
}

template <class T>
std::ostream& operator << (std::ostream& stream, const Vector<T>& v)
{

	stream << "[ ";
	for (size_t i = 0; i < v.getSize(); ++i)
	{
		std::cout << v[i] << " ";
	}
	stream << "]";

	return stream;
}