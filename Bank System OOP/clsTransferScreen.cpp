#include "clsTransferScreen.h"



//Private Methoes:
//Method(1):
std::string clsTransferScreen::_ReadAccountNumber(const std::string msg,const std::string& FileName, const std::string& delimiter,clsBankClient& client)
{
	std::string accNumber;
	do
	{
		std::cout << msg << ": ";
		std::getline(std::cin >> std::ws, accNumber);
		if (clsBankClient::isClientExist(accNumber, FileName, delimiter, &client))
			return accNumber;

		std::cout << "This account number [" << accNumber << "] not exist, Enter another one.\n\n";
	} while (true);
}
//Method(2):
void clsTransferScreen::_PrintClientInfoTransferScreen(clsBankClient& client)
{
	std::cout << "------------------------------";
	std::cout << "\n        Client Info";
	std::cout << "\n------------------------------";
	std::cout << "\nAccount Number: " << client.AccountNumber();
	std::cout << "\nClient Name   : " << client.FullName();
	std::cout << "\nClient Balance: " << client.Balance;
	std::cout << "\n------------------------------\n\n";
}
//Method(3):
double clsTransferScreen::_ReadTransferAmount(const double& Balance)
{
	double TransferAmount;
	do
	{
		std::cout << "Transfer Amount: ";
		std::cin >> TransferAmount;
		if (TransferAmount <= Balance)
			return TransferAmount;
		
		std::cout << "Amount exceeds the available balance,try again\n\n";
	} while (true);
}


//Public Methods:
//Method(1):
void clsTransferScreen::ShowTransferScreen(const std::string& FileName, const std::string& delimiter)
{
	std::string SourecAccNumber;
	clsBankClient SourceClient;
	clsBankClient DestinationClient;

	clsScreen::_DrawScreenHeader("TRANSFET SCREEN");
	SourecAccNumber = _ReadAccountNumber("Account number to transfer from", FileName, delimiter, SourceClient);
	_PrintClientInfoTransferScreen(SourceClient);
	do 
	{
		//Check if the transfer to is the same transfer from.
		if (_ReadAccountNumber("Account number to transfer to", FileName, delimiter, DestinationClient) != SourecAccNumber)
			break;

		std::cout << "You cannot transfer to the same account.\n\n";
	} while (true);
	_PrintClientInfoTransferScreen(DestinationClient);
	
	//Read Transfer Amount.
	double TransferAmount = _ReadTransferAmount(SourceClient.Balance);

	//Print result of tranfer.
	if (clsUtil::ConfirmAction("Are you sure you want to perform this operation"))
	{
		if (SourceClient.Trnasfer(TransferAmount, DestinationClient, FileName, delimiter))
			std::cout << "Transfer done successfully\n\n";
		else
			std::cout << "Transfer Faild\n\n";
	}
	else
		std::cout << "Canceled operation\n\n";

	std::cout << "Source Client:\n";
	_PrintClientInfoTransferScreen(SourceClient);
	std::cout << "Destination Client:\n";
	_PrintClientInfoTransferScreen(DestinationClient);
}