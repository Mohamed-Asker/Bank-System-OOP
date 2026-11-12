#include <iostream>
#include "clsPerson.h"



//Constructor.
clsPerson::clsPerson(const std::string& FirstName, const std::string& LastName, const std::string& Email, const std::string& Phone) : _FirstName(FirstName), _LastName(LastName), _Email(Email), _Phone(Phone) {};


//Setters.
void clsPerson::setFirstName(const std::string& FirstName)
{
	_FirstName = FirstName;
}
void clsPerson::setLastName(const std::string& LastName)
{
	_LastName = LastName;
}
void clsPerson::setEmail(const std::string& Email)
{
	_Email = Email;
}
void clsPerson::setPhone(const std::string& Phone)
{
	_Phone = Phone;
}

//Getters.
std::string clsPerson::getFirstName()
{
	return _FirstName;
}
std::string clsPerson::getLastName()
{
	return _LastName;
}
std::string clsPerson::getEmail()
{
	return _Email;
}
std::string clsPerson::getPhoen()
{
	return _Phone;
}


//Members Methods.
//Method (1):
std::string clsPerson::FullName()
{
	return _FirstName + " " + _LastName;
}

//Method (2):
void clsPerson::PrintInfo()
{
	std::cout << "          Person Info";
	std::cout << "\n---------------------------";
	std::cout << "\nFirst Name: " << _FirstName;
	std::cout << "\nLast Name : " << _LastName;
	std::cout << "\nFull Name : " << FullName();
	std::cout << "\nEmail     : " << _Email;
	std::cout << "\nPhone     : " << _Phone;
	std::cout << "\n---------------------------";
}