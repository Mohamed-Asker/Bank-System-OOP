#pragma once
#include <iostream>
#include <string>
#include "clsScreen.h"
#include "clsUser.h"


class clsFindUserScreen : protected clsScreen
{
private:
	//Private Methods:
    //Method(1):
	static void _PrintUserInfoFindUserScreen(clsUser& user);
public:
	//Public Methods:
	//Method(1)
	static void ShowFindUserScreen(const std::string& FileName, const std::string& delimiter);
};

