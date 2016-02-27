#pragma once

#include <vector>
#include <iomanip>// for setw()

#include "MyFunctions.h"

typedef std::vector<double> RowMatrix;
typedef std::vector<RowMatrix> Matrix;

namespace MatrixOperations
{
	static const std::string MESSAGE_ZERO_DETERMINATE = "Determinate the matrix = 0!";

	double GetDeterminate(const Matrix &matrix);
	double GetMinor(const Matrix &matrix , size_t x , size_t y);
	Matrix GetMinorMatrix(const Matrix &matrix);
	Matrix GetTransposeMatrix(const Matrix &matrix);
	Matrix GetInvertMatrix(const Matrix &matrix);

	void PrintMatrix(const Matrix & matrix);
	void FillMatrixFromFile(std::string nameFile, Matrix &matrix);
}