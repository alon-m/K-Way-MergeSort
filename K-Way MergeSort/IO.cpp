#include "IO.h"

int IO::GetIntInputFromConsole(const char* i_Msg)
{
	int result;
	bool isInputValid = false;
	while (!isInputValid)
	{
		string inputStr = GetStringInput(i_Msg);

		isInputValid = all_of(inputStr.begin(), inputStr.end(), isdigit) &&
			inputStr.length() <= 9;

		result = stoi(inputStr);
	}

	return result;
}

int IO::GetIntInputFromFile(fstream& i_InputFile)
{
	string inputStr;

	i_InputFile >> inputStr;
	bool isInputValid = all_of(inputStr.begin(), inputStr.end(), isdigit) &&
		inputStr.length() <= 9;

	if (!isInputValid)
	{
		throw invalid_argument("wrong input");
	}

	int result = stoi(inputStr);

	return result;
}

string IO::GetStringInput(const char* i_Msg)
{
	string inputStr;

	PrintMsgToConsole(i_Msg);
	cin >> inputStr;

	return inputStr;
}

int* IO::GetArrayOfIntegersFromFile(string& i_InputFileName, int i_AmountOfNumbers)
{
	int* result = new int[i_AmountOfNumbers];
	fstream inputFile;

	try
	{
		inputFile.open(i_InputFileName);
		if (inputFile.is_open())
		{
			for (int i = 0; i < i_AmountOfNumbers; i++)
			{
				result[i] = GetIntInputFromFile(inputFile);
			}
		}
		else
		{
			throw exception("file didn't open successfully");
		}

		return result;
	}
	catch (const std::exception& e)
	{
		if (inputFile.is_open())
		{
			inputFile.close();
		}
		throw e;
	}
}

void IO::PrintMsgToConsole(const char* i_Msg)
{
	cout << i_Msg;
}

void IO::PrintMsgToFile(ofstream& i_OutputFile, const char* i_Msg)
{
	if (i_OutputFile.is_open())
	{
		i_OutputFile << i_Msg;
	}
	else
	{
		throw exception("file didn't open successfully");
	}

}

void IO::PrintArrayToConsole(int i_Arr[], int i_Size)
{
	cout << "[ ";
	for (int i = 0; i < i_Size; i++)
	{
		cout << i_Arr[i];
		if (i != i_Size - 1)
		{
			cout << ", ";
		}
	}
	cout << " ]" << endl;
}

void IO::PrintArrayToFile(int i_Arr[], int i_Size, string& i_OutputFileName)
{
	ofstream outputFile;

	try
	{
		outputFile.open(i_OutputFileName);

		if (outputFile.is_open())
		{
			for (int i = 0; i < i_Size; i++)
			{
				string toPrint = to_string(i_Arr[i]) + "\n";
				PrintMsgToFile(outputFile, toPrint.c_str());
			}
		}
		else
		{
			throw new exception("file didn't open successfuly");
		}

		outputFile.close();
	}
	catch (const std::exception& e)
	{
		if (outputFile.is_open())
		{
			outputFile.close();
		}
		throw e;
	}


}
