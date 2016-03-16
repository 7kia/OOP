#include "stdafx.h"
#include "HTMLDecoder.h"

using namespace std;

string DoHtmlDecode(string inputString)
{
	vector<pair<string, string>> htmlMapping = {
		{ "&quot;", "\"" },
		{ "&apos;", "‘" },
		{ "&apos;", "‘" },
		{ "&lt;", "<" },
		{ "&gt;", ">" },
		{ "&amp;", "&" }
	};

	for (auto element : htmlMapping)
	{
		boost::replace_all(inputString, element.first, element.second);
	}
	return inputString;
}