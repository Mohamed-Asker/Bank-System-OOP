#include "clsFindCurrencyScreen.h"


//Private Methods.
//Method(1):
void clsFindCurrencyScreen::_PrintCurrencyCard(clsCurrency& currency)
{
	std::cout << "-----------------------------";
	std::cout << "\n       Currency Info";
	std::cout << "\n-----------------------------";
	std::cout << "\nCountry  : " << currency.Country();
	std::cout << "\nCode     : " << currency.CurrencyCode();
	std::cout << "\nName     : " << currency.CurrencyName();
	std::cout << "\nRate/(1$): " << currency.Rate;
	std::cout << "\n-----------------------------\n";
}


//Public Methods.
//Method(1):
void clsFindCurrencyScreen::ShowFindCurrencyScreen()
{
	clsScreen::_DrawScreenHeader("FIND CURRENCY SCREEN");
	short UserChoose = clsInputValidate::ReadShortNumberBetween("[1] Country\n[2] Code\nFind by", 1, 2);
	clsCurrency currency;

	if (UserChoose == 1)
	{
		std::string Country = clsInputValidate::ReadString("Country Name");
		if (clsCurrency::isCountryCurrencyExist(Country, &currency))
			_PrintCurrencyCard(currency);
		else
			std::cout << "Currency not found!\n";
	}
	else
	{
		std::string Code = clsInputValidate::ReadString("Currency Code");
		clsCurrency currency;

		if (clsCurrency::isCurrencyCodeExist(Code, &currency))
			_PrintCurrencyCard(currency);
		else
			std::cout << "Currency not found!\n";
	}

}