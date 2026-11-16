#pragma once
#include <iostream>
#include "clsScreen.h"


class clsTransactionsScreen : protected clsScreen
{
public: 

	//Public Methods:
	//Method(1):
	static void ShowTransactionsMenuScreen(const std::string& FileName, const std::string& delimiter);
};

