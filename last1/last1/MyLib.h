#pragma once
#ifdef LIB_EXPORT
#define LIB_API __declspec(dllexport)
#else
#define LIB_API __declspec(dllimport)
#endif
#include <string>
using namespace std;
extern "C" LIB_API int CountFromStr(string a);