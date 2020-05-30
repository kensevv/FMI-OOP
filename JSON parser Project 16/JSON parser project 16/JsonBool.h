#pragma once
#include "Json.h"

class JsonBool : public Json
{
private:
	bool value;
	void copy(const JsonBool& other);

public:
	JsonBool();
	JsonBool(const std::string& _jsontxt, const std::map<std::string, Json*> _elements, bool _value);
	JsonBool(bool _value);
	JsonBool(const JsonBool& other);
	JsonBool& operator=(const JsonBool& other);
	bool getValue()const;
	void setValue(bool value);

	void print() override;
};