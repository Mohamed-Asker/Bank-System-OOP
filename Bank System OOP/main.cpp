#include <iostream>
#include "../../Input Validate Library/Input Validate Library/clsInputValidate.h"
#include "clsBankClient.h"


void PrintHeaderOfUpdateClient()
{
	std::cout << "\n\n-------------------------------";
	std::cout << "\n      UPDATE CLIENT SCREEN";
	std::cout << "\n-------------------------------";
	std::cout << "\nUdateing Client: \n\n";
}

void ReadClientInfo(clsBankClient& client)
{
	PrintHeaderOfUpdateClient();
	client.FirstName = clsInputValidate::ReadString("First Name");
	client.LastName = clsInputValidate::ReadString("Last Name ");
	client.PinCode = clsInputValidate::ReadString("Pin Code  ");
	client.Email = clsInputValidate::ReadString("Email     ");
	client.Phone = clsInputValidate::ReadString("Phone     ");
	client.Balance = clsInputValidate::ReadPostiveDblNumber("Account Balance");
}

//Method (6):
void UpdateClient(const std::string& FileName, const std::string& delimiter)
{
	std::string accNumber;
	do
	{
		accNumber = clsInputValidate::ReadString("Account Number");
		if (clsBankClient::isClientExist(accNumber, FileName, delimiter))
		{
			system("cls");
			break;
		}
		std::cout << "Account number is not found, Enter another one.\n\n";
	} while (true);

	clsBankClient client = clsBankClient::FindClinet(accNumber, FileName, delimiter);
	client.PrintInfo();
	ReadClientInfo(client);
	client.PrintSaveResult(client.Save(FileName, delimiter));
}


std::string FileClient = "ClientDate.txt";
int main()
{
	UpdateClient(FileClient, "#//#");

	system("pause>0");
	return 0;
}