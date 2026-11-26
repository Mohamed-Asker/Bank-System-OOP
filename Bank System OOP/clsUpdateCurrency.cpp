#include "clsUpdateCurrency.h"


//Private Methods.
//Mehtod(1):
void clsUpdateCurrency::_PrintCurrencyDetails(clsCurrency& currency)
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
void clsUpdateCurrency::ShowUpdateCurrencyScreen()
{ 
	clsScreen::_DrawScreenHeader("UPDATE CURRENCY SCREEN");
	std::string CurrencyCode;
	clsCurrency currency;

	std::cout << "Currency Code: ";
	std::getline(std::cin >> std::ws, CurrencyCode);

	if (clsCurrency::isCurrencyCodeExist(CurrencyCode,&currency))
	{
		_PrintCurrencyDetails(currency);
		if (clsUtil::ConfirmAction("Are you sure you want to update the rate of this currency"))
		{
			currency.Rate = clsInputValidate::ReadPostiveDblNumber("New Rate");
			_PrintCurrencyDetails(currency);
			std::cout << "Currency update successfully :-)\n";
		}
	}
	else
		std::cout << "Currency code not found!\n";
}