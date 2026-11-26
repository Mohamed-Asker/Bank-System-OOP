#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include "clsScreen.h"
#include "clsCurrency.h"



class clsCurrenciesListScreen : protected clsScreen
{

private:
	//Private Methods.
	//Method(1):
	static void _PrintHeaderOfCurrenciesListScreen();
	//Method(2):
	static void _PrintCurrencyInfo(clsCurrency& currency);

public:

	//Public Methods.
	//Method(1):
	static void ShowCurrenciesListScreen();

};

