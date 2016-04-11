﻿// task1tests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../Rational.h"
#include <boost/test/output_test_stream.hpp>

using boost::test_tools::output_test_stream;

BOOST_AUTO_TEST_CASE(Test_Greates_Common_Denominator)
{
	BOOST_CHECK_EQUAL(GCD(2, 3), 1u);
	BOOST_CHECK_EQUAL(GCD(3, 2), 1u);
	BOOST_CHECK_EQUAL(GCD(12, 8), 4u);
	BOOST_CHECK_EQUAL(GCD(8, 12), 4u);
	BOOST_CHECK_EQUAL(GCD(0, 2), 2u);
	BOOST_CHECK_EQUAL(GCD(2, 0), 2u);
	BOOST_CHECK_EQUAL(GCD(0, 0), 1u);
}



/*
  Рациональное число:
	равно нулю по умолчанию (0/1)
	может быть созданно из целого в формате (n / 1)
	может быть задано с указанием числителя и знаменателя
	хранится в нормализованном виде
	*/

void VerifyRational(const CRational & r, int expectedNumerator, int expectedDenominator)
{
	BOOST_CHECK_EQUAL(r.GetNumerator(), expectedNumerator);
	BOOST_CHECK_EQUAL(r.GetDenominator(), expectedDenominator);
}

BOOST_AUTO_TEST_SUITE(Rational_number)
	BOOST_AUTO_TEST_CASE(is_0_by_default)
	{
		VerifyRational(CRational(), 0, 1);
	}
	BOOST_AUTO_TEST_CASE(can_be_constructed_from_integer)
	{
		VerifyRational(CRational(10), 10, 1);
		VerifyRational(CRational(-10), -10, 1);
		VerifyRational(CRational(0), 0, 1);
	}
	BOOST_AUTO_TEST_CASE(can_be_constructed_with_numerator_and_denominator)
	{
		VerifyRational(CRational(5, 2), 5, 2);
		VerifyRational(CRational(-5, 2), -5, 2);
		VerifyRational(CRational(5, -2), -5, 2);
		VerifyRational(CRational(-5, -2), 5, 2);
	}
	BOOST_AUTO_TEST_CASE(is_normalized_after_construction)
	{
		VerifyRational(CRational(6, 8), 3, 4);
		VerifyRational(CRational(6, -8), -3, 4);
		VerifyRational(CRational(-6, 8), -3, 4);
		VerifyRational(CRational(-6, -8), 3, 4);
		VerifyRational(CRational(-10, 20), -1, 2);
	}




//////////////////////////////////////////////////////////////////////////
// TODO: 1. Реализовать метод ToDouble() согласно заданию
// Возвращает отношение числителя и знаменателя в виде числа double
// Пример использования:
//	CRational r(3, 5)
//	cout << r.ToDouble(); // Должно вывести 0.6
//////////////////////////////////////////////////////////////////////////


BOOST_AUTO_TEST_SUITE(Ratio_numerator_to_denominator)

BOOST_AUTO_TEST_CASE(no_big_differecnce_for_computing_simple_fraction)
{
	CRational r(3, 5);
	BOOST_CHECK_CLOSE(r.ToDouble(), 0.6, 1e-10);
}

BOOST_AUTO_TEST_CASE(zero_divide_on_not_zero_equal_zero)
{
	CRational r(0, 4);
	BOOST_CHECK_CLOSE(r.ToDouble(), 0, 1e-10);
}

BOOST_AUTO_TEST_CASE(check_rational_number_on_rationality)
{
	CRational r(1, 3);
	BOOST_CHECK_CLOSE(r.ToDouble(), 0.333333, 1e-2);
}

BOOST_AUTO_TEST_SUITE_END()


//////////////////////////////////////////////////////////////////////////
// TODO: 2. Реализовать унарный + и унарный -
// Указание: см. материалы к лекции
// Пример использования:
//	const CRational r1(3, 5);
//	CRational r2 = -r1; // r2 должно стать -3/5
//	assert(r2.GetNumerator(), -3);
//	assert(r2.GetDenominator(), 5);
//	CRational r3 = +r2; // r3 также равно -3/5
//	assert(r3.GetNumerator(), -3);
//	assert(r3.GetDenominator(), 5);
// Унарный минус возвращает раицональное число без знака
// Унарный плюс возвращает рациональное число, равное текущему
// Реализация не должна допускать операции вроде:
//  -someRational = someOtherRational;
//	+someRational = someOtherRational;
//////////////////////////////////////////////////////////////////////////


BOOST_AUTO_TEST_SUITE(Unary_operations)

BOOST_AUTO_TEST_CASE(unary_minus)
{
	CRational first(3, 5);
	CRational second = -first;
	BOOST_CHECK_EQUAL(second.GetNumerator(), -3);
	BOOST_CHECK_EQUAL(second.GetDenominator(), 5);
}

BOOST_AUTO_TEST_CASE(unary_plus)
{
	CRational first(3, 5);
	CRational second = -first;
	CRational third = +second;
	BOOST_CHECK_EQUAL(third.GetNumerator(), -3);
	BOOST_CHECK_EQUAL(third.GetDenominator(), 5);
}

BOOST_AUTO_TEST_SUITE_END()


//////////////////////////////////////////////////////////////////////////
// TODO: 3. Реализовать бинарный +
// Возвращает результат сложения двух рациональных чисел, 
//	рационального числа с целым, целого числа с рациональным.
//	(1/2) + (1/6) = (2/3)
//	(1/2) + 1     = (3/2)
//	1 + (1/2)     = (3/2)
//////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////
// TODO: 4. Реализовать бинарный -
// Возвращает разность двух рациональных чисел, 
//	рационального числа и целого, либо целого числа и рационального:
//	(1/2) - (1/6) = (1/3)
//	(1/2) - 1     = (-1/2)
//	1 - (1/2)     = (1/2)
//////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////
// TODO: 5. Реализовать оператор +=
// Выполняет увеличение рационального числа на величину второго рационального,
//	либо целого числа:
//	(1/2) += (1/6)  → (2/3)
//	(1/2) += 1      → (3/2)
//////////////////////////////////////////////////////////////////////////


BOOST_AUTO_TEST_SUITE(Operator_plus_equal)

BOOST_AUTO_TEST_CASE(can_increase_other_rational_number)
{
	CRational first(1, 2);
	CRational second(1, 6);

	first += second;
	VerifyRational(first, 2, 3);
}

BOOST_AUTO_TEST_CASE(can_increase_other_integer_number)
{
	CRational first(1, 2);
	CRational second(1, 1);

	first += second;
	VerifyRational(first, 3, 2);

	first += 2;
	VerifyRational(first, 7, 2);
}

BOOST_AUTO_TEST_SUITE_END()


//////////////////////////////////////////////////////////////////////////
// TODO: 6. Реализовать оператор -=
// Выполняет уменьшение рационального числа на величину второго рационального либо целого числа :
// (1/2) -= (1/6)  → (1/3)
// (1/2) -= 1      → (-1/2)
//////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////
// TODO: 7. Реализовать оператор *
// Возвращает результат произведения рациональных чисел, 
//	рационального и целого, либо целого и рационального :
//	(1/2) * (2/3) = (1/3)
//	(1/2) * (-3)  = (-3/2)
//	(7*2) / 3     = (14/3)
//////////////////////////////////////////////////////////////////////////


BOOST_AUTO_TEST_SUITE(Operator_plus_equal)

BOOST_AUTO_TEST_CASE(multiplication_on_zero_equal_zero)
{
	CRational x(1, 2);
	VerifyRational(x * 0, 0, 0);
}

BOOST_AUTO_TEST_CASE(multiplication_rational_numbers)
{
	VerifyRational(CRational(-2, 4) * CRational(-1, 3), 1, 6);
	VerifyRational(CRational(1, 2) * CRational(2, 3), 1, 3);

}

BOOST_AUTO_TEST_CASE(multiplication_on_number)
{
	VerifyRational(CRational(1, 2) * -3, -3, 2);
	VerifyRational(CRational(7 * 2, 3), 14, 3);

	VerifyRational(7 * CRational(2, 3), 14, 3);
	VerifyRational(CRational(2, 3) * 7 , 14, 3);
}

BOOST_AUTO_TEST_SUITE_END()


//////////////////////////////////////////////////////////////////////////
// TODO: 8. Реализовать оператор /
// Возвращает частное двух рациональных чисел, 
//	рационального и целого, целого и рационального :
//	(1/2) ⁄ (2/3) = (3/4)
//	(1/2) ⁄ 5     = (1/10)
//	7 ⁄ (2/3)     = (21/2)
//////////////////////////////////////////////////////////////////////////


BOOST_AUTO_TEST_SUITE(Multiplacation)

BOOST_AUTO_TEST_CASE(divided_on_other_rational_number)
{
	CRational first(1, 2);
	CRational second(2, 3);

	first = first / second;
	VerifyRational(first, 3, 4);
}

BOOST_AUTO_TEST_CASE(divided_on_other_integer_number)
{
	CRational first(1, 2);
	CRational second(5, 1);

	first = first / second;
	VerifyRational(first, 1, 10);
}

BOOST_AUTO_TEST_CASE(integer_number_divided_on_rational)
{
	CRational first(7, 1);
	CRational second(2, 3);

	first = first / second;
	VerifyRational(first, 21, 2);
}

BOOST_AUTO_TEST_SUITE_END()


//////////////////////////////////////////////////////////////////////////
// TODO: 9. Реализовать оператор *=
// Умножает значение первого рационального числа на другое рациональное, 
//	либо целое:
//	(1/2) *= (2/3) → (1/3)
//	(1/2) *= 3     → (3/2)
//////////////////////////////////////////////////////////////////////////


BOOST_AUTO_TEST_SUITE(Operator_multiply_equal)

struct operator_multiply_equal_
{
	CRational rational = CRational(1, 2);
};

BOOST_FIXTURE_TEST_SUITE(operator_multiply_equal, operator_multiply_equal_)

BOOST_AUTO_TEST_CASE(multiply_on_rational)
{
	rational *= CRational(2, 3);
	VerifyRational(rational, 1, 3);
}

BOOST_AUTO_TEST_CASE(multiply_on_integer)
{
	rational *= 3;
	VerifyRational(rational, 3, 2);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()


//////////////////////////////////////////////////////////////////////////
// TODO: 10. Реализовать оператор /=
// Делит первое рациональное число на другое рациональное, 
//	либо целое:
//	(1/2) /= (2/3) → (3/4)
//	(1/2) /= 3     → (1/6)
//////////////////////////////////////////////////////////////////////////


BOOST_AUTO_TEST_SUITE(Operator_multiply_equal)

struct binary_addition_
{
	CRational rational = CRational(1, 2);
};

BOOST_FIXTURE_TEST_SUITE(binary_addition, binary_addition_)

BOOST_AUTO_TEST_CASE(division_on_rational)
{
	rational /= CRational(2, 3);
	VerifyRational(rational, 3, 4);
}

BOOST_AUTO_TEST_CASE(division_on_integer)
{
	rational /= 3;
	VerifyRational(rational, 1, 6);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()


//////////////////////////////////////////////////////////////////////////
// TODO: 11. Реализовать операторы == и !=
// Проверяют равенство (и неравенство) двух рациональных чисел, 
//	целого и рационального, рационального и целого:
//	(1/2) == (1/2) → true
//	(4/1) == 4     → true
//	3 == (3/1)     → true
//	(1/2) != (2/3) → true
//	(1/2) != 7     → true
//	3 != (2/3)     → true
//////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////
// TODO: 12. Реализовать операторы <, >, <=, >=
// Сравнивают два рациональных числа, рациональное с целым, 
//	целое с рациональным:
//	(1/2) >= (1/3) → true
//	(1/2) <= (1/3) → false
//	(3/1) > 2      → true
//	(1/2) < 7      → true
//	3 <= (7/2)     → true
//	3 >= (8/2)     → false
//////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////
// TODO: 13. Реализовать оператор вывода рационального числа в выходной поток 
//	std::ostream в формате <числитель>/<знаменатель>, 
//	например: 7/15
//////////////////////////////////////////////////////////////////////////


BOOST_AUTO_TEST_SUITE(Print_rational)

struct rational_to_ostream_
{
	output_test_stream output;
};

BOOST_FIXTURE_TEST_SUITE(rational_to_ostream, rational_to_ostream_)

BOOST_AUTO_TEST_CASE(rational_number_to_ostream)
{
	output << CRational(1, 2);
	BOOST_CHECK(output.is_equal("1/2"));
}

BOOST_AUTO_TEST_CASE(whole_rational_number_to_ostream)
{
	output << CRational(3);
	BOOST_CHECK(output.is_equal("3/1"));
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()


//////////////////////////////////////////////////////////////////////////
// TODO: 14. Реализовать оператор ввода рационального числа из входного потока 
//	std::istream в формате <числитель>/<знаменатель>, 
//	например: 7/15
//////////////////////////////////////////////////////////////////////////



BOOST_AUTO_TEST_SUITE_END()
