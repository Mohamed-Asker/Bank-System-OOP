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
		UpdateMode = 2
	};
	enum enSaveResult
	{
		svSucceeded = 1,
		svFildEmptyObject = 2
	};

	//Data Members.
	enMode _Mode;
	std::string _accNumber;
	std::string _PinCode;
	double _accBalance;

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
	void _Update(const std::string& FileName, const std::string& delimiter);


public:
	//Constructor.
	clsBankClient(enMode Mode, const std::string& accNumber, const std::string& PinCode, double accBalance, const std::string& FirstName, const std::string& LastName, const std::string& Email, const std::string& Phone);

	//Setters
	void setPinCode(const std::string& PinCode);
	void setAccountBalance(double Balance);

	//Getters
	bool isEmpty();
	std::string getAccountNumber();
	std::string getPinCode();
	double getAccountBalance();

	//Properties
	__declspec(property(get = getPinCode, put = setPinCode)) std::string PinCode;
	__declspec(property(get = getAccountBalance, put = setAccountBalance)) double Balance;

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
	enSaveResult Save(const std::string& FileName, const std::string& delimiter);
	//Method (7):
	void PrintSaveResult(enSaveResult SaveResult);

};