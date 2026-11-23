#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "clsPerson.h"
#include "Global.h"
#include "../../String Library/String Library/clsString.h"
#include "../../Input Validate Library/Input Validate Library/clsInputValidate.h"


class clsBankClient : public clsPerson
{
private:
	//Enums
	enum enMode
	{
		EmptyMode = 1,
		UpdateMode = 2,
		AddNewMode = 3
	};
	

	//Data Members.
	enMode _Mode;
	std::string _accNumber;
	std::string _PinCode;
	double _accBalance;
	bool _MarkForDelete = false;

	//Declaration:
	struct stTransferLogRecord;

	//Private Methods.
	//Method (1):
	static clsBankClient _ConvertLineDataToClientObject(std::string& line, const std::string& delimiter);
	//Method (2):
	static std::string _ConvertClientObjectToLine(clsBankClient& client, const std::string& delimiter);
	//Method (3):
	static clsBankClient _getEmptyClientObject();
	//Method (4):
	static std::vector <clsBankClient> _LoadClientsDateFromFile(const std::string& FileName, const std::string& delimtier);
	//Method (5):
	static void _SaveClientsDataToFile(std::vector <clsBankClient>& vClients, const std::string& FileName, const std::string& delimiter);
	//Method (6):
	void _AddDateLineToFile(const std::string& FileName, const std::string& delimiter);
	//Method (7):
	void _AddNewClientDataLine(const std::string& FileName, const std::string& delimiter);
	//Method (8):
	void _Update(const std::string& FileName, const std::string& delimiter);
	//Method (9):
	void _MarkToDelete(std::vector <clsBankClient>& vClients, bool& isClientDeleted);
	//Method (10):
	std::string _PerpareTransferLogDataLine(double TransferAmount, clsBankClient& DestinationClient, const std::string& UserName);
	//Method (11):
	void _RegisterTransferLog(double TransferAmount, clsBankClient& DestinationClient, const std::string& UserName);
	//Method (12):
	static stTransferLogRecord _ConvertTransferLogLineDataToRecord(std::string& line);




public:
	//Constructor.
	clsBankClient(enMode Mode, const std::string& accNumber, const std::string& PinCode, double accBalance, const std::string& FirstName, const std::string& LastName, const std::string& Email, const std::string& Phone);
	clsBankClient();
	//Setters
	void setPinCode(const std::string& PinCode);
	void setAccountBalance(double Balance);
	void setMarkForDelete(bool Mark);

	//Getters
	bool isEmpty();
	std::string AccountNumber();
	std::string getPinCode();
	double getAccountBalance();
	bool getMarkForDelet();

	//Properties
	__declspec(property(get = getPinCode, put = setPinCode)) std::string PinCode;
	__declspec(property(get = getAccountBalance, put = setAccountBalance)) double Balance;
	__declspec(property(get = getMarkForDelet, put = setMarkForDelete))bool MarkForDelet;

	//Enums
	enum enSaveResult
	{
		svSucceeded = 1,
		svFildEmptyObject = 2,
		svFildAccountNumberExist = 3
	};

	//Structure:
	struct stTransferLogRecord
	{
		std::string DateAndTime = "";
		std::string SourecAccNumber = "";
		std::string DestinationAccNumber = "";
		double TransferAmount = 0;
		double SourecBalance = 0;
		double DestinationBalance = 0;
		std::string UserName = "";
	};

	//Public Methods.
	//Method (1):
	
	//Method (2):
	static clsBankClient FindClinet(const std::string& accNumber, const std::string& FileName, const std::string& delimiter);
	//Method (3):
	static clsBankClient FindClinet(const std::string& accNumber, const std::string& PinCode, const std::string& FileName, const std::string& delimiter);
	//Method (4):
	static bool isClientExist(const std::string& accNumber, const std::string& FileName, const std::string& delimiter, clsBankClient* Ptr = nullptr);
	//Method (5):
	static bool isClientExist(const std::string& accNumber, const std::string& PinCode, const std::string& FileName, const std::string& delimiter, clsBankClient* Ptr = nullptr);
	//Method (6):
	enSaveResult Save(const std::string& accNumber, const std::string& FileName, const std::string& delimiter);
	//Method (7):
	
	//Method (8):
	static clsBankClient getAddNewClientObj(const std::string& accNumber);
	//Method (9):
	bool Delete(const std::string& FileName, const std::string& delimiter);
	//Method (10):
	static std::vector <clsBankClient> ClientsList(const std::string& FileName, const std::string& delimiter);
	//Method (11):
	static double TotalBalance(const std::string& FileName, const std::string& delimiter);
	//Method (12):
	bool Deposit(double Amount, const std::string& FileName, const std::string& delimiter);
	//Method (13):
	bool Withdraw(double Amount, const std::string& FileName, const std::string& delimiter);
	//Method (14):
	bool Trnasfer(double TransferAmount, clsBankClient& DestinationClient, const std::string& FileName, const std::string& delimiter, const std::string& UserName);
	//Method (16):
	static std::vector <stTransferLogRecord> TransferLogList();
	
}; 