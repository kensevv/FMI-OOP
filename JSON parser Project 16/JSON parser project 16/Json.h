#pragma once
#include <iostream>
#include <map>
#include <sstream>      // std::istringstream
#include <vector>

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
	void searchKey(std::string& sKey, bool & found); // this will search for matches with all keys, even nested ones in objects.
	void deleteKey(std::string& dKey, bool & deleted); // deep searches (nested objects aswell) for the key and deletes it if it matches.
	void create(std::string& newElement);

	void reset();

	const std::string& getJsontxt()const; 
	const std::map<std::string, Json*>& getElements() const;

	void loadNparse(const std::string & txt);

	void parse(std::string& jsontext, std::map<std::string, Json*>& elements);

	Json* createJson(int value);
	Json* createJson(double value);
	Json* createJson(bool value);
	Json* createJson(std::string value);
	Json* createJson(std::vector<int>& value);
	Json* createJson(std::vector<double>& value);
	Json* createJson(std::vector<std::string>& value);
};