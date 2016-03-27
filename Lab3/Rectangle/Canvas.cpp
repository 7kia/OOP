#include "stdafx.h"
#include "Canvas.h"

using namespace std;

CCanvas::CCanvas(size_t width, size_t height)
	:m_width(width),
	m_height(height)
{
	m_matrix = std::vector<std::string>(width);
	for (size_t i = 0; i < width; i++)
	{
		m_matrix[i].resize(height);
	}
	Clear(' ');
}

CCanvas::~CCanvas()
{
}

size_t CCanvas::GetWidth() const
{
	return m_width;
}

size_t CCanvas::GetHeight() const
{
	return m_height;
}

void CCanvas::Clear(char code)
{
	if (CheckCorrectnessChar(code))
	{
		for (auto & y : m_matrix)
		{
			for (auto & x : y)
			{
				x = code;
			}
		}
	}
}

void CCanvas::SetPixel(int x, int y, char code)
{
	if (CheckCorrectnessChar(code)
		||
		(x < 0) || (static_cast<size_t>(x) >= m_width)
		||
		(y < 0) || (static_cast<size_t>(y) >= m_height))
	{
		//throw invalid_argument(MESSAGE_INCORRECT_ARGUMENT);
		return;
	}
	m_matrix[x][y] = code;
}

char CCanvas::GetPixel(int x, int y) const
{
	if ((x < 0) || (static_cast<size_t>(x) >= m_width)
		||
		(y < 0) || (static_cast<size_t>(y) >= m_height))
	{
		return ' ';
	}
	return m_matrix[x][y];
}

void CCanvas::Write(std::ostream & ostream) const
{
	for (auto x : m_matrix)
	{
		copy(x.begin(), x.end(), std::ostream_iterator<char>(ostream, ""));
		ostream << '\n';
	}
}

bool CCanvas::CheckCorrectnessChar(char code)
{
	return (code > 0) && (code < (' ' - 1));
}

void CCanvas::FillRectangle(CRectangle & rect, char code, CCanvas & canvas)
{

	for (int x = rect.GetLeft(); x < rect.GetRight(); x++)
	{
		for (int y = rect.GetTop(); y < rect.GetBottom(); y++)
		{
			canvas.SetPixel(y, x, code);
		}
	}
}