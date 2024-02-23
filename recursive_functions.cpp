/********************************************************************************************
Name: Anthony Polese		                                 Z#: Z23582157
Course: Date Structures and Algorithm Analysis (COP3530) Professor: Dr. Lofton Bullard
Due Date: 03/26/2021 	                                 Due Time: 11:59pm
Total Points: 25                                         Assignment 10: Recursions

Description: This assignment involves practicing recursive functions.
			 The first function, palindrome(), works recursively and returns true or 
			 false based on if the given string is a palindrome.
			 The second function, printReverse(), works recursively and returns a 
			 given string in reverse.
			 The third function, printIterReverse(), does not work recursively and
			 returns a given string in reverse.
*********************************************************************************************/

#include <iostream>
#include <string.h>
#include <string>

using namespace std;

//function prototypes
bool palindrome(string key);		     //returns true if string key is a palindrome, false if not a palindrome
string printReverse(string key);     //recursive function that returns reverse of string key
string printIterReverse(string key); //non-recursive function that returns reverse of string key
void new_line();                     //clears remaining characters in input stream
char try_again();                    //asks if the user wants to retry the program, returns 'y' or 'n'

int main() {

	string userInput;  //stores string input given by user to use to test palindrome(), printReverse(), printIterReverse()
	char restart;	   //for do-while loop, 'y' or 'Y' causes another loop to try another string value
	bool isPalindrome; //stores value returned by palindrome()
	string reverse1;   //stores value returned by printReverse()
	string reverse2;   //stores value returned by printIterReverse()

	do {

		cout << "Enter a string: " << endl;
		getline(cin, userInput);

		isPalindrome = palindrome(userInput);  //determines if userInput is a palindrome
		
		if (isPalindrome) //is palindrome
		{
			cout << endl;
			cout << "palindrome():       " << "\"" << userInput << "\"" << " is a palindrome." << endl;
		}
		else				  //is not a palindrome
		{
			cout << endl;
			cout << "palindrome():       " << "\"" << userInput << "\"" << " is not a palindrome." << endl;
		}

		reverse1 = printReverse(userInput);     //userInput in reverse
		reverse2 = printIterReverse(userInput); //userInput in reverse

		//output statements
		cout << "printReverse():     " << "\"" << userInput << "\"" << " in reverse is ";
		cout	 << "\"" << reverse1 << "\"" << endl;
		cout << "printIterReverse(): " << "\"" << userInput << "\"" << " in reverse is ";
		cout	 << "\"" << reverse2 << "\"" << endl << endl;

		//asking if user wants to input another string value
		restart = try_again();
		cout << endl;

	} while (restart == 'Y' || restart == 'y');

	return 0;
}

/**************************************************************************************************
Name:			palindrome()
Pre-Condition:	It is not known whether string key is a palindrome
Post-Condition:	It is known whether string key is a palindrome
Description:		palindrome() is a recursive function that returns true if string key is 
				a palindrome, false if not a palindrome. 
**************************************************************************************************/
bool palindrome(string key)
{ 
	if (key.length() <= 1)					  //base case
	{
		return true;
	}
	else if (key[0] == key[key.length() - 1]) //recursive case
	{
		string key_reduced = "";                     //stores key with first and last letters removed
		for (int i = 1; i < (key.length() - 1); i++) //loop scans from second letter to second last letter
		{
			key_reduced += key[i];
		}

		return palindrome(key_reduced);
	}
	else										  
	{
		return false;
	}
}

/**************************************************************************************************
Name:			printReverse()
Pre-Condition:	Reverse of string key is not known
Post-Condition: Reverse of string key is known
Description:		printReverse() is a recursive function that returns string key 
				with the letters in reversed order.
**************************************************************************************************/
string printReverse(string key)
{
	if (key.length() <= 1) //base case
	{
		return key;
	}
	else					   //recursive case
	{
		string key_reverse = "";
		string key_reduced = "";

		//loop scans from first letter to second last letter of key and appends to key_reduced
		for (int i = 0; i < (key.length() - 1); i++)
		{
			key_reduced += key[i];
		}

		//appends last letter of key + result of recursive function call
		key_reverse += key[key.length() - 1] + printReverse(key_reduced);
		
		return key_reverse;
	}
}

/**************************************************************************************************
Name:			printIterReverse()
Pre-Condition:	Reverse of string key is not known
Post-Condition: Reverse of string key is known
Description:    printIterReverse() is a non-recursive function that returns string key
				with the letters in reversed order.
**************************************************************************************************/
string printIterReverse(string key)
{
	string key_reverse = "";

	//loop scans from last letter of key to the first and appends to key_reverse along the way
	for (int i = key.length(); i >= 0; i--)
	{
		key_reverse += key[i];
	}

	return key_reverse;
}

/**************************************************************************************************
Name:			try_again()
Pre-Condition:	It is not known whether the user wants to restart the program
Post-Condition: It is known whether the user wants to restart the program
Description:		try_again() returns a 'y', 'Y', 'n', or 'N' based on what the user inputs.
				try_again() asks the user if they want to restart the program and
				allows them to enter "yes" or "no". It really only matters whether it starts
				with 'y' or 'n'. The rest is discard by new_line(). If the input doesn't start
				with either letter, the user is asked to enter their answer again. Once
				a 'y', 'Y', 'n', or 'N' has been received, it is returned as a char variable.
**************************************************************************************************/
char try_again()
{
	char restart = ' ';

	//loop runs until valid response is given
	while (restart != 'y' && restart != 'Y' && restart != 'n' && restart != 'N')
	{
		cout << "Type \"yes\" to enter another string. Type \"no\" to exit." << endl;
		cin >> restart; //stores first letter of input
		new_line();		//clears rest of inputted line
		if (restart != 'y' && restart != 'Y' && restart != 'n' && restart != 'N')
		{
			cout << "Invalid input. Try again." << endl;
		}
	}

	return restart;
}

/**************************************************************************************************
Name:			new_line()
Pre-Condition:   Input line not cleared of unnecessary characters
Post-Condition: Input line is cleared of unnecessary characters
Description:		Used with the try_again() function to prevent I/O errors.
				try_again() takes a char input but allows user to enter a full word ("yes" or "no")
				so only the first letter of the input is stored in the char and new_line()
				prevents the remaining characters from interfering with future inputs by
				storing them in a variable one-after-the-other until the line break is found.
**************************************************************************************************/
void new_line()
{
	char symbol;
	do
	{
		cin.get(symbol);
	} while (symbol != '\n');
}