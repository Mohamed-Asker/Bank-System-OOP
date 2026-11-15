#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "../../Input Validate Library/Input Validate Library/clsInputValidate.h"


class clsFindClientScreen : protected clsScreen
{
private:
//Private Methods:
//Method(1):
	static void _PrintClientInfo(clsBankClient& client);

public:
	//Public Methods:
	//Method(1):
	static void ShowFindClientScreen(const std::string& FileName, const std::string& delimiter);
};

