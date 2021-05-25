
#include "IO.h"
#include "KWayMergeSort.h"

void Run();
void TestEverything();


int main()
{
	try
	{
		//TestEverything();
		Run();
	}
	catch (const std::exception& e)
	{
		IO::PrintMsgToConsole(e.what());
		exit(0);
	}

	return 0;
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


void TestEverything()
{
	std::string testCases[] = { "input1", "input1error", "input2", "input2error", "input3error", "input4", "input5" };
	fstream inputFile;
	string testFileName;
	string folderName = "Test\\";

	for (int i = 0; i <= testCases->length(); i++)
	{
		testFileName = folderName + testCases[i] + ".txt";
		inputFile.open(testFileName);

		try
		{
			if (inputFile.is_open())
			{
				int n = IO::GetPositiveNumberFromFile(inputFile);
				int k = IO::GetPositiveNumberFromFile(inputFile);
				string input = folderName;
				input += IO::GetStringFromFile(inputFile);
				string output = folderName;
				output += IO::GetStringFromFile(inputFile);

				inputFile.close();

				int* intArray = IO::GetArrayOfIntegersFromFile(input, n);
				int* resultArray = KWayMergeSort::Sort(intArray, n, k);
				IO::PrintArrayToFile(resultArray, n, output);
			}
			else
			{
				throw std::invalid_argument("wrong input");
			}
		}
		catch (const std::exception& e)
		{
			if (inputFile.is_open())
			{
				inputFile.close();
			}

			IO::PrintMsgToConsole(e.what());
			IO::PrintMsgToConsole("\n");
		}
	}
}
