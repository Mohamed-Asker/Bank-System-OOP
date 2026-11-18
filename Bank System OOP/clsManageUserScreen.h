#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUsersListScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"
#include "../../Input Validate Library/Input Validate Library/clsInputValidate.h"
#include "../../Utility Library/Utility Library/clsUtil.h"



class clsManageUserScreen : protected clsScreen
{
private:
	//Enums
	enum enUserMenuOptions
	{
		uListUser = 1,
		uAddNewUser = 2,
		uDeleteUser = 3,
		uUpdateUser = 4,
		uFindUser = 5,
		uMainMenu = 6
	};


	//Private Methods:
    //Method(1):
	static void _ShowManageUserMenu();
	//Method(2):
	static bool _PerformUserMenuOption(enUserMenuOptions UserChoose, const std::string& FileName, const std::string& delimiter);
	//Method(3):
	static enUserMenuOptions _ReadUserMenuOption();
	//Method(4):
	static void _ShowUsersListScreen(const std::string& FileName, const std::string& delimiter);
	//Method(5):
	static void _ShowAddNewUserScreen(const std::string& FileName, const std::string& delimiter);
	//Method(6):
	static void _ShowDeleteUserScreen(const std::string& FileName, const std::string& delimiter);
	//Method(7):
	static void _ShowUpdateUserScreen(const std::string& FileName, const std::string& delimiter);
	//Method(8):
	static void _ShowFindUserScreen(const std::string& FileName, const std::string& delimiter);

public:
	//Public Methods:
	//Method(1):
	static void RunUserMenuScreen(const std::string& FileName, const std::string& delimiter);

};

