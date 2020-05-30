#include "Json.h"
#include "JsonInt.h"
#include "JsonDouble.h"
#include "JsonBool.h"
#include "JsonArray.h"
#include "JsonString.h"
#include "JsonIntArray.h"
#include "JsonDoubleArray.h"
#include "JsonStringArray.h"

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
	for (size_t i = 0; i < jsontxt.length(); i++) //bug fix for nesting objects into objects with arrays in the nested object 
	{
		if (jsontxt[i] == ']') jsontxt.insert(i + 1, ",");
	}
	parse(this->jsontxt, this->elements);
}

void Json::parse(std::string& thisjsontxt, std::map<std::string, Json*>& thiselements)
{
	std::istringstream sstream(thisjsontxt);
	sstream.get(); // getting the first { 
	
	while (!sstream.eof())
	{
		std::string JsonKey;
		char symbol;
		sstream >> symbol;
		if (symbol == '}' || symbol == ']')
		{
			return;
		}
		if (symbol == '"') // Key of the object
		{
			//getting the whole key as one string

			char key[20];
			sstream.getline(key, 20, '"');
			JsonKey = key;

			char value[1000];
			sstream.get(); // getting the :

			int position = sstream.tellg(); // saving the current position
			

			char array[500];
			sstream.getline(array, 500, ']'); // will be used for string stream in case the key is an array
			
			
			sstream.seekg(position);
			sstream.getline(value, 1000, '}'); // getting the the whole remaining string in case its Value is another object.
			std::string findValtype = value;
			
			
			if (findValtype[0] != '{') // if the Value is not object, i read untill ',' for a normal value 
			{
				sstream.seekg(position); //returning to saved stream position
				sstream.getline(value, 50, ','); 
				findValtype = value;
			}
			if (findValtype[0] == '[') // if the value is an array
			{
				sstream.seekg(position);
				sstream.getline(value, 1000, ']'); // reading it again so i can have proper sstream position ( seekg bugged my program here)
				findValtype = value;
			}
			std::istringstream findType(findValtype); // findType stream will be used to find the type of the value and parse it

			//finding key type and creating Json* accordingly
			if (findValtype[0] == '{') // new object
			{
				Json* newestJson = new Json(findValtype);
				parse(findValtype, newestJson->elements);
				thiselements.insert(std::pair<std::string, Json*>(JsonKey, newestJson));
			}
			else if (findValtype[0] == '"') // string type
			{
				char thisValue[50];
				findType.get();
				findType.getline(thisValue, 50, '"');
				std::string stringValue = thisValue;

				Json* thisJson = createJson(stringValue);
				thiselements.insert(std::pair<std::string, Json*>(JsonKey, thisJson));
			}
			else if (findValtype[0] == 't' || findValtype[0] == 'f') //bool type
			{
				bool boolValue;
				if (findValtype == "true") boolValue = true;
				else boolValue = false;

				Json* thisJson = createJson(boolValue);
				thiselements.insert(std::pair<std::string, Json*>(JsonKey, thisJson));
			}
			else if (findValtype[0] >= '0' && findValtype[0] <= '9') // int / double
			{
				bool isDouble = false;
				for (int i = 0; i < findValtype.length(); i++) { if (findValtype[i] == '.')isDouble = true; }

				if (isDouble)
				{
					double doubleValue;
					findType >> doubleValue;
					Json* thisJson = createJson(doubleValue);
					thiselements.insert(std::pair<std::string, Json*>(JsonKey, thisJson));
				}
				else
				{
					int intValue;
					findType >> intValue;

					Json* thisJson = createJson(intValue);
					thiselements.insert(std::pair<std::string, Json*>(JsonKey, thisJson));
				}
			} 
			else if (findValtype[0] == '[') // array
			{
				
				findType.get(); // removing the [
				
				// first ill determine the type of the array and only one of these vectors will be filled during the while()
				std::vector<int> intarr;
				std::vector<double> doublearr;
				std::vector<std::string> stringarr;
				
				while (!findType.eof()) // find the type and parsing the elements of the array
				{
					if (findValtype[1] == '{') {
						std::cout <<std::endl<< "The program doesn't support array of objects yet. Soon!" << std::endl 
							<< "Please close and open supported JSON file" << std::endl;
						jsontxt.clear();
						elements.clear();
						return;
					}
					if (findValtype[1] == '"')
					{
						findType.get();
						char string[20];
						findType.getline(string, 20, '"');
						findType.get();
						std::string currentKey = string;

						stringarr.push_back(currentKey);
					}
					
					else if (findValtype[1] >= '0' && findValtype[1] <= '9') 
					{
						bool isDoubleArray = false;
						for (int i = 0; i < findValtype.length(); i++) { if (findValtype[i] == '.')isDoubleArray = true; }

						if (isDoubleArray)
						{
							char element[20];
							findType.getline(element, 20, ',');
							std::string stringelement = element;
							std::istringstream elemstream(stringelement);
							double currentDouble;
							elemstream >> currentDouble;

							doublearr.push_back(currentDouble);
						}
						else // is int
						{
							
							char element[20];
							findType.getline(element, 20, ',');
							std::string stringelement = element;
							std::istringstream elemstream(stringelement);
							int currentDouble;
							elemstream >> currentDouble;

							intarr.push_back(currentDouble);
						}
					}
				}

				// finding the not empty arraytype vector and inserting it to the map
				if (!intarr.empty())
				{
					Json* newJson = createJson(intarr);
					thiselements.insert(std::pair<std::string, Json*>(JsonKey, newJson));
				}
				else if (!doublearr.empty())
				{
					Json* newJson = createJson(doublearr);
					thiselements.insert(std::pair<std::string, Json*>(JsonKey, newJson));
				}
				else if (!stringarr.empty())
				{
					Json* newJson = createJson(stringarr);
					thiselements.insert(std::pair<std::string, Json*>(JsonKey, newJson));
				}
			}
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

Json* Json::createJson(std::vector<int>& value)
{
	Json* newJson = new JsonIntArray(value);
	return newJson;
}

Json* Json::createJson(std::vector<double>& value)
{
	Json* newJson = new JsonDoubleArray(value);
	return newJson;
}
Json* Json::createJson(std::vector<std::string>& value)
{
	Json* newJson = new JsonStringArray(value);
	return newJson;
}

