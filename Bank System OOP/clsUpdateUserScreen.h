#pragma once
#include <iostream>
#include <string>
#include "clsScreen.h"
#include "clsUser.h"
#include "../../Input Validate Library/Input Validate Library/clsInputValidate.h"
#include "../../Utility Library/Utility Library/clsUtil.h"



class clsUpdateUserScreen : protected clsScreen
{
private:
	//Private Methods:
	//Method(1):
	static void _PrintUserInfoUpdateScreen(clsUser& user);
	//Method(2):
	static void _ReadUserInfoUpdateScreen(clsUser& user);
	//Method(3):
	static short _ReadPermissionsUpdateScreen();
	//Method(4):
	static void _SaveResultUpdateScreen(clsUser& user, const std::string& FileName, const std::string& delimiter);

public:
	//Public Methods:
	//Method(1):
	static void ShowUpdateUserScreen(const std::string& FileName, const std::string& delimiter);
};

