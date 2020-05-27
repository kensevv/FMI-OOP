#pragma once
#include "Json.h"


class JsonInt : public Json
{
private:
	int value;
	void copy(const JsonInt& other);

public:
	JsonInt();
	JsonInt(const String& _jsontxt, const std::map<std::string, Json*> _elements, int _value);
	JsonInt(const JsonInt& other);
	JsonInt& operator=(const JsonInt& other);
	int getValue()const;
	void setValue(int value);

	void print() override;
};