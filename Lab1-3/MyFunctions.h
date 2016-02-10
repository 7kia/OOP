#ifndef MYFUNCTIONS_H
#define MYFUNCTIONS_H

#pragma once

typedef unsigned int uint;

struct Vector2U
{
	Vector2U(uint first , uint second);
	Vector2U();
	uint x;
	uint y;
};

static const int SIZE_CHAR_BUFFER = 255;

namespace MyFunctions
{
	bool CheckLoadFile(FILE **file , char const *name , char const *mode);
	bool IsSpaceSymbol(char symbol);
	void resetString(char* array);
	float ReadNumber(FILE *file);
	void ConstructFullFileName(char* name , const char* format);

	float GetDeterminate(float(*matrix)[2]);
	float GetDeterminate(float(*matrix)[3]);
	float GetMinor(float(*matrix)[3] , uint x , uint y);

	bool IsInList(Vector2U value ,const std::vector<Vector2U> &list);

};


#endif // MYFUNCTIONS_H
