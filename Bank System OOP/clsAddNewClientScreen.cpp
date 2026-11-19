#include "clsAddNewClientScreen.h"


//Private Methods:
//Method(1):
void clsAddNewClientScreen::_PrintClientInfo(clsBankClient& client)
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
//Method(2):
void clsAddNewClientScreen::_PrintSaveResult(clsBankClient& client, const std::string& FileName, const std::string& delimiter)
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
//Method (3):
void clsAddNewClientScreen::_ReadClientInfo(clsBankClient& client)
{
	client.FirstName = clsInputValidate::ReadString("First Name");
	client.LastName = clsInputValidate::ReadString("Last Name ");
	client.PinCode = clsInputValidate::ReadString("Pin Code  ");
	client.Email = clsInputValidate::ReadString("Email     ");
	client.Phone = clsInputValidate::ReadString("Phone     ");
	client.Balance = clsInputValidate::ReadPostiveDblNumber("Account Balance");
}

//public Methods:
//Method(1):
void clsAddNewClientScreen::ShowAddNewClientScreen(const std::string& FileName, const std::string& delimiter)
{
	if (!::CurrentUser.HasPermission(clsUser::pAddNewClient))
	{
		clsScreen::_DrawScreenHeader("Access Denied! Please Conact Your admin.");
		return;
	}

	clsScreen::_DrawScreenHeader("ADD NEW CLIENT SCREEN");
	std::string accNumber;
	do
	{
		int tempAccNumber = clsInputValidate::ReadPostiveIntNumber("Account Number", "Enter a valid account number.\n");
		accNumber = std::to_string(tempAccNumber);
		if (!clsBankClient::isClientExist(accNumber, FileName, delimiter))
		{
			clsUtil::ResetScreen();
			clsScreen::_DrawScreenHeader("ADD NEW CLIENT SCREEN");
			break;
		}
		std::cout << "Account Number Is Already Used, Enter another one\n\n";
	} while (true);

	clsBankClient client = clsBankClient::getAddNewClientObj(accNumber);
	_ReadClientInfo(client);
	_PrintSaveResult(client, FileName, delimiter);
}