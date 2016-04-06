#pragma once

#include <string>
#include <iostream>// for std::cin and std::cout
#include <fstream>
#include <memory>
#include <boost/algorithm/string.hpp>

#include "SorterShapes.h"

class CShapeReader : public CSorterShapes
{
public:
	CShapeReader(std::string nameInputFile, std::string nameOutputFile);
	~CShapeReader();

	void			Run();// TODO
public:
	typedef typename std::vector<std::string> listArguments;

	enum class IdCommand
	{
		Point = 0	,
		LineSegment	,
		Triangle	,
		Rectangle	,
		Circle
	};
	const std::vector<std::string> COMMANDS_NAME =
	{
		"Point"			,
		"Line"	,
		"Triangle"		,
		"Rectangle"		,
		"Circle"
	};
	const std::vector<int> AMOUNT_ARGUMENTS_FOR_COMMAND =
	{
		4	,
		6	,
		9	,
		7	,
		6
	};
private:
	const std::string MESSAGE_INCORRECT_COMMAND = "Incorrect command.";

	const std::string MESSAGE_FAILED_OPEN = "Failed to open ";
	const std::string MESSAGE_FAILED_OPEN_FOR_READING = " for reading!";
	const std::string MESSAGE_FAILED_OPEN_FOR_WRITING = " for writing!";
	const std::string MESSAGE_INCORRECT_AMOUNT_ARGUMENTS = "Incorrect amount arguments! Must will be ";

	std::string			m_nameInputFile;
	std::string			m_nameOutputFile;

	std::ifstream		m_inputFile;
	std::ofstream		m_outputFile;

private:
	void				OpenFiles();
	void				CheckAndOpenFileForReading(std::ifstream &file, const std::string& fileName);
	void				CheckAndOpenFileForWriting(std::ofstream &file, const std::string& fileName);

	void				ReadShapes(std::ifstream & file);
	void				CheckAmountArguments(const listArguments & arguments, IdCommand id);
	void				AddPoint(const listArguments & arguments);
	void				AddLineSegment(const listArguments & arguments);
	void				AddTriangle(const listArguments & arguments);
	void				AddRectangle(const listArguments & arguments);
	void				AddCircle(const listArguments & arguments);

	listArguments		SplitWords(std::string const & text);
	bool				IsCommand(const std::string & word);
private:
	std::vector<std::shared_ptr<IShape>> m_shapes;
};
