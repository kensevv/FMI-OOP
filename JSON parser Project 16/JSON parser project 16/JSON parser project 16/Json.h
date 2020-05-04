#pragma once
#include "String.h"

class Json
{
public:
	String jsontxt;

	Json(String& newjsontxt);

	void parse();
};

