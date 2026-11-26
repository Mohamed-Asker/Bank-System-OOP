#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "../../Input Validate Library/Input Validate Library/clsInputValidate.h"
#include "../../Utility Library/Utility Library/clsUtil.h"



class clsCurrencyExchangeMainScreen : protected clsScreen
{
private:
	//Enums
	enum enCurrencyMenuOptions
	{
		cListCurrency = 1,
		cFindCurrency = 2,
		cUpdateRate = 3,
		cCurrencyCalculator = 4,
		cMainMenu = 5
	};
	//Private Methods.
	//Method(1):
	static void _ShowCurrencyExchangeMenu();
	//Method(2):
	static enCurrencyMenuOptions _ReadCurrencyMenuOption();
	//Method(3):
	static bool _PerformCurrenciesMainMenueOptions(enCurrencyMenuOptions UserChoose);
	//Method(4):
	static void _ShowListCurrenciesScreen();
	//Method(5):
	static void _ShowFindCurrencyScreen();
	//Method(6):
	static void _ShowUpdateRateScreen();
	//Method(7):
	static void _ShowCurrencyCalculatorScreen();
	

public:
	//Public Methods.
	//Method(1):
	static void RunCurrencyExchangeMainScreen();
};