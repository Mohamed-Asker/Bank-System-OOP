#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsClientScreenList.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUserScreen.h"
#include "../../Utility Library/Utility Library/clsUtil.h"
#include "../../Input Validate Library/Input Validate Library/clsInputValidate.h"


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
	static void _ShowClientListScreen(const std::string& FileName, const std::string& delimiter);
	//Method(2);
	static void _ShowAddNewClientScreen(const std::string& FileName, const std::string& delimiter);
	//Method(3);
	static void _ShowDeleteClientScreen(const std::string& FileName, const std::string& delimiter);
	//Method(4);
	static void _ShowUpdateClientScreen(const std::string& FileName, const std::string& delimiter);
	//Method(5);
	static void _ShowFindClientScreen(const std::string& FileName, const std::string& delimiter);
	//Method(6);
	static void _ShowTransactionScreen(const std::string& FileName, const std::string& delimiter);
	//Method(7);
	static void _ShowManageUserScreen(const std::string& FileName, const std::string& delimiter);
	//Method(8);
	static void _ShowMainMenu();
	//Method(9);
	static enMainMenuOptions _ReadMainMenuOption();
	//Method(10);
	static bool _PerformMainMenuOprtion(enMainMenuOptions UserChoose,const std::string& ClientsFileName, const std::string& UsersFileName,const std::string& delimiter);

public:

	//Public Methods:
    //Method(1);
	static void RunMainMenu(const std::string& ClientsFileName, const std::string& UserFileName, const std::string& delimiter);
	

};

