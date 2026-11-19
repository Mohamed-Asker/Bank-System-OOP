#pragma once
#include <iostream>
#include <string>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsUser.h"
#include "Global.h"
#include "../../Utility Library/Utility Library/clsUtil.h"
#include "../../Input Validate Library/Input Validate Library/clsInputValidate.h"


class clsUpdateclientScreen : protected clsScreen
{
private:
	//Private Methods:
	//Method(1)
	static void _ReadClientInfo(clsBankClient& client);
	//Method(2)
	static void _PrintClientInfo(clsBankClient& client);
	//Method(3):
	static void _PrintSaveResult(clsBankClient& client, const std::string& FileName, const std::string& delimiter);

public:
	//Public Methods:
	//Method(1)
	static void ShowUpdateClientScreen(const std::string& FileName, const std::string& delimiter);
};

