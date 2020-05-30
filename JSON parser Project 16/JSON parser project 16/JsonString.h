#pragma once
#include "Json.h"

class JsonString : public Json
{
private:
	std::string value;
	void copy(const JsonString& other);

public:
	JsonString();
	JsonString(const std::string& _jsontxt, const std::map<std::string, Json*> _elements, std::string _value);
	JsonString(std::string _value);
	JsonString(const JsonString& other);
	JsonString& operator=(const JsonString& other);
	const std::string& getValue()const;
	void setValue(std::string _value);

	void print() override;
};

