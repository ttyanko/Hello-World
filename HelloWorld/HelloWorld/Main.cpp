/************************************************************************************************
* Program : Hello World																			*
* Author : Tyler Yanko																			*
* Last Revision : 2/13/2017																		*
* Description : Just a basic program to refresh myself on the basic foundations of C++.			*
*				(IO, loops, control statements, pointers, files, functions, classes)			*
************************************************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include "Person.h"

void helloFunction(std::string *nameOfUser);    // Prompts name from user

int main()
{
	std::string nameOfUser;
	std::string genderOfUser;
	int ageOfUser;
	std::string confirmReset;
	std::string continuePrompt;
	std::ifstream nameFile("name.txt");

	// Testing if file exists and manipulating it
	if (nameFile.good())
	{
		getline(nameFile, nameOfUser);
		std::cout << "I see your file here, your name is " << nameOfUser << std::endl;
		nameFile.close();
		std::cout << "Would you like to start over?\n (yes / no)" << std::endl;
		getline(std::cin, confirmReset);

		// For this loop I'll just use conditions instead of a flag variable, this looks more elegant.
		do 
		{
			if (confirmReset == "no")
			{
				std::cout << "Hello World, " << nameOfUser << std::endl;
			}
			else if (confirmReset == "yes")
			{
				if (remove("name.txt") != 0)
				{
					std::cout << "I couldn't delete your file." << std::endl;
				}
				else
				{
					std::cout << "I've deleted your file" << std::endl << std::endl;
					std::cout << "Let's get you set up" << std::endl;
					helloFunction(&nameOfUser);
					
					std::ofstream buildNameFile;
					buildNameFile.open("name.txt");
					buildNameFile << nameOfUser << std::endl;
					buildNameFile.close();
				}
			}
			else
			{
				std::cout << "You need to enter either 'yes' or 'no'" << std::endl;
			}
		} while (confirmReset != "yes" && confirmReset != "no");

	}
	else
	{
		std::cout << "I don't see your name in our files.\n" ;
		helloFunction(&nameOfUser);
		
		std::ofstream buildNameFile;
		buildNameFile.open("name.txt");
		buildNameFile << nameOfUser << std::endl;
		buildNameFile.close();
	}

	std::cout << std::endl << "Would you like to enter more info and test Classes? (yes/no)" << std::endl;
	getline(std::cin, continuePrompt);
	do
	{
		if (continuePrompt == "no")
		{
			std::cout << "Goodbye!" << std::endl;
		}
		else if (continuePrompt == "yes")
		{
			std::cout << "Let's set you up" << std::endl;
			std::cout << "How old are you?" << std::endl;
			std::cin >> ageOfUser;
			std::cout << "What is your gender?" << std::endl;
			std::cin.clear();
			std::cin.ignore();
			getline(std::cin, genderOfUser);
			Person person(nameOfUser, ageOfUser, genderOfUser);
			std::ofstream buildNameFile;
			buildNameFile.open("name.txt", std::ios_base::app);
			buildNameFile << person.getUserAge() << std::endl;
			buildNameFile << person.getUserGender() << std::endl;
			buildNameFile.close();
			std::cout << "Thanks! All done - " << std::endl;
		}
		else
		{
			std::cout << "You need to enter either 'yes' or 'no'" << std::endl;
		}
	} while (continuePrompt != "yes" && continuePrompt != "no");
}

void helloFunction(std::string* nameOfUser)
{
	std::string confirmUserName;

	do
	{
		std::cout << "What's your name?" << std::endl;
		getline(std::cin, *nameOfUser);
		std::cout << std::endl << "Your name is " << *nameOfUser << "? (yes or no)" << std::endl;
		getline(std::cin, confirmUserName);

		if (confirmUserName == "yes")
		{
			std::cout << "Hello World, " << *nameOfUser << std::endl;
		}
		else if (confirmUserName == "no")
		{
			std::cout << std::endl << "You must have entered it wrong, let's try again." << std::endl;
		}
		else
		{
			std::cout << std::endl << "You didn't answer yes or no, so now you have to do it again." << std::endl;
		}
	} while (confirmUserName != "yes");
}