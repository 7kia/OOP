#include "stdafx.h"
#include "HTMLDecoder.h"

using namespace std;

string DoHtmlDecode(const string &inputString)
{
	std::string result = inputString;

	map<string, string> translatableStrings;
	translatableStrings.insert({ "&quot;", "\"" });
	translatableStrings.insert({ "&apos;", "‘" });
	translatableStrings.insert({ "&lt;", "<" });
	translatableStrings.insert({ "&gt;", ">" });
	translatableStrings.insert({ "&amp;", "&" });

	for (auto element : translatableStrings)
	{
		boost::replace_all(result, element.first, element.second);
	}
	return result;
}