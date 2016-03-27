#pragma once

#include <string>
#include <iostream>// for std::cin and std::cout
#include <fstream>
#include <vector>

#include "Rectangle.h"
#include "Canvas.h"
#include <boost/algorithm/string.hpp>

typedef typename std::vector<std::string> listArguments;

class CApplication
{
public:
	CApplication(int argc , char *argv[]);
	~CApplication();

	void Run();

private:
	const std::string MESSAGE_FAILED_OPEN = "Failed to open ";
	const std::string MESSAGE_FAILED_OPEN_FOR_READING = " for reading!";
	const std::string MESSAGE_FAILED_OPEN_FOR_WRITING = " for writing!";
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


	const int AMOUNT_ARGUMENTS = 5;

private:
	std::string m_nameFirstCommandFile;
	std::string m_nameSecondCommandFile;
	std::string m_nameOutputFile;
	std::string m_nameInserectFile;

	std::ifstream m_firstCommandFile;
	std::ifstream m_secondCommandFile;
	std::ofstream m_outputFile;
	std::ofstream m_inserectFile;
private:
	void CheckParametrs(int argc , char *argv[]);

	void OpenFiles();
	void CheckAndOpenFileForReading(std::ifstream & file, const std::string& fileName);
	void CheckAndOpenFileForWriting(std::ofstream & file, const std::string& fileName);

	void ApplyCommandOnRectangle(CRectangle &rectangle, std::ifstream &file);

	void ProcessRectangleCommand(const listArguments & arguments, CRectangle & rectangle);
	void ProcessMoveCommand(const listArguments & arguments, CRectangle & rectangle);
	void ProcessScaleCommand(const listArguments & arguments, CRectangle & rectangle);
	bool IsCommand(const std::string & word);
	void WriteResultTransformationsInFile(std::vector<CRectangle> & rectangles, std::ofstream & file);
	void WriteResultIntersectionInFile(std::vector<CRectangle> & rectangles, std::ofstream & file);
};

