#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "Global.h"
#include "../../Utility Library/Utility Library/clsUtil.h"


class clsRegisterLoginScreen : protected clsScreen
{
private:
	//Private Methods:
	//Method(1):
	static void _PrintHeaderOfRegisterLoginScreen();
	//Method(2):
	static void _PrintLoginRegisterRecord(clsUser::stLoginRegisterRecord& LoginRegister);
public:
	//Public Methods:
	//Method(1):
	static void ShowRegisterLoginScreen(const std::string& FileName, const std::string& delimiter);
};

