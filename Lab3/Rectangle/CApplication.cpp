#include "stdafx.h"
#include "CApplication.h"

using namespace std;

vector<string> SplitWords(string const& text)
{
	std::string trimmed = boost::trim_copy(text);

	vector<string> words;
	boost::split(words, trimmed, boost::is_space(), boost::token_compress_on);
	return words;
}

CApplication::CApplication(int argc , char * argv[])
{
	CheckParametrs(argc, argv);
	
	m_nameFirstCommandFile = argv[1];
	m_nameSecondCommandFile = argv[2];
	m_nameOutputFile = argv[3];	
	m_nameInserectFile = argv[4];
}

CApplication::~CApplication()
{
}

void CApplication::Run()
{
	OpenFiles();

	vector<CRectangle> rectangles = { CRectangle(), CRectangle() };
	ApplyCommandOnRectangle(rectangles[0], m_firstCommandFile);

	ApplyCommandOnRectangle(rectangles[1], m_secondCommandFile);

	rectangles.push_back(rectangles[0]);
	rectangles[2].Intersect(rectangles[1]);
	WriteResultTransformationsInFile(rectangles, m_outputFile);

	WriteResultIntersectionInFile(rectangles, m_inserectFile);

//	outputFile << secondMaxCost;
}

void CApplication::CheckParametrs(int argc , char *argv[])
{
	if (argc != AMOUNT_ARGUMENTS)
	{
		throw invalid_argument(MESSAGE_INCORRECT_AMOUNT_ARGUMENTS + to_string(AMOUNT_ARGUMENTS));
	}
}

void CApplication::OpenFiles()
{
	CheckAndOpenFileForReading(m_firstCommandFile, m_nameFirstCommandFile);
	CheckAndOpenFileForReading(m_secondCommandFile, m_nameSecondCommandFile);
	CheckAndOpenFileForWriting(m_outputFile, m_nameOutputFile);
	CheckAndOpenFileForWriting(m_inserectFile, m_nameInserectFile);

}

void CApplication::CheckAndOpenFileForReading(ifstream & file, const string& fileName)
{
	file.open(fileName);
	file.exceptions(ifstream::badbit);
	if (!file.is_open())
	{
		throw ifstream::failure(MESSAGE_FAILED_OPEN + fileName + MESSAGE_FAILED_OPEN_FOR_READING);
	}
}

void CApplication::CheckAndOpenFileForWriting(ofstream & file, const string& fileName)
{
	file.open(fileName);
	file.exceptions(ofstream::badbit);
	if (!file.is_open())
	{
		throw ofstream::failure(MESSAGE_FAILED_OPEN + fileName + MESSAGE_FAILED_OPEN_FOR_WRITING);
	}
}

void CApplication::ApplyCommandOnRectangle(CRectangle & rectangle, std::ifstream & file)
{
	string stringFromFile;
	getline(file, stringFromFile);

	listArguments argumnents = SplitWords(stringFromFile);
	if (argumnents.size() < 1)
	{
		throw invalid_argument(MESSAGE_NO_RECTANGLE_INITIALIZATION);
	}
	if (argumnents[0] != COMMANDS_NAME[IdCommand::Rectangle])
	{
		throw invalid_argument(MESSAGE_INCORRECT_COMMAND);
	}

	ProcessRectangleCommand(argumnents, rectangle);

	while (getline(file, stringFromFile))
	{
		argumnents = SplitWords(stringFromFile);
		if (argumnents[0] == COMMANDS_NAME[IdCommand::Move])
		{
			ProcessMoveCommand(argumnents, rectangle);
		}
		else if (argumnents[0] == COMMANDS_NAME[IdCommand::Scale])
		{
			ProcessScaleCommand(argumnents, rectangle);
		}
		else
		{
			throw invalid_argument(MESSAGE_INCORRECT_COMMAND);
		}
	}


}

void CApplication::ProcessRectangleCommand(const listArguments & arguments, CRectangle & rectangle)
{
	if (arguments.size() != AMOUNT_ARGUMENTS_FOR_COMMAND[static_cast<int>(IdCommand::Rectangle)])
	{
		throw invalid_argument(MESSAGE_INCORRECT_AMOUNT_ARGUMENTS
			+ to_string(AMOUNT_ARGUMENTS_FOR_COMMAND[static_cast<int>(IdCommand::Rectangle)]));
	}

	rectangle.SetLeft(stoi(arguments[1]));
	rectangle.SetTop(stoi(arguments[2]));
	rectangle.SetWidth(stoi(arguments[3]));
	rectangle.SetHeight(stoi(arguments[4]));
}

void CApplication::ProcessMoveCommand(const listArguments & arguments, CRectangle & rectangle)
{
	if (arguments.size() != AMOUNT_ARGUMENTS_FOR_COMMAND[static_cast<int>(IdCommand::Move)])
	{
		throw invalid_argument(MESSAGE_INCORRECT_AMOUNT_ARGUMENTS 
			+ to_string(AMOUNT_ARGUMENTS_FOR_COMMAND[static_cast<int>(IdCommand::Move)]));
	}

	rectangle.Move(stoi(arguments[1]), stoi(arguments[2]));
}

void CApplication::ProcessScaleCommand(const listArguments & arguments, CRectangle & rectangle)
{
	if (arguments.size() != AMOUNT_ARGUMENTS_FOR_COMMAND[static_cast<int>(IdCommand::Scale)])
	{
		throw invalid_argument(MESSAGE_INCORRECT_AMOUNT_ARGUMENTS
			+ to_string(AMOUNT_ARGUMENTS_FOR_COMMAND[static_cast<int>(IdCommand::Scale)]));
	}

	rectangle.Scale(stoi(arguments[1]), stoi(arguments[2]));
}

bool CApplication::IsCommand(const std::string & word)
{
	return find(COMMANDS_NAME.begin(), COMMANDS_NAME.end(), word) != COMMANDS_NAME.end();
}

void CApplication::WriteResultTransformationsInFile(vector<CRectangle> & rectangles, ofstream & file)
{
	
	for (size_t index = 0; index < 2; index++)
	{
		file << "Rectangle " << index + 1 << ":\n";
		file << "\t" << "Left top :" << '(' << rectangles[index].GetLeft() << ';' << rectangles[index].GetTop() << ")\n";
		file << "\t" << "Size :" << '(' << rectangles[index].GetWidth() << "*" << rectangles[index].GetHeight() << ")\n";
		file << "\t" << "Right bottom :" << '(' << rectangles[index].GetRight() << ';' << rectangles[index].GetBottom() << ")\n";
		file << "\t" << "Area :" << rectangles[index].GetArea() << "\n";
		file << "\t" << "Perimeter :" << rectangles[index].GetPerimeter() << "\n";
	};

	file << "Intersection :\n";
	file << "\t" << "Left top :" << '(' << rectangles[2].GetLeft() << ';' << rectangles[2].GetTop() << ")\n";
	file << "\t" << "Size :" << '(' << rectangles[2].GetWidth() << "*" << rectangles[2].GetHeight() << ")\n";
	file << "\t" << "Right bottom :" << '(' << rectangles[2].GetRight() << ';' << rectangles[2].GetBottom() << ")\n";
	file << "\t" << "Area :" << rectangles[2].GetArea() << "\n";
	file << "\t" << "Perimeter :" << rectangles[2].GetPerimeter() << "\n";
}

void CApplication::WriteResultIntersectionInFile(vector<CRectangle> & rectangles, ofstream & file)
{
	CCanvas canvas(30, 30);
	canvas.FillRectangle(rectangles[0], '0', canvas);
	canvas.FillRectangle(rectangles[1], '1', canvas);
	canvas.FillRectangle(rectangles[2], '2', canvas);

	canvas.Write(file);
}