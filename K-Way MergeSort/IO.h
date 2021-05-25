#pragma once
#include <algorithm>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;


class IO
{
public:

	static int GetPositiveNumberFromConsole(const char* i_Msg);

	static int GetIntInputFromConsole(const char* i_Msg);

	static int GetPositiveNumberFromFile(fstream& i_InputFile);
	
	static int GetIntInputFromFile(fstream& i_InputFile);

	static string GetStringInput(const char* i_Msg);

	static string GetStringFromFile(fstream& i_InputFile);

	static int* GetArrayOfIntegersFromFile(string& i_InputFileName, int i_AmountOfNumbers);

	static void PrintMsgToConsole(const char* i_Msg);

	static void PrintMsgToFile(ofstream& i_OutputFile, const char* i_Msg);

	static void PrintArrayToConsole(int i_Arr[], int i_Size);
	
	static void PrintArrayToFile(int i_Arr[], int i_Size, string& i_OutputFileName);

	static bool CheckIfStringIsNumber(string& i_str);

};