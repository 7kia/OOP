// stdafx.h: ���������� ���� ��� ����������� ��������� ���������� ������
// ��� ���������� ������ ��� ����������� �������, ������� ����� ������������, ��
// �� ����� ����������
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>

#include <iostream>// for std::cin and std::cout
#include <fstream>
#include <clocale>                     // ��� ������� ��������� ������

#include <cstdlib>;
#include <windows.h>;


#define BOOST_TEST_MODULE RectangleTestModule
#define BOOST_TEST_MODULE ApplicationTestModule
#define BOOST_TEST_INCLUDED
#pragma warning (disable:4702)
#include <boost/test/unit_test.hpp>


// TODO: ���������� ����� ������ �� �������������� ���������, ����������� ��� ���������
