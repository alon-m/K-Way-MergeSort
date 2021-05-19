#include "main.h"

void main()
{
	try
	{
		int arraySize = IO::GetIntInputFromConsole("Enter amount of numbers");
		int kValue = IO::GetIntInputFromConsole("Enter your k value");
		string inputFilePath = IO::GetStringInput("Enter input file name");
		string outputFilePath = IO::GetStringInput("Enter output file name");
		int* intArray = IO::GetArrayOfIntegersFromFile(inputFilePath, arraySize);
		int* resultArray = KWayMergeSort::Sort(intArray, arraySize, kValue);
		IO::PrintArrayToFile(resultArray, arraySize, outputFilePath);
	}
	catch (const invalid_argument& e)
	{
		IO::PrintMsgToConsole(e.what());
	}
	catch (const std::exception& e)
	{
		IO::PrintMsgToConsole("unknown error occured");
		exit(0);
	}
}

int* CreateTestCase()
{
	//{ 1, 6, -2, 3, 15, 4, 8 };
	int* testArr = new int[7];

	testArr[0] = 1;
	testArr[1] = 6;
	testArr[2] = -2;
	testArr[3] = 3;
	testArr[4] = 15;
	testArr[5] = 4;
	testArr[6] = 8;

	return testArr;
}
