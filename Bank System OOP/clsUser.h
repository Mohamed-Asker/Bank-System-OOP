#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "clsPerson.h"
#include "../../String Library/String Library/clsString.h"
#include "../../Date Library/Date Library/clsDate.h"



class clsUser : public clsPerson
{
private:
	//Private Enums
	enum enMode
	{
		_eEmptyMode = 1,
		_eUpdateMode = 2,
		_eAddNewMode = 3
	};

	//Private Data Members:
	std::string _UserName;
	std::string _Password;
	enMode _Mode;
	short _Permission;
	bool _MarkForDelete = false;

	//Private Methods:
	//Method(1):
	static clsUser _EmptyUserObj();
	//Method(2):
	static clsUser _ConvertUserLineDateToUserObj(std::string& line, const std::string& delimiter);
	//Method(3):
	std::string _ConvertUserObjDataToLine(clsUser& User, const std::string& delimiter);
	//Method(4):
	static std::vector <clsUser> _LoadUsersDataFromFile(const std::string& FileName, const std::string& delimiter);
	//Method(5):
	void _SaveUsersDataToFile(std::vector<clsUser>& vUsers, const std::string& FileName, const std::string& delimiter);
	//Method(6):
	void _Update(const std::string& FileName, const std::string& delimiter);
	//Method(7):
	void _AddUserDataToFile(const std::string& FileName, const std::string& delimiter);
	//Method(8):
	void _AddNewUser(const std::string& FileName, const std::string& delimiter);
	//Method(9):
	void _MarkToDelete(std::vector <clsUser>& vUsers, bool& isUserDeleted);
	//Method(10):
	std::string _PrepareLoginRecord(const std::string& delimiter);
	
public: 
	//Constructors:
    //Constructor(1):
	clsUser();
	//Constructor(2):
	clsUser(enMode Mode, const std::string& UserName, const std::string& Password, short Permissions, const std::string& FirstName, const std::string& LastName, const std::string& Email, const std::string& Phone);

	//Setter:
	void setUesrName(const std::string& UserName);
	void setPassword(const std::string& Password);
	void setPermissions(short permission);

	//Getters
	bool isEmpty();
	clsUser::enMode Mode();
	std::string getUserName();
	std::string getPassword();
	short getPermissons();
	bool getEllipsis();

	//Properties
	__declspec(property(get = getUserName, put = setUesrName)) std::string UserName;
	__declspec(property(get = getPassword, put = setPassword))std::string Password;
	__declspec(property(get = getPermissons, put = setPermissions))short Permissions;

	//Public Enums;
	//Enum(1):
	enum enSaveResult
	{
		svSuccessded = 1,
		svFildEmptyObj = 2,
		svFildUserExist = 3
	};
	//Enum(2):
	enum enPermissions
	{
		pShowClientList = 1,
		pAddNewClient = 2,
		pDeleteClient = 4,
		pUpdateClient = 8,
		pFindClient = 16,
		pTransactions = 32,
		pManageUsers = 64,
		pAll = 127
	};

	//Public Methods:
	//Method(1):
	static clsUser FindUser(const std::string& UserName, const std::string& FileName, const std::string& delimiter);
	//Method(2):
	static clsUser FindUser(const std::string& UserName, const std::string& Password, const std::string& FileName, const std::string& delimiter);
	//Method(3):
	static bool isUserExist(const std::string& UserName, const std::string& FileName, const std::string& delimiter, clsUser* UserPtr = nullptr);
	//Method(4):
	static bool isUserExist(const std::string& UserName, const std::string& Password,const std::string& FileName, const std::string& delimiter, clsUser* UserPtr = nullptr);
	//Method(5):
	enSaveResult SaveUser(const std::string& FileName, const std::string& delimiter);
	//Method(5):
	bool DeleteUser(const std::string& FileName, const std::string& delimiter);
	//Method(6):
	static clsUser AddNewUserObj(const std::string UserName);
	//Method(7):
	static std::vector <clsUser> UsersList(const std::string& FileName, const std::string& delimiter);
	//Method(8):
	void ClearUserObj();
	//Method(9):
	bool HasPermission(short Permission);
	//Method(10):
	void RegisterLogin(const std::string& LoginFile, const std::string& delimiter);

};

