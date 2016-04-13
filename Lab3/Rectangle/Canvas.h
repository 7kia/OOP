#pragma once
/*
Класс, моделирующий сущность Canvas (полотно, холст для рисования, картинка, канва),
хранящую прямоугольный массив пикселей. Для каждого пикселя изображения можно задать
свой код символа, что позволяет выводить простейшие картинки в текстовом режиме,
вроде таких:
+----+
/    /|
+----+ |
|    | +
|    |/
+----+
*/
#include <vector>
#include <iterator>
#include <ctype.h>

#include "Rectangle.h"

class CCanvas
{
public:
	// Создает канву для рисования размером width*height
	// После своего создания содержимое канвы заполнено пробельными символами
	// Допускается создание канвы нулевых размеров
	CCanvas(size_t width, size_t height);
	~CCanvas();

	// Возвращает ширину канвы
	size_t GetWidth()const;

	// Возвращает высоту канвы
	size_t GetHeight()const;

	// Очищает канву (заполняет содержимое символами с указанным кодом)
	// Если код символа находится в диапазоне от 0 до ' ', команда игнорируется
	void Clear(char code = ' ');

	// Задает код символа code для пикселя в координатах (x, y)
	// Координаты верхнего левого угла канвы принимаются равными 0, 0.
	// Если координаты выходят за пределы канвы, либо код символа 
	// находится в диапазоне от 0 до (' ' - 1), содержимое канвы не должно меняться
	void SetPixel(int x, int y, char code);

	// Возвращает код символа пикселя в координатах (x, y)
	// Координаты верхнего левого угла канвы принимаются равными 0, 0.
	// Если координаты пикселя выходят за пределы канвы, должен возвращаться
	// код символа "пробел"
	char GetPixel(int x, int y) const;

	// Выводит содержимое в поток вывода, производный от std::ostream 
	// (например, std::cout, экземпляр ofstream, или ostringstream)
	// В конце каждой строки должен выводиться символ \n
	void Write(std::ostream & ostream) const;

	void FillRectangle(CRectangle & rect, char code, CCanvas & canvas);

private:
	const std::string MESSAGE_INCORRECT_ARGUMENT = "Incorrect arguments! Argument must be more zero.";

	bool CheckCorrectnessChar(char code);
private:
	size_t m_width;
	size_t m_height;
	std::vector<std::string> m_matrix;
	// Закрытые данные и методы класса
};