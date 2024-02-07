#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

//Function prototypes
void initialize(int& zeroCount, int& oddCount, int& evenCount);
void classifyNumber(int num, int& zeroCount, int& oddCount,
	int& evenCount);
void printResults(int zeroCount, int oddCount, int evenCount, 
	int sum, int total);

int main()
{
	//Variable declaration
	int number,			//variable to store the new number
		zeros,			//variable to store the number of zeros
		odds,			//variable to store the number of odd integers
		evens;			//variable to store the number of even integers

	int sum = 0,		//Variable to store the sum of all numbers
		average = 0,	//variable to store the average of all numbers
		total = 0;		//variable to store the total amount of seperate numbers

	int count = 0;		//variable to store the amount of times the loop has processed
						//once this reaches 10, it will reset to 0

	char q;				//variable used to pause applicaiton before exiting

	ifstream inFile;
	ofstream outFile;

	initialize(zeros, odds, evens); 

	cout << "Anthony Cantu\t" << "L2-6\t" << "L2-6.exe" << endl;

	inFile.open("C:\\Users\\Anthony\\OneDrive\\Documents\\School\\Fall 2023\\CIS 022 - C++\\Labs\\Lab 2\\Lab 2 - Documents\\L2-6\\L2-6Data.txt");

	if (!inFile) //Error check, if file cannot be opened
	{
		cout << "ERROR: Unable to open input file." << endl
			 << "Press enter to terminate the program.";

		cin.ignore(2, '\n');
		cin.get(q);
		
		return 1;
	}

	outFile.open("C:\\Users\\antca\\OneDrive\\Documents\\School\\Fall 2023\\CIS 022 - C++\\Labs\\Lab 2\\Lab 2 - Documents\\L2-6\\Ch06_Ex20Out-AC.txt");
	outFile << setfill(' ');

	cout << "Processing Data";

	inFile >> number;
	while (!inFile.eof()) //Loop through each number of the input file
	{
		if (!(inFile >> number)) 
		{
			if (inFile.eof())
				break;
			else
			{
				cout << "ERROR: " << number << endl;
				inFile.clear();
				inFile.ignore();
				continue;
			}
		}
	
		cout << "NUMBER PROCESSED: " << number << endl;
		total++;
		count++;
		sum += number;
		outFile << right << setw(7) << number;
		classifyNumber(number, zeros, odds, evens);
		inFile >> number;
		if (count == 10)
		{
			count = 0; //Reset count back to 0
			outFile << endl; //Start new line after 10 numbers
		}
		
	}

	cout << endl; //Line Break;

	//Output to console
	printResults(zeros, odds, evens, sum, total); 

	//Output to file
	outFile << endl;
	outFile << "There are " << evens << " evens, "
		<< "which includes " << zeros << " zeros"
		<< endl;
	outFile << "Total number of odds are: " << odds
		<< endl;
	outFile << "The sum of numbers = " << sum << endl;
	outFile << "The average is " << sum / total;

	//Close files
	inFile.close();
	outFile.close();

	cout << endl; //Line Break;
	cout << "Press any key to Exit.";
	cin.ignore(2, '\n');
	cin.get(q);

	return 0;
}

void initialize(int& zeroCount, int& oddCount, int& evenCount)
{
	zeroCount = 0;
	oddCount = 0;
	evenCount = 0;
}

void classifyNumber(int num, int& zeroCount, int& oddCount,
	int& evenCount)
{
	switch (num % 2)
	{
	case 0:
		evenCount++;
		if (num == 0)
			zeroCount++;
		break;
	case 1:
	case -1:
		oddCount++;
	} 
} 

void printResults(int zeroCount, int oddCount, int evenCount, 
	int sum, int total)
{
	cout << "There are " << evenCount << " evens, "
		<< "which includes " << zeroCount << " zeros"
		<< endl;
	cout << "Total number of odds are: " << oddCount
		<< endl;
	cout << "The sum of numbers = " << sum << endl;
	cout << "The average is " << sum / total;
}