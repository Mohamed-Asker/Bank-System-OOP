#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "clsBankClient.h"
#include "../../String Library/String Library/clsString.h"
#include "../../Input Validate Library/Input Validate Library/clsInputValidate.h"



//Constructor.
clsBankClient::clsBankClient(enMode Mode, const std::string& accNumber, const std::string& PinCode, double accBalance, const std::string& FirstName, const std::string& LastName, const std::string& Email, const std::string& Phone) :
	clsPerson(FirstName, LastName, Email, Phone), _Mode(Mode), _accNumber(accNumber), _PinCode(PinCode), _accBalance(accBalance) {};

//Setters
void clsBankClient::setPinCode(const std::string& NewPinCode)
{
	_PinCode = NewPinCode;
}
void clsBankClient::setAccountBalance(double NewBalance)
{
	_accBalance = NewBalance;
}
void clsBankClient::setMarkForDelete(bool Mark)
{
	_MarkForDelete = Mark;
}

//Getters
bool clsBankClient::isEmpty()
{
	return _Mode == enMode::EmptyMode;
}
std::string clsBankClient::AccountNumber()
{
	return _accNumber;
}
std::string clsBankClient::getPinCode()
{
	return _PinCode;
}
double clsBankClient::getAccountBalance()
{
	return _accBalance;
}
bool clsBankClient::getMarkForDelet()
{
	return _MarkForDelete;
}

//Private Methods.
//Method (1):
clsBankClient clsBankClient::_ConvertLineDataToClientObject(std::string& line, const std::string& delimiter)
{
	std::vector <std::string> vClientData = clsString::split(line, delimiter);
	return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], std::stod(vClientData[2]), vClientData[3], vClientData[4], vClientData[5], vClientData[6]);
}
//Method (2):
std::string clsBankClient::_ConvertClientObjectToLine(clsBankClient& client, const std::string& delimiter)
{
	std::string line;
	line += client.AccountNumber() + delimiter;
	line += client.PinCode + delimiter;
	line += std::to_string(client.Balance) + delimiter;
	line += client.FirstName + delimiter;
	line += client.LastName + delimiter;
	line += client.Email + delimiter;
	line += client.Phone;
	return line;
}
//Method (3):
clsBankClient clsBankClient::_getEmptyClientObject()
{
	return clsBankClient(enMode::EmptyMode, "", "", 0, "", "", "", "");
}
//Method (4):
std::vector <clsBankClient> clsBankClient::_LoadClientsDateFromFile(const std::string& FileName, const std::string& delimiter)
{
	std::vector <clsBankClient> vClients;
	std::fstream file(FileName, std::ios::in);
	if (file.is_open())
	{
		std::string line;
		while (std::getline(file, line))
			vClients.push_back(_ConvertLineDataToClientObject(line, delimiter));
		file.close();
	}
	return vClients;
}
//Method (5):
void clsBankClient::_SaveClientsDataToFile(std::vector <clsBankClient>& vClients, const std::string& FileName, const std::string& delimiter)
{
	std::fstream file(FileName, std::ios::out);
	if (file.is_open())
	{
		for (clsBankClient& tempClient : vClients)
			if (tempClient.MarkForDelet == false)
			{
				file << _ConvertClientObjectToLine(tempClient, delimiter) << std::endl;
			}
		file.close();
	}
}
//Method (6):
void clsBankClient::_AddDateLineToFile(const std::string& FileName, const std::string& delimiter)
{
	std::fstream file(FileName, std::ios::out | std::ios::app);
	if (file.is_open())
	{
		file << _ConvertClientObjectToLine(*this, delimiter) << std::endl;
		file.close();
	}
}
//Method (7):
void clsBankClient::_AddNewClientDataLine(const std::string& FileName, const std::string& delimiter)
{
	_AddDateLineToFile(FileName, delimiter);
}
//Method (8):
void clsBankClient::_Update(const std::string& FileName, const std::string& delimiter)
{
	std::vector <clsBankClient> vClients = clsBankClient::_LoadClientsDateFromFile(FileName, delimiter);
	for (clsBankClient& tempClient : vClients)
	{
		if (tempClient.AccountNumber() == AccountNumber())
		{
			tempClient = *this;
			break;
		}
	}
	clsBankClient::_SaveClientsDataToFile(vClients, FileName, delimiter);
}
//Method (9):
void clsBankClient::_MarkToDelete(std::vector <clsBankClient>& vClients, bool& isClientDeleted)
{
	for (clsBankClient& tempClient : vClients)
	{
		if (tempClient.AccountNumber() == this->AccountNumber())
		{
			tempClient.MarkForDelet = true;
			isClientDeleted = true;
			break;
		}
	}
}


//Public Methods.
//Method (1):
void clsBankClient::PrintInfo()
{
	std::cout << "           Client Info";
	std::cout << "\n-------------------------------";
	std::cout << "\nAccount Number : " << _accNumber;
	std::cout << "\nPin Code       : " << _PinCode;
	std::cout << "\nFirst Name     : " << FirstName;
	std::cout << "\nLast Name      : " << LastName;
	std::cout << "\nFull Name      : " << FullName();
	std::cout << "\nEmail          : " << Email;
	std::cout << "\nPhone          : " << Phone;
	std::cout << "\nAccount Balance: " << _accBalance;
	std::cout << "\n-------------------------------";
}
//Method (2):
clsBankClient clsBankClient::FindClinet(const std::string& accNumber, const std::string& FileName, const std::string& delimiter)
{
	std::fstream file;
	file.open(FileName, std::ios::in);
	if (file.is_open())
	{
		std::string line;
		while (std::getline(file, line))
		{
			clsBankClient client = _ConvertLineDataToClientObject(line, delimiter);
			if (client.AccountNumber() == accNumber)
			{
				file.close();
				return client;
			}
		}
		file.close();
	}
	return _getEmptyClientObject();
}
//Method (3):
clsBankClient clsBankClient::FindClinet(const std::string& accNumber, const std::string& PinCode, const std::string& FileName, const std::string& delimiter)
{
	std::fstream file;
	file.open(FileName, std::ios::in);
	if (file.is_open())
	{
		std::string line;
		while (std::getline(file, line))
		{
			clsBankClient client = _ConvertLineDataToClientObject(line, delimiter);
			if (client.AccountNumber() == accNumber && client.PinCode == PinCode)
			{
				file.close();
				return client;
			}
		}
		file.close();
	}
	return _getEmptyClientObject();
}
//Method (4):
bool clsBankClient::isClientExist(const std::string& accNumber, const std::string& FileName, const std::string& delimiter)
{
	clsBankClient client = clsBankClient::FindClinet(accNumber, FileName, delimiter);
	return (!client.isEmpty());
}
//Method (5):
bool clsBankClient::isClientExist(const std::string& accNumber, const std::string& PinCode, const std::string& FileName, const std::string& delimiter)
{
	clsBankClient client = clsBankClient::FindClinet(accNumber, PinCode, FileName, delimiter);
	return (!client.isEmpty());
}
//Method (6):
clsBankClient::enSaveResult clsBankClient::Save(const std::string& accNumber,const std::string& FileName, const std::string& delimiter)
{
	switch (_Mode)
	{
	case enMode::EmptyMode:
	{
		if (isEmpty())
			return enSaveResult::svFildEmptyObject;
		break;
	}
	case clsBankClient::enMode::UpdateMode:
	{
		_Update(FileName, delimiter);
		return enSaveResult::svSucceeded;
		break;
	}
	case clsBankClient::AddNewMode:
	{
		if (isClientExist(accNumber, FileName, delimiter))
			return enSaveResult::svFildAccountNumberExist;
		else
		{
			_AddNewClientDataLine(FileName, delimiter);
			_Mode = enMode::UpdateMode;
			return enSaveResult::svSucceeded;
		}
		break;
	}
	}
}
//Method (7):
void clsBankClient::PrintSaveResult(enSaveResult SaveResult)
{
	switch (SaveResult)
	{
	case enSaveResult::svSucceeded:
	{
		system("cls");
		PrintInfo();
		std::cout << "\nAccount Update successfully :-)\n";
		break;
	}
	case enSaveResult::svFildEmptyObject:
	{
		system("cls");
		PrintInfo();
		std::cout << "\nError account was not saved because it's Empty!\n";
		break;
	}
	case enSaveResult::svFildAccountNumberExist:
	{
		system("cls");
		PrintInfo();
		std::cout << "\nError account was not saved because account number is used!\n";
		break;
	}
	}
}
//Method (8):
clsBankClient clsBankClient::getAddNewClientObj(const std::string& accNumber)
{
	return clsBankClient(enMode::AddNewMode, accNumber, "", 0, "", "", "", "");
}
//Method (9):
bool clsBankClient::Delete(const std::string& FileName, const std::string& delimiter)
{
	std::vector <clsBankClient> vClients = _LoadClientsDateFromFile(FileName, delimiter);
	bool isClientDeleted = false;
	_MarkToDelete(vClients, isClientDeleted);
	_SaveClientsDataToFile(vClients, FileName, delimiter);
	if (isClientDeleted)
		*this = _getEmptyClientObject();
	return isClientDeleted;
}
//Method (10):
std::vector <clsBankClient> clsBankClient::ClientsList(const std::string& FileName, const std::string& delimiter)
{
	return _LoadClientsDateFromFile(FileName, delimiter);
}
//Method (11):
double clsBankClient::TotalBalance(const std::string& FileName, const std::string& delimiter)
{
	std::vector <clsBankClient> vClients = clsBankClient::ClientsList(FileName, delimiter);
	double TotalBalance = 0;
	for (clsBankClient& tempClient : vClients)
		TotalBalance += tempClient.Balance;
	return TotalBalance;
}