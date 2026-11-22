#pragma once
#include <iostream>
#include <string>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "../../Utility Library/Utility Library/clsUtil.h"

class clsTransferScreen : protected clsScreen
{
private:
	//Private Methoes:
	//Method(1):
	static std::string _ReadAccountNumber(const std::string msg, const std::string& FileName, const std::string& delimiter, clsBankClient& client);
	//Method(2):
	static void _PrintClientInfoTransferScreen(clsBankClient& client);
	//Method(3):
	static double _ReadTransferAmount(const double& Balance);
public:
	//Public Methods:
	//Method(1):
	static void ShowTransferScreen(const std::string& FileName, const std::string& delimiter);
};

