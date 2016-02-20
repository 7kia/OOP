// Lab1-2.cpp: определяет точку входа для консольного приложения.
//

/*
Лабораторная работа 1. 2 задание 7 вариант

Разработайте программу radix.exe, выполняющую перевод чисел из
одной произвольной системы счисления в другую произвольную и 
запись результата в стандартный поток вывода. Под произвольной
системой счисления понимается система с основанием от 2 до 36. 
Системы счисления с 11-ричной до 36-ричной должны использовать
заглавные буквы латинского алфавита от A до Z для представления
разрядов с 1110до 3510. Форматкоманднойстрокиприложения:

radix.exe <source notation><destination notation><value>

Например, следующим способом программа должна осуществлять
перевод шестнадцатеричного числа 1F в его десятичное представление:
radix.exe 16 10 1F

В конце строки, выводимой в стандартный поток выводадолжен 
располагаться код \n.

Программа должна быть способна осуществлять перевод как
положительных, так и отрицательных чисел, а также нуля. Особое 
внимание уделите переводу максимальных и минимальных целых 
чисел на данной платформе (они должны преобразовываться 
корректно).
*/
#include "stdafx.h"
#include "CApplication.h"

using namespace std;

int main(int argc , char *argv[])
{
	try
	{
		CheckParametrs(argc, argv);
		CheckNotations(argv[1], argv[2]);

		int numberInputNotation = atoi(argv[1]);
		int numberOutputNotation = atoi(argv[2]);
		string inputNumber = argv[3];

		bool isSigned = isNegative(inputNumber);
		RemoveMathematicSymbol(inputNumber);
		CheckValue(inputNumber, numberInputNotation);


		int valueInputNumber = TranslateStringToNumber(inputNumber, numberInputNotation);
		std::string outputNumber = TranslateIntToString(valueInputNumber, numberOutputNotation);

		std::cout << MESSAGE_RESULT << outputNumber << std::endl;
		std::cout << MESSAGE_DECIMAL_NOTATION << valueInputNumber << std::endl;
	}
	catch (invalid_argument const& err)
	{
		cout << err.what() << endl;
		return 1;
	}
	catch (underflow_error const& err)
	{
		cout << err.what() << endl;
		return 1;
	}
	catch (overflow_error const& err)
	{
		cout << err.what() << endl;
		return 1;
	}

	return 0;
}