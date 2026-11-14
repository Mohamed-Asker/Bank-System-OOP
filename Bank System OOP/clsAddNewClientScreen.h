#pragma once
#include <iostream>
#include <string>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "../../Input Validate Library/Input Validate Library/clsInputValidate.h"
#include "../../Utility Library/Utility Library/clsUtil.h"

class clsAddNewClientScreen : protected clsScreen 
{
private:
	//Private Methods:
	//Method(1):
	static void _PrintClientInfo(clsBankClient& client);
	//Method(2):
	static void _PrintSaveResult(clsBankClient& client, const std::string& FileName, const std::string& delimiter);
	//Method (3):
	static void _ReadClientInfo(clsBankClient& client);
public:

	//public Methods:
	//Method(1):
	static void ShowAddNewClientScreen(const std::string& FileName, const std::string& delimiter);
};

