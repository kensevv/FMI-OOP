#pragma once
#include "Json.h"

class JsonDouble : public Json
{
private:
	double value;
	void copy(const JsonDouble& other);

public:
	JsonDouble();
	JsonDouble(const std::string& _jsontxt, const std::map<std::string, Json*> _elements, double _value);
	JsonDouble(double _value);
	JsonDouble(const JsonDouble& other);
	JsonDouble& operator=(const JsonDouble& other);
	double getValue()const;
	void setValue(double value);

	void print() override;
};