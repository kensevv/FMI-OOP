#include "Json.h"
#include "JsonInt.h"
#include "JsonDouble.h"
#include "JsonBool.h"
#include "JsonArray.h"

void Json::copy(const Json& other)
{
	this->jsontxt = other.jsontxt;
	this->elements = other.elements;
}

Json::Json()
{
}

Json::Json(const String& _jsontxt, const std::map<std::string, Json*> _elements)
{
	this->jsontxt = _jsontxt;
	this->elements = _elements;
}

Json::Json(String& newjsontxt)
{
	this->jsontxt = newjsontxt;
}

Json::Json(const Json& other)
{
	copy(other);
}

Json& Json::operator=(const Json& other)
{
	if (this != &other) {
	copy(other);
	}
	return *this;
}

void Json::print()
{
	//std::cout << this->jsontxt;

	std::map<std::string, Json*>::iterator itr;
	std::cout << "\nParsed Json : \n";
	std::cout << "\tKEY\tELEMENT\n";
	for (itr = elements.begin(); itr != elements.end(); ++itr) {
		std::cout << '\t' << itr->first << '\t'; itr->second->print();
		std::cout << std::endl;
	}
	std::cout << std::endl;
}


void Json::reset()
{
	this->jsontxt = '\0';
	elements.clear();
}


const String& Json::getJsontxt() const
{
	return this->jsontxt;
}

const std::map<std::string, Json*>& Json::getElements() const
{
	return this->elements;
}

void Json::loadNparse(const String& txt)
{
	this->jsontxt = txt;
	parse();
}

void Json::parse()
{

}