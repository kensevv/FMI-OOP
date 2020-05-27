#pragma once
#include "String.h"
#include <iostream>
#include <map>
#include <any>
#include <typeinfo>


class Json
{
protected:
	String jsontxt;
	std::map<std::string, Json*> elements;

	void copy(const Json& other);
public:
	Json();
	Json(const String& _jsontxt, const std::map<std::string, Json*> _elements);
	Json(String& newjsontxt);
	Json(const Json& other);
	Json& operator=(const Json& other);

	virtual void print();

	void reset();

	const String& getJsontxt()const;
	const std::map<std::string, Json*>& getElements() const;

	void loadNparse(const String & txt);

	void parse();
};