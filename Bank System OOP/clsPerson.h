#pragma once
#include <iostream>
#include "InterfaceCommunication.h"


class clsPerson : public InterfaceCommunication
{
private:
	//Date Members.
	std::string _FirstName;
	std::string _LastName;
	std::string _Email;
	std::string _Phone;

public:
	//Constructor.
	clsPerson(const std::string& FirstName, const std::string& LastName, const std::string& Email, const std::string& Phone);
	clsPerson();

	//Setters.
	void setFirstName(const std::string& FirstName);
	void setLastName(const std::string& LastName);
	void setEmail(const std::string& Email);
	void setPhone(const std::string& Phone);

	//Getters.
	std::string getFirstName();
	std::string getLastName();
	std::string getEmail();
	std::string getPhoen();

	//Properties.
	__declspec(property(get = getFirstName, put = setFirstName)) std::string FirstName;
	__declspec(property(get = getLastName, put = setLastName))std::string LastName;
	__declspec(property(get = getEmail, put = setEmail))std::string Email;
	__declspec(property(get = getPhoen, put = setPhone))std::string Phone;

	//Members Methods.
	//Method (1):
	std::string FullName();
	//Method (2):
	virtual void PrintInfo();
	//Method (3):
	void SendEmail(const std::string& Title, const std::string& Body);
	//Method (4):
	void SendFax(const std::string& Title, const std::string& Body);
	//Method (5):
	void SendSMS(const std::string& Title, const std::string& Body);
};