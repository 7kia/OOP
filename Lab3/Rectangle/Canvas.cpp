#include "stdafx.h"
#include "Canvas.h"

using namespace std;

CCanvas::CCanvas(size_t width, size_t height)
	:m_width(width)
	,m_height(height)
{
	std::string column(height, ' ');
	m_matrix = std::vector<std::string>(width, column);
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
		for (auto & column : m_matrix)
		{
			for (auto & cell : column)
			{
				cell = code;
			}
		}
	}
}

void CCanvas::SetPixel(int x, int y, char code)
{
	// todo: invert condition.
	if (!(isprint(code)
		|| (static_cast<size_t>(x) >= m_width)
		|| (static_cast<size_t>(y) >= m_height))
		)
	{
		m_matrix[x][y] = code;
	}
}

char CCanvas::GetPixel(int x, int y) const
{
	// TODO: no need to check x<0
	if ((static_cast<size_t>(x) >= m_width)
		||
		(static_cast<size_t>(y) >= m_height))
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

// TODO: rename to CheckCharCorrectness
bool CCanvas::CheckCorrectnessChar(char code)
{
	// TODO: use std::is_print or isprint
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