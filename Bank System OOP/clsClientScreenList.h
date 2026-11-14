#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "../../Utility Library/Utility Library/clsUtil.h"


class clsClientScreenList : public clsScreen
{
private:
	//Private Methods:
	//Method(1):
	static void _PrintHeaderOfShowClientList();
	//Method(2):
	static void _PrintClientInfo(clsBankClient& client);


public:
	//Public Methods:
	//Method(1):
	static void ShowClientListScreen(const std::string& FileName, const std::string& delimiter);
};

