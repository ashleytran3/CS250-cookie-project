/* 
    All the functions in this file were collaboratively worked on and implemented
*/
#include "Interface.h"

#include <iostream>
#include <string>

using namespace std;

// Definition function displayMenu
void displayMenu()
{
	cout << string(62, '*') << endl
		<< string(24, ' ') << "COOKIE RECIPES"
		<< endl << string(62, '*') << endl << endl;

	cout << "Select one of the following:" << endl << endl
		<< "    a. Print all recipes" << endl
		<< "    b. Print cookie recipe" << endl
		<< "    c. Print cookie calories" << endl
		<< "    d. Print limited calories" << endl
		<< "    e. Check serving and party size" << endl
		<< "    f. To exit" << endl << endl;
}

// Definition function processChoice
void processChoice(CookieList& cookieList)
{
	bool done = false;
	char input = 'a';

	while (!done)
	{
		cout << "Enter your choice: ";
		cin >> input;
		cout << endl;
		bool valid = true;
		switch (input)
		{
			case 'a':
			{
				cout << string(62, '-') << endl << "    COOKIE RECIPES"
					<< endl << string(62, '-') << endl << endl;

				cookieList.printAllCookies();

				break;
			}
			case 'b':
			{
				cout << string(62, '-') << endl << "    COOKIE RECIPES" << endl
					<< string(62, '-') << endl << endl <<
					"Choose a cookie to view the recipe." << endl << endl;

				cookieList.printCookiesSelection();

				cout << endl << "Your choice: ";
				int choice1 = 0;
				cin >> choice1;
				cout << endl;

				cookieList.printRecipe(choice1);

				break;
			}
			case 'c':
			{
				cout << string(62, '-') << endl << "    COOKIE CALORIES"
					<< endl << string(62, '-') << endl << endl
					<< "Choose a cookie # to view number of calories."
					<< endl << endl;

				cookieList.printCookiesSelection();

				cout << endl << "Your choice: ";
				int choice2 = 0;
				cin >> choice2;
				cout << endl << "    ";

				cookieList.printCalories(choice2);

				break;
			}
			case 'd':
			{
				cout << string(62, '-') << endl
					<< "    MAXIMUM CALORIES" << endl << string(62, '-')
					<< endl << endl <<
					"What is the maximum # of calories (100-200)? ";

				size_t numCalories = 0;
				cin >> numCalories;
				cout << endl;

				cookieList.printLimitedCalories(numCalories);

				break;
			}
			case 'e':
			{
				cout << string(62, '-') << endl << "    COOKIE RECIPES"
					<< endl << string(62, '-') << endl << endl
					<< "Choose a cookie to view the serving size."
					<< endl << endl;

				cookieList.printCookiesSelection();

				cout << endl << "Your choice: ";
				size_t choice3 = 0;
				cin >> choice3;

				cout << "Your party size: ";
				size_t partySize = 0;
				cin >> partySize;
				cout << endl;

				if (cookieList.checkSufficientServings(choice3, partySize))
				{
					cout << "    You have enough cookies for the party!";
				}
				else
				{
					cout << "    You do not have enough cookies for the party.";
				}

				cout << endl;

				break;
			}
			case 'f':
			{
				cout << "Thank you for using our software. Good bye!";
				done = true;
				break;
			}
			default:
				valid = false;
				cout << "  => Sorry. That is not a selection." << endl;

			}

			if(!done) 
			{
				if (valid) 
				{
					cout << endl << string(62, '=') << endl << endl <<
						"Would you like to continue (y/n)? ";
				}
				else
				{
					cout << endl << string(62, '=') << endl << endl <<
						"Would you like to try again (y/n)? ";
				}
				
				cin >> input;
				cout << endl;

				if (input == 'y') 
				{
					displayMenu();
				}
				else if (input == 'n') 
				{
					cout << "Thank you for using our software. Good bye!";
					done = true;
				}
				
			}
			
			
	}
}
