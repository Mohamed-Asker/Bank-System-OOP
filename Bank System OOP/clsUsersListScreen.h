#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include "clsScreen.h"
#include "clsUser.h"
#include "../../Utility Library/Utility Library/clsUtil.h"


class clsUsersListScreen : protected clsScreen
{
private:
	//Private Methods:
	//Method(1):
	static void _PrintHeaderOfUsersListScreen();
	//Method(2):
	static void _PrintUserInfoListScreen(clsUser& user);

public:
	//Public Methods:
	//Method(1):
	static void ShowUsersListScreen(const std::string& FileName, const std::string& delimiter);
};