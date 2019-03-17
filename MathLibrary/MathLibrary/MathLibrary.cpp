// MathLibrary.cpp : Определяет экспортированные функции для приложения DLL.
//

#include "stdafx.h"
#define LIB_EXPORT
#include <string>
#include "MathLibrary.h"
using namespace std;
int CountFromStr(string inGo)
{
	int b = 0;
	for (int i = 0; i < inGo.size(); ++i)
		if ((int)inGo[i] > -1 && (int)inGo[i] < 255 && isdigit(inGo[i]))
			++b;
	return b;
}

