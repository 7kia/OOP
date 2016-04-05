#include "stdafx.h"
#include "SorterShapes.h"

void CSorterShapes::PrintListShapes(std::vector<IShape*>& listShapes, std::ostringstream &strm)
{
	for (const auto& shape : listShapes)
	{
		strm << shape->GetStringPresentation();
	}
}
