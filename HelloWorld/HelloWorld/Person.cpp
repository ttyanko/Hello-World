/************************************************************************************************
* File : Person.cpp																				*
* Author : Tyler Yanko																			*
* Last Revision : 2/13/2017																		*
* Description : Very basic class to handle adding information about a person				    *
************************************************************************************************/

#include "Person.h"
#include <iostream>
#include <string>

Person::Person(std::string name, int age, std::string gender) : userName(name), userAge(age), userGender(gender) {}

std::string Person::getUserName()
{
	return userName;
}

int Person::getUserAge()
{
	return userAge;
}

std::string Person::getUserGender()
{
	return userGender;
}

Person::~Person()
{
	/* Member variables aren't pointers should default destructor should be fine
	 Here incase member variables change and require updating this. */
}