#pragma once
/*
�����, ������������ �������� Canvas (�������, ����� ��� ���������, ��������, �����),
�������� ������������� ������ ��������. ��� ������� ������� ����������� ����� ������
���� ��� �������, ��� ��������� �������� ���������� �������� � ��������� ������,
����� �����:
+----+
/    /|
+----+ |
|    | +
|    |/
+----+
*/
#include <vector>
#include <iterator>
#include "Rectangle.h"

class CCanvas
{
public:
	// ������� ����� ��� ��������� �������� width*height
	// ����� ������ �������� ���������� ����� ��������� ����������� ���������
	// ����������� �������� ����� ������� ��������
	CCanvas(size_t width, size_t height);
	~CCanvas();

	// ���������� ������ �����
	size_t GetWidth()const;

	// ���������� ������ �����
	size_t GetHeight()const;

	// ������� ����� (��������� ���������� ��������� � ��������� �����)
	// ���� ��� ������� ��������� � ��������� �� 0 �� ' ', ������� ������������
	void Clear(char code = ' ');

	// ������ ��� ������� code ��� ������� � ����������� (x, y)
	// ���������� �������� ������ ���� ����� ����������� ������� 0, 0.
	// ���� ���������� ������� �� ������� �����, ���� ��� ������� 
	// ��������� � ��������� �� 0 �� (' ' - 1), ���������� ����� �� ������ ��������
	void SetPixel(int x, int y, char code);

	// ���������� ��� ������� ������� � ����������� (x, y)
	// ���������� �������� ������ ���� ����� ����������� ������� 0, 0.
	// ���� ���������� ������� ������� �� ������� �����, ������ ������������
	// ��� ������� "������"
	char GetPixel(int x, int y) const;

	// ������� ���������� � ����� ������, ����������� �� std::ostream 
	// (��������, std::cout, ��������� ofstream, ��� ostringstream)
	// � ����� ������ ������ ������ ���������� ������ \n
	void Write(std::ostream & ostream) const;

	void FillRectangle(CRectangle & rect, char code, CCanvas & canvas);

private:
	const std::string MESSAGE_INCORRECT_ARGUMENT = "Incorrect arguments! Argument must be more zero.";

	bool CheckCorrectnessChar(char code);
private:
	size_t m_width;
	size_t m_height;
	std::vector<std::string> m_matrix;
	// �������� ������ � ������ ������
};