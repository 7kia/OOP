#include "stdafx.h"
#include "Rational.h"

CRational::CRational(int numerator, int denominator)
	: m_numerator(numerator)
	, m_denominator(denominator)
{
	if (denominator < 0)
	{
		m_numerator = -m_numerator;
		m_denominator = -m_denominator;
	}
	Normalize();
}

int CRational::GetNumerator() const
{
	return m_numerator;
}

int CRational::GetDenominator() const
{
	return m_denominator;
}

void CRational::Normalize()
{
	const int gcd = GCD(abs(m_numerator), m_denominator);
	m_numerator /= gcd;
	m_denominator /= gcd;
}

unsigned GCD(unsigned a, unsigned b)
{
	while (b != 0)
	{
		std::swap(a, b);
		b = b % a;
	}
	return (a != 0) ? a : 1;
}

//////////////////////////////////////////////////////////////////////////
// TODO: 1. Реализовать метод ToDouble() согласно заданию
//////////////////////////////////////////////////////////////////////////


double CRational::ToDouble()
{
	return static_cast<double>(m_numerator) / static_cast<double>(m_denominator);
}

//////////////////////////////////////////////////////////////////////////
// TODO: 2. Реализовать унарный + и унарный -
//////////////////////////////////////////////////////////////////////////

CRational const CRational::operator+() const
{
	return *this;
}

CRational const CRational::operator-()	const
{
	return CRational((-1)*m_numerator, m_denominator);
}


//////////////////////////////////////////////////////////////////////////
// TODO: 3. Реализовать бинарный +
//////////////////////////////////////////////////////////////////////////


CRational const operator+(CRational const &rational1, CRational const &rational2)
{
	return (CRational((rational1.GetNumerator() * rational2.GetDenominator())
						+ (rational2.GetNumerator() * rational1.GetDenominator()),
						rational1.GetDenominator() * rational2.GetDenominator()));
}


//////////////////////////////////////////////////////////////////////////
// TODO: 4. Реализовать бинарный -
//////////////////////////////////////////////////////////////////////////


CRational const operator-(CRational const &rational1, CRational const &rational2)
{
	return rational1 + -rational2;
}


//////////////////////////////////////////////////////////////////////////
// TODO: 5. Реализовать оператор +=
//////////////////////////////////////////////////////////////////////////


CRational & CRational::operator+=(CRational const & other)
{
	*this = *this + other;

	return *this;
}


//////////////////////////////////////////////////////////////////////////
// TODO: 6. Реализовать оператор -=
//////////////////////////////////////////////////////////////////////////


CRational & CRational::operator-=(CRational const & other)
{
	*this = *this - other;

	return *this;
}


//////////////////////////////////////////////////////////////////////////
// TODO: 7. Реализовать оператор *
//////////////////////////////////////////////////////////////////////////


CRational const operator*(CRational const & left, CRational const & right) 
{
	CRational result(left.m_numerator * right.m_numerator,
					(left.m_numerator * right.m_numerator != 0) ? left.m_denominator * right.m_denominator : 0);
	result.Normalize();

	return result;
}

//////////////////////////////////////////////////////////////////////////
// TODO: 8. Реализовать оператор /
//////////////////////////////////////////////////////////////////////////


CRational const operator/(CRational const & left, CRational const & right)
{
	CRational copyLeft = left;

	copyLeft.m_numerator *= right.GetDenominator();
	copyLeft.m_denominator *= right.GetNumerator();
	copyLeft.Normalize();

	return copyLeft;
}



//////////////////////////////////////////////////////////////////////////
// TODO: 9. Реализовать оператор *=
//////////////////////////////////////////////////////////////////////////


CRational& CRational::operator*=(const CRational & num2)
{
	m_numerator *= num2.GetNumerator();
	m_denominator *= num2.GetDenominator();

	Normalize();

	return *this;
}

//////////////////////////////////////////////////////////////////////////
// TODO: 10. Реализовать оператор /=
//////////////////////////////////////////////////////////////////////////

CRational& CRational::operator/=(CRational const & other)
{
	*this = *this / other;
	return *this;
}


//////////////////////////////////////////////////////////////////////////
// TODO: 11. Реализовать операторы == и !=
//////////////////////////////////////////////////////////////////////////


bool const operator==(CRational const& first, CRational const& second)
{
	return ((first.GetNumerator() == second.GetNumerator())
			&& (first.GetDenominator() == second.GetDenominator()));
}

bool const operator!=(CRational const& first, CRational const& second)
{
	return !(first == second);
}


//////////////////////////////////////////////////////////////////////////
// TODO: 12. Реализовать операторы <, >, <=, >=
//////////////////////////////////////////////////////////////////////////


bool const CRational::operator <(CRational const &rat) const
{
	auto copyRightVal = rat;
	auto copyLeftVal = *this;

	copyRightVal.m_numerator *= m_denominator;
	copyRightVal.m_denominator *= m_denominator;

	copyLeftVal.m_numerator *= copyRightVal.m_denominator / copyLeftVal.m_denominator;
	copyLeftVal.m_denominator *= copyRightVal.m_denominator / copyLeftVal.m_denominator;

	return copyLeftVal.m_numerator < copyRightVal.m_numerator;
}

bool const CRational::operator >(CRational const &rat) const
{
	auto copyRightVal = rat;
	auto copyLeftVal = *this;

	copyRightVal.m_numerator *= m_denominator;
	copyRightVal.m_denominator *= m_denominator;

	copyLeftVal.m_numerator *= copyRightVal.m_denominator / copyLeftVal.m_denominator;
	copyLeftVal.m_denominator *= copyRightVal.m_denominator / copyLeftVal.m_denominator;

	return copyLeftVal.m_numerator > copyRightVal.m_numerator;
}

bool const CRational::operator <=(CRational const &rat) const
{
	auto copyRightVal = rat;
	auto copyLeftVal = *this;

	copyRightVal.m_numerator *= m_denominator;
	copyRightVal.m_denominator *= m_denominator;

	copyLeftVal.m_numerator *= copyRightVal.m_denominator / copyLeftVal.m_denominator;
	copyLeftVal.m_denominator *= copyRightVal.m_denominator / copyLeftVal.m_denominator;

	return copyLeftVal.m_numerator <= copyRightVal.m_numerator;
}

bool const CRational::operator >=(CRational const &rat) const
{
	auto copyRightVal = rat;
	auto copyLeftVal = *this;

	copyRightVal.m_numerator *= m_denominator;
	copyRightVal.m_denominator *= m_denominator;

	copyLeftVal.m_numerator *= copyRightVal.m_denominator / copyLeftVal.m_denominator;
	copyLeftVal.m_denominator *= copyRightVal.m_denominator / copyLeftVal.m_denominator;

	return copyLeftVal.m_numerator >= copyRightVal.m_numerator;
}


//////////////////////////////////////////////////////////////////////////
// TODO: 13. Реализовать оператор вывода рационального числа в выходной поток 
//////////////////////////////////////////////////////////////////////////



std::ostream & operator<<(std::ostream & stream, CRational const & number)
{
	stream << number.GetNumerator() << "/" << number.GetDenominator();
	return stream;
}


//////////////////////////////////////////////////////////////////////////
// TODO: 14. Реализовать оператор ввода рационального числа из входного потока 
//////////////////////////////////////////////////////////////////////////



std::istream& operator>>(std::istream &stream, CRational &number)
{
	std::streamoff const startPosistion = stream.tellg();

	int numerator;
	int denominator;
	if ((stream >> numerator) && (stream.get() == '/') && (stream >> denominator))
	{
		number = CRational(numerator, denominator);
	}
	else
	{
		stream.seekg(startPosistion);
		stream.setstate(stream.rdstate() | std::ios_base::failbit);
	}

	return stream;
}