#include "clsFindClientScreen.h"



//Private Methods:
//Method(1):
void clsFindClientScreen::_PrintClientInfo(clsBankClient& client)
{
	std::cout << "-------------------------------";
	std::cout << "\n           Client Info";
	std::cout << "\n-------------------------------";
	std::cout << "\nAccount Number : " << client.AccountNumber();
	std::cout << "\nPin Code       : " << client.PinCode;
	std::cout << "\nFirst Name     : " << client.FirstName;
	std::cout << "\nLast Name      : " << client.LastName;
	std::cout << "\nFull Name      : " << client.FullName();
	std::cout << "\nEmail          : " << client.Email;
	std::cout << "\nPhone          : " << client.Phone;
	std::cout << "\nAccount Balance: " << client.Balance;
	std::cout << "\n-------------------------------\n";
}


//Public Methods:
//Method(1):
void clsFindClientScreen::ShowFindClientScreen(const std::string& FileName, const std::string& delimiter)
{
	std::string accNumber;
	clsBankClient client;
	clsScreen::_DrawScreenHeader("FIND CLIENT SCREEN");
	int tempAccNumber = clsInputValidate::ReadPostiveIntNumber("Account Number", "Invalid Input\n\n");
	accNumber = std::to_string(tempAccNumber);

	if (clsBankClient::isClientExist(accNumber, FileName, delimiter, &client))
		_PrintClientInfo(client);
	else
		std::cout << "This account number not found\n";
}