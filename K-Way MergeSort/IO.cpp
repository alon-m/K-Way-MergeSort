#include "IO.h"

int IO::GetPositiveNumberFromConsole(const char* i_Msg)
{
	int result = 0;
	bool isInputValid = false;
	string inputStr;

	while (!isInputValid)
	{
		inputStr = GetStringInput(i_Msg);
		isInputValid = CheckIfStringIsNumber(inputStr);
		
		if (isInputValid)
		{
			result = stoi(inputStr);
			isInputValid = result > 0;
		}
	}

	return result;
}

int IO::GetIntInputFromConsole(const char* i_Msg)
{
	int result;
	bool isInputValid = false;
	string inputStr;

	while (!isInputValid)
	{
		inputStr = GetStringInput(i_Msg);
		isInputValid = CheckIfStringIsNumber(inputStr);
	}

	result = stoi(inputStr);

	return result;
}

int IO::GetPositiveNumberFromFile(fstream& i_InputFile)
{
	string inputStr;
	int result = 0;

	i_InputFile >> inputStr;
	bool isInputValid = CheckIfStringIsNumber(inputStr);

	if (isInputValid)
	{
		result = stoi(inputStr);
		isInputValid = result > 0;
	}

	if (!isInputValid)
	{
		throw invalid_argument("wrong input");
	}

	return result;
}

int IO::GetIntInputFromFile(fstream& i_InputFile)
{
	string inputStr;

	i_InputFile >> inputStr;
	bool isInputValid = CheckIfStringIsNumber(inputStr);

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
	std::cin >> inputStr;

	return inputStr;
}

string IO::GetStringFromFile(fstream& i_InputFile)
{
	string result;

	i_InputFile >> result;

	return result;
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
			throw std::invalid_argument("wrong input");
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
		throw std::invalid_argument("wrong input");
	}

}

void IO::PrintArrayToConsole(int i_Arr[], int i_Size)
{
	std::cout << "[ ";
	for (int i = 0; i < i_Size; i++)
	{
		std::cout << i_Arr[i];
		if (i != i_Size - 1)
		{
			cout << ", ";
		}
	}
	std::cout << " ]" << endl;
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
			throw std::invalid_argument("wrong input");
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

bool IO::CheckIfStringIsNumber(string& i_str)
{
	bool result = true;

	if (i_str.length() <= 9)
	{
		for (int i = 0; i < i_str.length(); i++)
		{
			if (i_str[i] == '-')
			{
				if (i != 0)
				{
					result = false;
					break;
				}
			}
			else if (!isdigit(i_str[i]))
			{
				result = false;
				break;
			}
		}
	}
	else
	{
		result = false;
	}

	return result;
}
