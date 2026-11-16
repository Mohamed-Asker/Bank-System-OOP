#pragma once
#include <iostream>
#include <string>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "../../Input Validate Library/Input Validate Library/clsInputValidate.h"
#include "../../Utility Library/Utility Library/clsUtil.h"



class clsDepositScreen : protected clsScreen
{
private:
	//Private Methods:
	//Method(1):
	static void _PrintClientDepositInfo(clsBankClient& client);
	//Method(2):
	static void _Deposit(clsBankClient& client,double Amount);
	//Method(3):
	static void _PrintDepsoitResult(double balance, bool Result);


public:

	//Public Methods:
	//Method(1):
	static void _ShowDepositScreen(const std::string& FileName, const std::string& delimiter);

};

