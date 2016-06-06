#pragma once

#include "../StringList.h"
#include "../StringListIterator.h"
#include "../StringListReverseIterator.h"

#include <vector>

bool VerifyVectors(const std::vector<std::string> &first, const std::vector<std::string> &second);
std::vector<std::string> ConvertToVector(CStringList & list);

struct StringListWithSeveralElement_
{
	std::string firstElelment = "OOP";
	std::string secondElelment = "PPO";
	std::string thirdElelment = "MLaTA";
	std::string fourthElelment = "CV";
	std::string fifthElelment = "TM";

	CStringList list;
	std::list<std::string> pattern;
	size_t expectedSize = 0;
	///*
	StringListWithSeveralElement_()
	{
		list.PushToEnd(firstElelment);
		list.PushToEnd(secondElelment);
		list.PushToEnd(thirdElelment);
		list.PushToEnd(fourthElelment);
		list.PushToEnd(fifthElelment);

		expectedSize = list.GetSize();

		pattern.push_back(firstElelment);
		pattern.push_back(secondElelment);
		pattern.push_back(thirdElelment);
		pattern.push_back(fourthElelment);
		pattern.push_back(fifthElelment);

	}
	//*/
};
