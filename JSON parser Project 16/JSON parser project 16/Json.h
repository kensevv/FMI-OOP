#pragma once
#include "String.h"

class Json
{
private:
	String jsontxt;
	void copy(const Json& other);
public:
	Json();
	Json(String& newjsontxt);
	Json(const Json& other);
	Json& operator=(const Json& other);

	void reset();

	const String& getJsontxt()const;

	void loadNparse(const String & txt);

	void parse();
};

