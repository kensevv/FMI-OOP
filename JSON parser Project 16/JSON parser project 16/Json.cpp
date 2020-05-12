#include "Json.h"

void Json::copy(const Json& other)
{
	this->jsontxt = other.jsontxt;
}

Json::Json()
{
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
	copy(other);
	return *this;
}

void Json::reset()
{
	this->jsontxt = '\0';
}


const String& Json::getJsontxt() const
{
	return this->jsontxt;
}

void Json::loadNparse(const String& txt)
{
	this->jsontxt = txt;

	//parse
}

void Json::parse()
{
}
