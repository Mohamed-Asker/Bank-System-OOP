#include "clsClientScreenList.h"

//Private Methods:
//Method(1):
void clsClientScreenList::_PrintHeaderOfShowClientList()
{
	std::cout << "========================================================================================================================\n";
	std::cout  << std::left << std::setw(20) << "Account Number";
	std::cout  << std::left << std::setw(15) << "Pin Code";
	std::cout  << std::left << std::setw(40) << "Client Name";
	std::cout  << std::left << std::setw(21) << "Client Phone";
	std::cout << std::left << std::setw(18) << "Account Balance";
	std::cout << "\n========================================================================================================================\n";
}
//Method(2):
void
 clsClientScreenList::_PrintClientInfo(clsBankClient& client)
{
	std::cout << std::left << std::setw(20) << client.AccountNumber();
	std::cout << std::left << std::setw(15) << client.PinCode;
	std::cout << std::left << std::setw(40) << client.FullName();
	std::cout << std::left << std::setw(21) << client.Phone;
	std::cout << std::left << std::setw(18) << client.Balance;
}

//Public Methods:
//Method(1):
void clsClientScreenList::ShowClientListScreen(const std::string& FileName, const std::string& delimiter)
{
	std::vector <clsBankClient> vClients = clsBankClient::ClientsList(FileName, delimiter);
	short NumberOfClients = vClients.size();
	clsScreen::_DrawScreenHeader("CLIENTS LIST SCREEN","(" + std::to_string(NumberOfClients) + ") CLIENT" + clsUtil::FormWord(NumberOfClients, false),38);
	_PrintHeaderOfShowClientList();

	if (NumberOfClients == 0)
		std::cout << std::right << std::setw(77) << "No Clients Available In the System!\n";
	else
	{
		short counter = 0;
		for (clsBankClient& tempClient : vClients)
		{
			counter++;
			_PrintClientInfo(tempClient);
			std::cout << std::endl;
			if (counter != NumberOfClients)
				std::cout << "------------------------------------------------------------------------------------------------------------------------\n";
			else
				std::cout << "========================================================================================================================\n";
		}
	}
}