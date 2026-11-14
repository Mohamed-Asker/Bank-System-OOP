#pragma once
#include <iostream>
#include <string>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "../../Input Validate Library/Input Validate Library/clsInputValidate.h"
#include "../../Utility Library/Utility Library/clsUtil.h"

class clsDeleteClientScreen : protected clsScreen
{
private:
	//Private Methods:
    //Method(1):
	static void _PrintClientInfo(clsBankClient& client);

public:

	//Public Methods:
	//Method(1):
	static void ShowDeleteClientScreen(const std::string& FileName, const std::string& delimiter);
};

