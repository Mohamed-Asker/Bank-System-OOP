#pragma once
#pragma once
#include <iostream>
#include <vector>
#include "clsPerson.h"




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
	enum enSaveResult
	{
		svSucceeded = 1,
		svFildEmptyObject = 2,
		svFildAccountNumberExist = 3
	};

	//Data Members.
	enMode _Mode;
	std::string _accNumber;
	std::string _PinCode;
	double _accBalance;
	bool _MarkForDelete = false;

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

public:
	//Constructor.
	clsBankClient(enMode Mode, const std::string& accNumber, const std::string& PinCode, double accBalance, const std::string& FirstName, const std::string& LastName, const std::string& Email, const std::string& Phone);

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

	//Public Methods.
	//Method (1):
	void PrintInfo() override;
	//Method (2):
	static clsBankClient FindClinet(const std::string& accNumber, const std::string& FileName, const std::string& delimiter);
	//Method (3):
	static clsBankClient FindClinet(const std::string& accNumber, const std::string& PinCode, const std::string& FileName, const std::string& delimiter);
	//Method (4):
	static bool isClientExist(const std::string& accNumber, const std::string& FileName, const std::string& delimiter);
	//Method (5):
	static bool isClientExist(const std::string& accNumber, const std::string& PinCode, const std::string& FileName, const std::string& delimiter);
	//Method (6):
	enSaveResult Save(const std::string& accNumber, const std::string& FileName, const std::string& delimiter);
	//Method (7):
	void PrintSaveResult(enSaveResult SaveResult);
	//Method (8):
	static clsBankClient getAddNewClientObj(const std::string& accNumber);
	//Method (9):
	bool Delete(const std::string& FileName, const std::string& delimiter);

};