#include "clsCurrenciesListScreen.h"


//Private Methods.
//Method(1):
void clsCurrenciesListScreen::_PrintHeaderOfCurrenciesListScreen()
{
	std::cout << std::string(120, '=');
	std::cout << std::setw(40) << std::left << "Country";
	std::cout << std::setw(15) << std::left << "Code";
	std::cout << std::setw(45) << std::left << "Currency Name";
	std::cout << std::setw(20) << std::left << "Rate/(1$)";
	std::cout << std::string(120, '=');
}
//Method(2):
void clsCurrenciesListScreen::_PrintCurrencyInfo(clsCurrency& currency)
{
	std::cout << std::setw(40) << std::left << currency.Country();
	std::cout << std::setw(15) << std::left << currency.CurrencyCode();
	std::cout << std::setw(45) << std::left << currency.CurrencyName();
	std::cout << std::setw(20) << std::left << currency.Rate;
}

//Public Methods.
//Method(1):
void clsCurrenciesListScreen::ShowCurrenciesListScreen()
{
	std::vector <clsCurrency> vCurrencies = clsCurrency::CurrencyList();
	short NumberOfCurrencies = vCurrencies.size();

	clsScreen::_DrawScreenHeader("CURRENCIES LIST SCREEN", "(" + std::to_string(NumberOfCurrencies) + ") Currency", 38);
	_PrintHeaderOfCurrenciesListScreen();

	if (NumberOfCurrencies == 0)
	{
		std::cout << std::setw(77) << std::right << "No Currencies Available In the System!\n";
		std::cout << std::string(120, '=');
	}
	else
	{
		short counter = 0;
		for (clsCurrency& tempCurrency : vCurrencies)
		{
			counter++;
			_PrintCurrencyInfo(tempCurrency);
			if (counter != 0)
				std::cout << std::string(120, '-');
			else
				std::cout << std::string(120, '=');
		}
	}
}