#pragma once
#include <iostream>
#include <map>
#include <any>
#include <typeinfo>
#include <sstream>      // std::istringstream

class Json
{
protected:
	std::string jsontxt;
	std::map<std::string, Json*> elements;

	void copy(const Json& other);
public:
	Json();
	Json(const std::string& _jsontxt, const std::map<std::string, Json*> _elements);
	Json(std::string& newjsontxt);
	Json(const Json& other);
	Json& operator=(const Json& other);

	virtual void print();

	void reset();

	const std::string& getJsontxt()const;
	const std::map<std::string, Json*>& getElements() const;

	void loadNparse(const std::string & txt);

	void parse();

	Json* createJson(int value);
	Json* createJson(double value);
	Json* createJson(bool value);
	Json* createJson(std::string value);
};