#pragma once

#ifdef MATHLIBRARY_EXPORTS
#define MATHLIBRARY_API __declspec(dllexport)
#else
#define MATHLIBRARY_API __declspec(dllimport)
#endif
#include <string>
using namespace std;
extern "C" MATHLIBRARY_API int CountFromStr(string a);