#include "main.h"

void main()
{
	try
	{
		string input = "Test/input_file_1.txt";
		string output = "Test/TestOutput_file_1.txt";
		RunTest(10,4, input, output);
		//Run();
	}
	catch (const invalid_argument& e)
	{
		IO::PrintMsgToConsole(e.what());
	}
	catch (const std::exception& e)
	{
		IO::PrintMsgToConsole("unknown error occurred");
		exit(0);
	}
}

void Run()
{
	int arraySize = IO::GetIntInputFromConsole("Enter amount of numbers: ");
	int kValue = IO::GetIntInputFromConsole("Enter your k value: ");
	string inputFilePath = IO::GetStringInput("Enter input file name: ");
	string outputFilePath = IO::GetStringInput("Enter output file name: ");
	int* intArray = IO::GetArrayOfIntegersFromFile(inputFilePath, arraySize);
	int* resultArray = KWayMergeSort::Sort(intArray, arraySize, kValue);
	IO::PrintArrayToFile(resultArray, arraySize, outputFilePath);
}



void RunTest(int i_ArrSize, int i_Kvalue, string& i_InputFile, string& i_OutputFile)
{
	int* intArray = IO::GetArrayOfIntegersFromFile(i_InputFile, i_ArrSize);
	int* resultArray = KWayMergeSort::Sort(intArray, i_ArrSize, i_Kvalue);
	cout << endl;
	for (int i = 0; i < i_ArrSize; i++)
		cout << resultArray[i] << " ";
	IO::PrintArrayToFile(resultArray, i_ArrSize, i_OutputFile);
}
