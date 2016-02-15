#ifndef MATRIXOPERATIONS_H
#define MATRIXOPERATIONS_H

#pragma once


#include <vector>
#include <iomanip>// for setw()

#include "boost/numeric/ublas/vector.hpp"
#include "MyFunctions.h"

typedef std::vector<double> RowMatrix;
typedef std::vector<RowMatrix> Matrix;

namespace MatrixOperations
{
	double GetDeterminate(const Matrix &matrix);
	double GetMinor(const Matrix &matrix , size_t x , size_t y);
	Matrix GetMinorMatrix(const Matrix &matrix);
	Matrix GetTransposeMatrix(const Matrix &matrix);

	void PrintMatrix(const Matrix & matrix);
}

#endif