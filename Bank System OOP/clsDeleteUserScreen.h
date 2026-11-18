#pragma once
#include <iostream>
#include "clsUser.h"
#include "clsScreen.h"
#include "../../Utility Library/Utility Library/clsUtil.h"


class clsDeleteUserScreen : protected clsScreen
{
private:
	//Private Methods:
	//Method(1):
	static void _PrintUserInfoDeleteScreen(clsUser& user);

public:
	//Public Methods:
	//Method(1):
	static void ShowDeleteUserScreen(const std::string& FileName, const std::string& delimiter);
};

