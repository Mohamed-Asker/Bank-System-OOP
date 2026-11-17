#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "../../Utility Library/Utility Library/clsUtil.h"


class clsTotalBalaceScreen : protected clsScreen
{
private:
	//Private Methods:
	//Method(1):
	static void _PrintHeaderOfTotalBalanceScreen(short NumberOfClients);
	//Method(2):
	static void _PrintClientInfoTotalBalance(clsBankClient& client);

public:

	//Public Methods:
	//Method(1):
	static void ShowTotalBalaceScreen(const std::string& FileName, const std::string& delimiter);
};

