#include "Json.h"
#include "JsonInt.h"
#include "JsonDouble.h"
#include "JsonBool.h"
#include "JsonArray.h"
#include "JsonString.h"

void Json::copy(const Json& other)
{
	this->jsontxt = other.jsontxt;
	this->elements = other.elements;
}

Json::Json()
{
}

Json::Json(const std::string& _jsontxt, const std::map<std::string, Json*> _elements)
{
	this->jsontxt = _jsontxt;
	this->elements = _elements;
}

Json::Json(std::string& newjsontxt)
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
	std::map<std::string, Json*>::iterator itr;
	std::cout << "(KEY  -  ELEMENT):\n";
	for (itr = elements.begin(); itr != elements.end(); ++itr) {
		std::cout << itr->first << "  -  "; itr->second->print();
		std::cout << std::endl;
	}
}


void Json::reset()
{
	this->jsontxt = '\0';
	elements.clear();
}


const std::string& Json::getJsontxt() const
{
	return this->jsontxt;
}

const std::map<std::string, Json*>& Json::getElements() const
{
	return this->elements;
}

void Json::loadNparse(const std::string& txt)
{
	this->jsontxt = txt;
	parse();
}

void Json::parse()
{
	//std::cout << jsontxt;
	std::istringstream sstream(jsontxt);
	
	
	while (!sstream.eof())
	{
		std::string JsonKey;
		//...

		char symbol;
		sstream >> symbol;
		if (symbol == '{') // new object type
		{
			//new json* as value, recursive pasring.
		}
		else if (symbol == '"') // Key of the object
		{
			//getting the whole key as one string

			char key[20];
			sstream.getline(key, 20, '"');
			JsonKey = key;

			char value[50];
			sstream.get(); // getting the :
			sstream.getline(value, 50, ',');

			std::string findVtype = value;
			std::istringstream findType(findVtype);

			//finding key type and creating Json* accordingly
			if (findVtype[0] == '"') // string type
			{
				char thisValue[50];
				findType.get();
				findType.getline(thisValue, 50, '"');
				std::string stringValue = thisValue;

				Json* thisJson = createJson(stringValue);
				elements.insert(std::pair<std::string, Json*>(JsonKey, thisJson));
			}
			else if (findVtype[0] == 't' || findVtype[0] == 'f') //bool type
			{
				bool boolValue;
				if (findVtype == "true") boolValue = true;
				else boolValue = false;

				Json* thisJson = createJson(boolValue);
				elements.insert(std::pair<std::string, Json*>(JsonKey, thisJson));
			}
			else if (findVtype[0] >= '0' && findVtype[0] <= '9') // int / double
			{
				bool isDouble = false;
				for (int i = 0; i < findVtype.length(); i++) { if (findVtype[i] == '.')isDouble = true; }

				if (isDouble)
				{
					double doubleValue;
					findType >> doubleValue;
					Json* thisJson = createJson(doubleValue);
					elements.insert(std::pair<std::string, Json*>(JsonKey, thisJson));
				}
				else
				{
					int intValue;
					findType >> intValue;
					
					Json* thisJson = createJson(intValue);
					elements.insert(std::pair<std::string, Json*>(JsonKey, thisJson));
				}
			}
		}
		else if (symbol == '[') // array
		{
			//array
		}
	}
}

Json* Json::createJson(int value)
{
	Json* newJson = new JsonInt(value);
	return newJson;
}

Json* Json::createJson(double value)
{
	Json* newJson = new JsonDouble(value);
	return newJson;
}

Json* Json::createJson(bool value)
{
	Json* newJson = new JsonBool(value);
	return newJson;
}

Json* Json::createJson(std::string value)
{
	Json* newJson = new JsonString(value);
	return newJson;
}

