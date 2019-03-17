
#include "pch.h"
#include <iostream>
#include <string>
#include "MathLibrary.h"

using namespace std;

const char EOLN = '\n';
const char YES_CHAR = 'Y';
const char NO_CHAR = 'N';
const int LEFT_BOUND = -1000000000;
const int RIGHT_BOUND = +1000000000;
const std::string ABOUT_MESSAGE = "Enter a string";
const std::string CONTINUE_MESSAGE = "Continue? (Y/N)>";
const std::string INCORRECT_MESSAGE = "Input is incorrect. Try again>";
const std::string INPUT_MESSAGE = "Input an string>";
const std::string OUT_OF_BOUNDS_MESSAGE = "This number is out of bounds";
const std::string OUTPUT_MESSAGE = "Result: ";
const std::string SKIP_CHARACTERS = " ";

void ClearInputStream(std::istream &in)
{
	in.clear();
	while (in.peek() != EOLN && in.peek() != EOF)
	{
		in.get();
	}
}
int Seek(std::istream &in)
{
	while (in.peek() != EOLN)
	{
		in.get();
	}
	return in.peek();
}
bool CheckBounds(int n)
{
	bool ok = (LEFT_BOUND <= n && n <= RIGHT_BOUND);
	if (!ok)
	{
		std::cout << OUT_OF_BOUNDS_MESSAGE << " ["
			<< LEFT_BOUND << ", " << RIGHT_BOUND << "]" <<
			std::endl;
	}
	return ok;
}
string ReadInt(std::istream &in)
{
	std::cout << INPUT_MESSAGE;
	string ans;

	getline(cin, ans);
	//while (!in || Seek(in) != EOLN)
	while (!cin)
	{
		ClearInputStream(in);
		std::cout << INCORRECT_MESSAGE;
		cin.ignore();
		getline(cin, ans);
	}
	return ans;
}


bool NeedContinue(std::istream &in)
{
	std::cout << CONTINUE_MESSAGE;
	char ans;
	in >> ans;
	while (!in || Seek(in) != EOLN || ans != YES_CHAR && ans != NO_CHAR)
	{
		ClearInputStream(in);
		std::cout << INCORRECT_MESSAGE;
		in >> ans;
	}
	return ans == YES_CHAR;
}
int main()
{
	std::cout << ABOUT_MESSAGE << std::endl;
	bool cont = true;
	while (cont)
	{
		string inGo = ReadInt(std::cin);

		std::cout << OUTPUT_MESSAGE << CountFromStr(inGo) << std::endl;
		cont = NeedContinue(std::cin);
		cin.ignore();
	}
	return 0;
}