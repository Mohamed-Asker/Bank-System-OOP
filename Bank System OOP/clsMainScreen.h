#pragma once
#include <iostream>
#include "clsScreen.h"


class clsMainScreen : protected clsScreen
{
public:


	//Public Methods:
    //Method(1);
	static void ShowMainMenu(const std::string& FileName, const std::string& delimiter);
};

