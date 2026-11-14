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


	//Priavte Methods:
	//Method(1);
	static void _ShowClientListScreen(const std::string& FileNam, const std::string& delimiter);
	//Method(2);
	static void _ShowAddNewClientScreen(const std::string& FileNam, const std::string& delimiter);
	//Method(3);
	static void _ShowDeleteClientScreen(const std::string& FileNam, const std::string& delimiter);
	//Method(4);
	static void _ShowUpdateClientScreen(const std::string& FileNam, const std::string& delimiter);
	//Method(5);
	static void _ShowFindClientScreen(const std::string& FileNam, const std::string& delimiter);
	//Method(6);
	static void _ShowTransactionScreen(const std::string& FileNam, const std::string& delimiter);
	//Method(7);
	static void _ShowManageUserScreen(const std::string& FileNam, const std::string& delimiter);

public:


	//Public Methods:
    //Method(1);
	static void ShowMainMenu(const std::string& FileName, const std::string& delimiter);
	//Method(2);
	static enMainMenuOptions ReadMainMenuOption(short from, short to, const std::string& msg = "Choose what do you want to do");
	//Method(3);
	static bool PerformMainMenuOprtion(enMainMenuOptions UserChoose,const std::string& FileName, const std::string& delimiter);
};

