#include "clsUpdateclientScreen.h"




//Private Methods:
//Method(1)
void clsUpdateclientScreen::_ReadClientInfo(clsBankClient& client)
{
	std::cout << "\nUpdating Client:-\n";
	client.FirstName = clsInputValidate::ReadString("First Name    ");
	client.LastName = clsInputValidate::ReadString("Last Name     ");
	client.PinCode = clsInputValidate::ReadString("Pin Code      ");
	client.Email = clsInputValidate::ReadString("Email         ");
	client.Phone = clsInputValidate::ReadString("Phone         ");
	client.Balance = std::stod(clsInputValidate::ReadString("Account Balance"));
}
//Method(2)
void clsUpdateclientScreen::_PrintClientInfo(clsBankClient& client)
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
//Method(3):
void clsUpdateclientScreen::_PrintSaveResult(clsBankClient& client, const std::string& FileName, const std::string& delimiter)
{
	switch (client.Save(client.AccountNumber(), FileName, delimiter))
	{
	case clsBankClient::enSaveResult::svSucceeded:
		clsUtil::ResetScreen();
		_PrintClientInfo(client);
		std::cout << "Client Add Successfully :-)\n";
		break;

	case clsBankClient::enSaveResult::svFildEmptyObject:
		clsUtil::ResetScreen();
		std::cout << "\nError account was not saved because it's Empty!\n";
		break;

	case clsBankClient::enSaveResult::svFildAccountNumberExist:
		clsUtil::ResetScreen();
		std::cout << "\nError account was not saved because account number is used!\n";
		break;
	}
}

//Public Methods:
//Method(1)
void clsUpdateclientScreen::ShowUpdateClientScreen(const std::string& FileName, const std::string& delimiter)
{
	std::string accNumber;
	clsBankClient client;
	clsScreen::_DrawScreenHeader("UPDATE CLIENT SC  REEN");
	do
	{
		int tempAccNumber = clsInputValidate::ReadPostiveIntNumber("Account Number", "Invalid Input\n\n");
		accNumber = std::to_string(tempAccNumber);
		if (clsBankClient::isClientExist(accNumber, FileName, delimiter, &client))
		{
			clsUtil::ResetScreen();
			clsScreen::_DrawScreenHeader("UPDATE CLIENT SCREEN");
			break;
		}
		std::cout << "Account number is not found, Enter another one.\n\n";
	} while (true);
	_PrintClientInfo(client);
	if (clsUtil::ConfirmAction("Are you sure you want to update this client"))
	{
		_ReadClientInfo(client);
		_PrintSaveResult(client, FileName, delimiter);
	}
	else
		std::cout << "The client has not been updated.\n";
}