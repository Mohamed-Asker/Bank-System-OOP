#pragma once
#include <iostream>
#include "clsScreen.h"


class clsMainScreen : protected clsScreen
{
private:
	//Enums:
	enum enMainMenuOptions
	{
		ShowClientList = 1,
		AddNewClient = 2,
		DeleteClient = 3,
		UpdateClient = 4,
		FindClient = 5,
		Transactions = 6,
		ManageUsers = 7,
		Exit = 8
	};

public:


	//Public Methods:
    //Method(1);
	static void ShowMainMenu(const std::string& FileName, const std::string& delimiter);
	//Method(2);
	static enMainMenuOptions ReadMainMenuOption(short from, short to, const std::string& msg = "Choose whar do you want to do");
};

