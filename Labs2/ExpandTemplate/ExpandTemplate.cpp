#include "stdafx.h"
#include "ExpandTemplate.h"

using namespace std;

string ExpandTemplateForString(string inputString, templates const &params) {

	
	for (auto element = params.crbegin(); element != params.crend(); element++)
	{
		boost::replace_all(inputString, element->first, element->second);
	}
	return inputString;
}