#pragma once
#include <iostream>
#include <string>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "../../Input Validate Library/Input Validate Library/clsInputValidate.h"
#include "../../Utility Library/Utility Library/clsUtil.h"

class clsUpdateCurrency : protected clsScreen
{
private:
	//Private Methods.
	//Mehtod(1):
	static void _PrintCurrencyDetails(clsCurrency& currency);
public:
	//Public Methods.
	//Method(1):
	static void ShowUpdateCurrencyScreen();
};

