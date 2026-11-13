#include <iostream>
#include <iomanip>
#include "../../Input Validate Library/Input Validate Library/clsInputValidate.h"
#include "../../Utility Library/Utility Library/clsUtil.h"
#include "clsBankClient.h"

void PrintHeaderOfClientsList(int NumberOfClients)
{
	std::cout << "\n\n";
	std::cout << std::setw(60) << "CLIENTS LIST " << NumberOfClients << " CLIENT" << clsUtil::FormWord(NumberOfClients, false);
	std::cout << "\n------------------------------------------------------------------------------------------------------------------------\n";
	std::cout << "|" << std::left << std::setw(38) << "Account Number";
	std::cout << "|" << std::left << std::setw(38) << "Client Name";
	std::cout << "|" << std::left << std::setw(38) << "Balance";
	std::cout << "\n------------------------------------------------------------------------------------------------------------------------\n";
}

void PrintClientData(clsBankClient& client)
{
	std::cout << "|" << std::left << std::setw(38) << client.AccountNumber();
	std::cout << "|" << std::left << std::setw(38) << client.FullName();
	std::cout << "|" << std::left << std::setw(38) << client.Balance;
}

void ShowTotalBalace(std::string& FileName,const std::string& delimiter)
{
	std::vector <clsBankClient> vClients = clsBankClient::ClientsList(FileName, delimiter);
	int NumberOfClients = vClients.size();
	PrintHeaderOfClientsList(NumberOfClients);

	if (NumberOfClients == 0)
		std::cout << std::right << std::setw(75) << "No Clients Available In the System!\n";
	else
		for (clsBankClient& tempClient : vClients)
		{
			PrintClientData(tempClient);
			std::cout << std::endl;
		}
	std::cout << "------------------------------------------------------------------------------------------------------------------------\n";
	double  TotalBalance = clsBankClient::TotalBalance(FileName, delimiter);
	std::cout << "Total Balances = " << TotalBalance << "\n";
	std::cout << clsUtil::NumberToText((int)TotalBalance);
}

std::string FileClient = "ClientDate.txt";
int main()
{
	ShowTotalBalace(FileClient, "#//#");
	

	system("pause>0");
	return 0;
}