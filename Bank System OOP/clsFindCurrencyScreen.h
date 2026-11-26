#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "../../Input Validate Library/Input Validate Library/clsInputValidate.h"

class clsFindCurrencyScreen :protected clsScreen
{
private:
	//Private Methods.
	//Method(1):
	static void _PrintCurrencyCard(clsCurrency& currency);

public:
	//Public Methods.
	//Method(1):
	static void ShowFindCurrencyScreen();
};

