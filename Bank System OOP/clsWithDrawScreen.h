#pragma once
#include <iostream>
#include <string>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "../../Input Validate Library/Input Validate Library/clsInputValidate.h"
#include "../../Utility Library/Utility Library/clsUtil.h"


class clsWithDrawScreen : protected clsScreen
{

private:
	//Private Methods:
    //Method(1):
	static void _PrintClientWithdrawInfo(clsBankClient& client);
	//Method(2):
	static double _ReadWithdrawAmount(double ClientBalance);
	//Method(3):
	static void _PrintWithdrawResult(double balance, bool Result);

public:

	//Public Menthods:
	//Menthod(1):
	static void ShowWithdrawScreen(const std::string& FileName, const std::string& delimiter);
};

