#include "clsTransactionsScreen.h"


//Public Methods:
//Method(1):
void clsTransactionsScreen::ShowTransactionsMenuScreen(const std::string& FileName, const std::string& delimiter)
{
	clsScreen::_DrawScreenHeader("TRANSACTIONS SCREEN");
	std::cout << "[1] Deposit.";
	std::cout << "\n[2] Withdraw.";
	std::cout << "\n[3] Total Balance.";
	std::cout << "\n[4] Main Menue.";
	std::cout << "\n----------------------------------------\n";
}