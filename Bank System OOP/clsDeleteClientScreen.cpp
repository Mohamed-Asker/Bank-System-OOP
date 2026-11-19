#include "clsDeleteClientScreen.h"

//Private Methods:
//Method(1):
void clsDeleteClientScreen::_PrintClientInfo(clsBankClient& client)
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
void clsDeleteClientScreen::ShowDeleteClientScreen(const std::string& FileName, const std::string& delimiter)
{
	if (!::CurrentUser.HasPermission(clsUser::pDeleteClient))
	{
		clsScreen::_DrawScreenHeader("Access Denied! Please Conact Your admin.");
		return;
	}

	std::string accNumber;
	clsBankClient client;
	clsScreen::_DrawScreenHeader("DELETE CLIENT SCREEN");
	do
	{
		int tempAccNumber = clsInputValidate::ReadPostiveIntNumber("Account Number", "Invalid input\n\n");
		accNumber = std::to_string(tempAccNumber);
		if (clsBankClient::isClientExist(accNumber, FileName, delimiter, &client))
		{
			clsUtil::ResetScreen();
			clsScreen::_DrawScreenHeader("DELETE CLIENT SCREEN");
			break;
		}
		std::cout << "This account number not found, Enter another one.\n\n";
	} while (true);

	_PrintClientInfo(client);
	if (clsUtil::ConfirmAction("Are you sure you want to delete this client"))
	{
		if (client.Delete(FileName,delimiter))
			std::cout << "Client Deleted Successfully.\n";
		else
			std::cout << "Error Client was not deleted.\n";
	}
	else
		std::cout << "Client was not deleted.\n";
}