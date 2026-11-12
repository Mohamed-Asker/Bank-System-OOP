#include <iostream>
#include "../../Input Validate Library/Input Validate Library/clsInputValidate.h"
#include "../../Utility Library/Utility Library/clsUtil.h"
#include "clsBankClient.h"

void PrintHeaderOfDeleteScreen()
{
	std::cout << "-------------------------------";
	std::cout << "\n      DELETE SCREEN";
	std::cout << "\n-------------------------------\n";
}

void DeleteScreen(std::string FileName, std::string delimiter)
{
	std::string accNumber;
	PrintHeaderOfDeleteScreen();
	do
	{
		accNumber = clsInputValidate::ReadString("Account Number");
		if (clsBankClient::isClientExist(accNumber, FileName, "#//#"))
		{
			system("cls");
			PrintHeaderOfDeleteScreen();
			break;
		}
		std::cout << "Account number is not found, Enter another one.\n\n";
	} while (true);

	clsBankClient client = clsBankClient::FindClinet(accNumber, FileName, "#//#");
	client.PrintInfo();

	if (clsUtil::ConfirmAction("\nAre you sure you want to delete this client"))
	{
		if (client.Delete(FileName, delimiter))
			std::cout << "Client Deleted Successfully.\n";
		else
			std::cout << "Error Client was not deleted.\n";
	}
	else
		std::cout << "Client was not deleted.\n";
}


std::string FileClient = "ClientDate.txt";
int main()
{
	DeleteScreen(FileClient, "#//#");
	

	system("pause>0");
	return 0;
}