#include "clsTransactionsScreen.h"



//Private Methods:
//Method(1):
void clsTransactionsScreen::_ShowTransactionsMenuScreen()
{
	std::cout << "[1] Deposit.";
	std::cout << "\n[2] Withdraw.";
	std::cout << "\n[3] Total Balance.";
	std::cout << "\n[4] Main Menue.";
	std::cout << "\n----------------------------------------\n";
}
//Method(2):
clsTransactionsScreen::enTransactionsMenuOptions clsTransactionsScreen::_ReadTransactionsMenuOptions(const std::string& msg, short from, short to)
{
	return  enTransactionsMenuOptions(clsInputValidate::ReadShortNumberBetween(msg, from, to));
}
//Method(3):
bool clsTransactionsScreen::_PerformTransactionMenuOption(enTransactionsMenuOptions UserChoose,const std::string& FileName, const std::string& delimiter)
{
	switch (UserChoose)
	{
	case enTransactionsMenuOptions::tDeposit:
		_ShowDepositScreen(FileName, delimiter);
		clsUtil::PressAnyKey("Press any key to go back to transaction menu");
		return true;

	case enTransactionsMenuOptions::tWithdraw:
		_ShowWithdrawScreen(FileName, delimiter);
		clsUtil::PressAnyKey("Press any key to go back to transaction menu");
		return true;

	case enTransactionsMenuOptions::tTotalBalance:
		_ShowTotalBalanceScreen(FileName, delimiter);
		clsUtil::PressAnyKey("Press any key to go back to transaction menu");
		return true;

	case enTransactionsMenuOptions::tMainMenu:
		return false;
	}
}
//Method(4):
void clsTransactionsScreen::_ShowDepositScreen(const std::string& FileName, const std::string& delimiter)
{
	clsUtil::ResetScreen();
	clsDepositScreen::_ShowDepositScreen(FileName, delimiter);
}
//Method(5):
void clsTransactionsScreen::_ShowWithdrawScreen(const std::string& FileName, const std::string& delimiter)
{
	clsUtil::ResetScreen();
	clsWithDrawScreen::ShowWithdrawScreen(FileName, delimiter);
}
//Method(6):
void clsTransactionsScreen::_ShowTotalBalanceScreen(const std::string& FileName, const std::string& delimiter)
{
	clsUtil::ResetScreen();
	clsTotalBalaceScreen::ShowTotalBalaceScreen(FileName, delimiter);
}


//Public Methods:
//Method(1):
void clsTransactionsScreen::RunTransactionsMenu(const std::string& FileName, const std::string& delimiter)
{
	bool GoMainMenu = true;
	do
	{
		clsUtil::ResetScreen();
		clsScreen::_DrawScreenHeader("TRANSACTIONS SCREEN");
		_ShowTransactionsMenuScreen();
		GoMainMenu = _PerformTransactionMenuOption(_ReadTransactionsMenuOptions("Enter transaction type from 1 to 4", 1, 4), FileName, delimiter);
	} while (GoMainMenu);
}