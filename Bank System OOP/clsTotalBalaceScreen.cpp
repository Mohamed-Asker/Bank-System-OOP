#include "clsTotalBalaceScreen.h"




//Private Methods:
//Method(1):
void clsTotalBalaceScreen::_PrintHeaderOfTotalBalanceScreen(short NumberOfClients)
{
	std::cout << "========================================================================================================================\n";
	std::cout << std::left << std::setw(38) << "Account Number";
	std::cout << std::left << std::setw(46) << "Client Name";
	std::cout << std::left << std::setw(30) << "Client Balance";
	std::cout << "\n========================================================================================================================\n";
}
//Method(2):
void clsTotalBalaceScreen::_PrintClientInfoTotalBalance(clsBankClient& client)
{
	std::cout << std::left << std::setw(38) << client.AccountNumber();
	std::cout << std::left << std::setw(46) << client.FullName();
	std::cout << std::left << std::setw(30) << client.Balance;
}


//Public Methods:
//Method(1):
void clsTotalBalaceScreen::ShowTotalBalaceScreen(const std::string& FileName, const std::string& delimiter)
{
	std::vector <clsBankClient> vClients = clsBankClient::ClientsList(FileName, delimiter);
	short NumberOfClients = vClients.size();
	clsScreen::_DrawScreenHeader("TOTAL BALANCE SCREEN", "(" + std::to_string(NumberOfClients) + ") CLINET" + clsUtil::FormWord(NumberOfClients, false), 40);
	_PrintHeaderOfTotalBalanceScreen(NumberOfClients);
	std::string Separator = std::string(120, '=');
	if (NumberOfClients == 0)
	{
		std::cout << std::right << std::setw(77) << "No Clients Available In the System!\n";
		std::cout << Separator;
	}
	else
	{
		short counter = 0;
		for (clsBankClient& tempClient : vClients)
		{
			counter++;
			_PrintClientInfoTotalBalance(tempClient);
			std::cout << std::endl;
			if (counter != NumberOfClients)
				std::cout << "------------------------------------------------------------------------------------------------------------------------\n";
			else
				std::cout << Separator;
		}
	}
	double TotalBalance = clsBankClient::TotalBalance(FileName, delimiter);
	std::cout << "Total Balance is [" << TotalBalance << "]\n";
	std::cout << clsUtil::NumberToText(int(TotalBalance)) << "\n";
}