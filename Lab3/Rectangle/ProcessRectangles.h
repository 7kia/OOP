#pragma once

#include <string>
#include <iostream>// for std::cin and std::cout
#include <fstream>
#include <vector>
#include <boost/algorithm/string.hpp>

#include "Rectangle.h"
#include "Canvas.h"

typedef typename std::vector<std::string> listArguments;

class CProcessRectangles
{
public:

private:
	const std::string MESSAGE_INCORRECT_AMOUNT_ARGUMENTS = "Incorrect amount arguments! Must will be ";

	enum IdCommand
	{
		Rectangle = 0,
		Move,
		Scale
	};
	const std::vector<std::string> COMMANDS_NAME =
	{
		"Rectangle"	,
		"Move"		,
		"Scale"
	};
	const std::vector<int> AMOUNT_ARGUMENTS_FOR_COMMAND =
	{
		5,
		3,
		3
	};
	const std::string MESSAGE_INCORRECT_COMMAND = "Incorrect command.";
	const std::string MESSAGE_NO_RECTANGLE_INITIALIZATION = "Rectangle is not initializate.";

protected:
	void ApplyCommandOnRectangle(CRectangle &rectangle, std::ifstream &file);

	void ProcessRectangleCommand(const listArguments & arguments, CRectangle & rectangle);
	void ProcessMoveCommand(const listArguments & arguments, CRectangle & rectangle);
	void ProcessScaleCommand(const listArguments & arguments, CRectangle & rectangle);
	bool IsCommand(const std::string & word);
	void WriteResultTransformationsInFile(std::vector<CRectangle> & rectangles, std::ofstream & file);
	void WriteResultIntersectionInFile(std::vector<CRectangle> & rectangles, std::ofstream & file);

};