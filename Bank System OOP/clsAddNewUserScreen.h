#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "../../Input Validate Library/Input Validate Library/clsInputValidate.h"
#include "../../Utility Library/Utility Library/clsUtil.h"


class clsAddNewUserScreen : protected clsScreen
{

private:
	//Private Methods:
	//Method(1):
	static void _ReadUserInfoAddNew(clsUser& user);
	//Method(2):
	static short _ReadPermissions();
	//Method(3):
	static void _PrintUserInfoAddNew(clsUser& User);
	//Method(4):
	static void _PrintSaveResult(clsUser& user, const std::string& FileName, const std::string& delimiter);
public:
	//Public Methods:
	//Method(1):
	static void _ShowAddNewUserScreen(const std::string& FileName, const std::string& delimiter);
};

