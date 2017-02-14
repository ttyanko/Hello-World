/************************************************************************************************
* File : Person.h																				*
* Author : Tyler Yanko																			*
* Last Revision : 2/13/2017																		*
* Description : Very basic class to handle adding information about a person				    *
************************************************************************************************/
#include <iostream>
#include <string>

#pragma once
#ifndef PERSON_H
#define PERSON_H
#endif // !PERSON_H

class Person
{
private:
	std::string userName;
	int userAge;
	std::string userGender;

public:
	Person(std::string name, int age, std::string gender);
	int getUserAge();
	std::string getUserName();
	std::string getUserGender();
	~Person();
};

