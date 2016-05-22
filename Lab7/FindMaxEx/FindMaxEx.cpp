#include "stdafx.h"
#include "FindMaxEx.h"

void ProcessVector(std::vector<double> &vector)
{
	if (vector.size())
	{
		double minValue = *std::min_element(vector.begin(), vector.end());

		auto Multiply = [minValue](double source) {
			return source * minValue;
		};

		boost::transform(vector, vector.begin(), Multiply);
		std::sort(vector.begin(), vector.end());
	}
}