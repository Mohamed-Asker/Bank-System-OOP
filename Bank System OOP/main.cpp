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
	std::cout << "|" << std::left << std::setw(20) << "Account Number";
	std::cout << "|" << std::left << std::setw(15) << "Pin Code";
	std::cout << "|" << std::left << std::setw(40) << "Client Name";
	std::cout << "|" << std::left << std::setw(19) << "Phone";
	std::cout << "|" << std::left << std::setw(20) << "Balance";
	std::cout << "\n------------------------------------------------------------------------------------------------------------------------\n";
}

void PrintClientCard(clsBankClient& client)
{
	std::cout << "|" << std::left << std::setw(20) << client.AccountNumber();
	std::cout << "|" << std::left << std::setw(15) << client.PinCode;
	std::cout << "|" << std::left << std::setw(40) << client.FullName();
	std::cout << "|" << std::left << std::setw(19) << client.Phone;
	std::cout << "|" << std::left << std::setw(20) << client.Balance;
}

void ShowClientsList(std::string FileName, std::string delimiter)
{
	std::vector <clsBankClient> vClients = clsBankClient::getClientsList(FileName, delimiter);
	int NumberOfClients = vClients.size();
	PrintHeaderOfClientsList(NumberOfClients);
	if (NumberOfClients == 0)
		std::cout << std::right << std::setw(75) << "No Clients Available In the System!\n";
	else
		for (clsBankClient& tempClient : vClients)
		{
			PrintClientCard(tempClient);
			std::cout << std::endl;
		}
	std::cout << "------------------------------------------------------------------------------------------------------------------------\n";
}

std::string FileClient = "ClientDate.txt";
int main()
{
	
	ShowClientsList(FileClient, "#//#");

	system("pause>0");
	return 0;
}