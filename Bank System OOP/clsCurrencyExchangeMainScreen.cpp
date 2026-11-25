#include "clsCurrencyExchangeMainScreen.h"


//Private Methods.
//Method(1):
void clsCurrencyExchangeMainScreen::_ShowCurrencyExchangeMenu()
{
	std::cout << "[1] List Currencies.";
	std::cout << "\n[2] Find Currency.";
	std::cout << "\n[3] Update Currency.";
	std::cout << "\n[4] Currency Calculator.";
	std::cout << "\n[5] Main Menu.";
	std::cout << "\n------------------------------------------\n";
}
//Method(2):
clsCurrencyExchangeMainScreen::enCurrencyMenuOptions clsCurrencyExchangeMainScreen::_ReadCurrencyMenuOption()
{
	return static_cast<enCurrencyMenuOptions>(clsInputValidate::ReadShortNumberBetween("Choose Whar do you want to do[1,5]", 1, 5));
}
//Method(3):
bool clsCurrencyExchangeMainScreen::_PerformCurrenciesMainMenueOptions(enCurrencyMenuOptions UserChoose)
{
	switch (UserChoose)
	{
	case enCurrencyMenuOptions::cListCurrency:
		_ShowListCurrenciesScreen();
		clsUtil::PressAnyKey("Press any key to go back to Currenies menu");
		return false;

	case enCurrencyMenuOptions::cFindCurrency:
		_ShowFindCurrencyScreen();
		clsUtil::PressAnyKey("Press any key to go back to Currenies menu");
		return false;

	case enCurrencyMenuOptions::cUpdateRate:
		_ShowUpdateRateScreen();
		clsUtil::PressAnyKey("Press any key to go back to Currenies menu");
		return false;

	case enCurrencyMenuOptions::cCurrencyCalculator:
		_ShowCurrencyCalculatorScreen();
		clsUtil::PressAnyKey("Press any key to go back to Currenies menu");
		return false;

	case enCurrencyMenuOptions::cMainMenu:
		return true;

	default:
		return false;
	}
}
//Method(4):
void clsCurrencyExchangeMainScreen::_ShowListCurrenciesScreen()
{
	system("cls");
	std::cout << "List Currencies Screen Will Be Here\n";
}
//Method(5):
void clsCurrencyExchangeMainScreen::_ShowFindCurrencyScreen()
{
	system("cls");
	std::cout << "Find Currency Screen Will Be Here\n";
}
//Method(6):
void clsCurrencyExchangeMainScreen::_ShowUpdateRateScreen()
{
	system("cls");
	std::cout << "Update Rate Screen Will Be Here\n";
}
//Method(7):
void clsCurrencyExchangeMainScreen::_ShowCurrencyCalculatorScreen()
{
	system("cls");
	std::cout << "Currency Calculator Screen Will Be Here\n";
}



//Public Methods.
//Method(1):
void clsCurrencyExchangeMainScreen::RunCurrencyExchangeMainScreen()
{
	bool GoToMainMenu;
	do
	{
		system("cls");
		clsScreen::_DrawScreenHeader("CURRENCY EXCANGE MENU SCREEN");
		_ShowCurrencyExchangeMenu();
		GoToMainMenu = _PerformCurrenciesMainMenueOptions(_ReadCurrencyMenuOption());
	} while (!GoToMainMenu);
}