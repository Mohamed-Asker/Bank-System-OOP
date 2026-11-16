#include "clsDepositScreen.h"



//Private Methods:
//Method(1):
void clsDepositScreen::_PrintClientDepositInfo(clsBankClient& client)
{
	std::cout << "----------------------------------------";
	std::cout << "\n            Client Info";
	std::cout << "\n----------------------------------------";
	std::cout << "\nAccount Number : " << client.AccountNumber();
	std::cout << "\nFull Name      : " << client.FullName();
	std::cout << "\nAccount Balance: " << client.Balance;
	std::cout << "\n----------------------------------------\n";
}
//Method(2):
void clsDepositScreen::_Deposit(clsBankClient& client,double Amount)
{
	client.Balance += Amount;
}
//Method(3):
void clsDepositScreen::_PrintDepsoitResult(double balance, bool Result)
{
	if (Result)
	{
		std::cout << "Amount deposit successfully\n";
		std::cout << "New balance is [" << balance << "]\n";
	}
	else
		std::cout << "An issue occurred while performing the transaction\n";
}

//Public Methods:
//Method(1):
void clsDepositScreen::_ShowDepositScreen(const std::string& FileName, const std::string& delimiter)
{
	std::string accNumber;
	clsBankClient client;
	clsScreen::_DrawScreenHeader("DEPOSIT SCREEN");
	do
	{
		int tempAccNumber = clsInputValidate::ReadPostiveIntNumber("Account Number", "Invalid Input\n\n");
		accNumber = std::to_string(tempAccNumber);
		if (clsBankClient::isClientExist(accNumber, FileName, delimiter, &client))
		{
			system("cls");
			clsScreen::_DrawScreenHeader("DEPOSIT SCREEN");
			break;
		}
		std::cout << "This account number not found\n\n";
	} while (true);

	_PrintClientDepositInfo(client);
	double DepositAmount = clsInputValidate::ReadPostiveDblNumber("Deposit Amount", "Please enter an appropriate amount\n\n");

	if (clsUtil::ConfirmAction("Are you sure you want to perform this trnasaction"))
		_PrintDepsoitResult(client.Balance, client.Deposit(DepositAmount, FileName, delimiter));
	else
		std::cout << "Transaction was clancled\n";
}