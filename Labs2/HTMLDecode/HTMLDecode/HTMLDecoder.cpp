#include "stdafx.h"
#include "HTMLDecoder.h"

using namespace std;

string DoHtmlDecode(string inputString)
{
	map<string, string> translatableStrings;
	translatableStrings.insert({ "&quot;", "\"" });
	translatableStrings.insert({ "&apos;", "‘" });
	translatableStrings.insert({ "&lt;", "<" });
	translatableStrings.insert({ "&gt;", ">" });
	translatableStrings.insert({ "&amp;", "&" });

	for (auto element : translatableStrings)
	{
		boost::replace_all(inputString, element.first, element.second);
	}
	return inputString;
}