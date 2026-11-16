#include "clsWithDrawScreen.h"


//Private Methods:
//Method(1):
void clsWithDrawScreen::_PrintClientWithdrawInfo(clsBankClient& client)
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
double clsWithDrawScreen::_ReadWithdrawAmount(double ClientBalance)
{
	double WithdrawAmount;
	do
	{
		WithdrawAmount = clsInputValidate::ReadPostiveDblNumber("Withdraw Amount", "Please enter an appropriate amount\n\n");
		if (WithdrawAmount <= ClientBalance)
			break;
		std::cout << "Withdrawal amount exceeds your account balance.\n\n";
	} while (true);
	return WithdrawAmount;
}
//Method(3):
void clsWithDrawScreen::_PrintWithdrawResult(double balance, bool Result)
{
	if (Result)
	{
		std::cout << "Amount Withdraw successfully\n";
		std::cout << "New balance is [" << balance << "]\n";
	}
	else
		std::cout << "An issue occurred while performing the transaction\n";
}

//Public Menthods:
//Menthod(1):
void clsWithDrawScreen::ShowWithdrawScreen(const std::string& FileName, const std::string& delimiter)
{
	std::string accNumber;
	clsBankClient client;
	clsScreen::_DrawScreenHeader("WITHDRAW DCREEN");
	do
	{
		int tempAccNumber = clsInputValidate::ReadPostiveIntNumber("Account Number", "Invalid Input\n\n");
		accNumber = std::to_string(tempAccNumber);
		if (clsBankClient::isClientExist(accNumber, FileName, delimiter, &client))
		{
			clsUtil::ResetScreen();
			clsScreen::_DrawScreenHeader("WITHDRAW DCREEN");
			break;
		}
		std::cout << "Client with account number [" << accNumber << "] not found\n\n";
	} while (true);
	_PrintClientWithdrawInfo(client);
	double WithdrawAmount = _ReadWithdrawAmount(client.Balance);

	if (clsUtil::ConfirmAction("Are you sure you want to perform this transaction"))
		_PrintWithdrawResult(client.Balance, client.Withdraw(WithdrawAmount, FileName, delimiter));
	else
		std::cout << "Transaction was clancled\n";
}