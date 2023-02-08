#include "Functions.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/* Declaring array that will be 10 numbers of 10 lines */

int arr[100] = {};		//Made global in need to change the size depending on what I should do with program
int user_size = 100;

int main()
{
	string FileName;
	int choice;
	char again = 'y';
	bool option = true;
	ifstream File;

	while (true)
	{
		cout << "Enter the name of the file: ";
		cin >> FileName;
		cout << endl << endl;								/*Following code is for the opening file and closing until done right
															wasn't put into function to be more clear for me while doing*/
		File.open(FileName);

		if (File)
		{
			break;
		}

		else
		{
			cout << "Your file was not found, try again." << endl;
		}
	}

	int n = 0;
	int num;

	while (File.good())
	{
		File >> num;
		arr[n] = num;
		n++;
	}

	File.close();







	while (option)
	{
		/*Brings up user menu for array options*/
		menu();

		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			int check_num;
			cout << "What number would you like to check ==> ";
			cin >> check_num;
			int result = search(arr, user_size, check_num);
			(result == -1)
				? cout << "Your number was not in the arry."
				: cout << "Your number was at index " << result;
		}
		break;
		case 2:
		{
			modify(arr, 0, user_size);
		}
		break;
		case 3:
		{
			user_size = user_size + 1;
			insertElement(arr, user_size);

		}
		break;
		case 4:
		{

			/*Longer code due to the user having to input both choice and index */
			int userIndex;
			char userChoice;
			cout << "What index would you like to replace in array ==> ";
			cin >> userIndex;
			cout << "Enter 0 to replace with 0 or enter D to delete the integer ==>";
			cin >> userChoice;
			if (userChoice == 'D')
			{
				deleteInt(arr, userIndex, user_size);
				user_size = user_size - 1;
			}
			else if (userChoice == '0')
			{
				replaceElement(arr, userIndex, userChoice, user_size);
			}

		}
		break;
		case 5:
			/*Not asked to do but is visual aid to see if what is being done works*/
			printArray(arr, user_size);
			break;
		default:
			cout << "Error! You did not pick a number between 1-4" << endl;
			break;

		}


		cout << endl;
		cout << "If you would like to repeat type Y for yes or N for No ==> ";
		cin >> again;
		cout << endl;									/* This is for the prompt to repeat in order for the user to
														be able to see or repeat whats going on*/
		if (again == 'Y' || again == 'y')
			continue;
		else if (again == 'N' || again == 'n')
		{
			option = false;
			break;
		}
	}

}