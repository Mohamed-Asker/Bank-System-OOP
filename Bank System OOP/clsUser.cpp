#include "clsUser.h"


//Constructors
//Constructor(1):
clsUser::clsUser() 
{
	*this = _EmptyUserObj();
}
//Constructor(2):
clsUser::clsUser(enMode Mode, const std::string& UserName, const std::string& Password, short Permissions, const std::string& FirstName, const std::string& LastName, const std::string& Email, const std::string& Phone) : clsPerson(FirstName, LastName, Email, Phone), _Mode(Mode), _UserName(UserName), _Password(Password), _Permission(Permissions) {}

//Setter:
void clsUser::setUesrName(const std::string& UserName)
{
	_UserName = UserName;
}
void clsUser::setPassword(const std::string& Password)
{
	_Password = Password;
}
void clsUser::setPermissions(short Permission)
{
	_Permission = Permission;
}

//Getters
bool clsUser::isEmpty()
{
	return _Mode == enMode::_eEmptyMode;
}
clsUser::enMode clsUser::Mode()
{
	switch (_Mode)
	{
	case enMode::_eEmptyMode:
		return enMode::_eEmptyMode;

	case enMode::_eUpdateMode:
		return enMode::_eUpdateMode;

	case enMode::_eAddNewMode:
		return enMode::_eAddNewMode;
	default:
		return _Mode;
	}
}
std::string clsUser::getUserName()
{
	return _UserName;
}
std::string clsUser::getPassword()
{
	return _Password;
}
short clsUser::getPermissons()
{
	return _Permission;
}
bool clsUser::getEllipsis()
{
	return _MarkForDelete;
}


//Private Methods:
// //Method(1):
clsUser clsUser::_EmptyUserObj()
{
	return clsUser(enMode::_eEmptyMode, "", "", 0, "", "", "", "");
}
//Method(2):
clsUser clsUser::_ConvertUserLineDateToUserObj(std::string& line, const std::string& delimiter)
{
	std::vector <std::string> vUser = clsString::split(line, delimiter);
	return clsUser(enMode::_eUpdateMode, vUser[0], vUser[1], std::stoi(vUser[2]), vUser[3], vUser[4], vUser[5], vUser[6]);
}
//Method(3):
std::string clsUser::_ConvertUserObjDataToLine(clsUser& User, const std::string& delimiter)
{
	std::string line;
	line += User.UserName + delimiter;
	line += User.Password + delimiter;
	line += std::to_string(User.Permissions) + delimiter;
	line += User.FirstName + delimiter;
	line += User.LastName + delimiter;
	line += User.Email + delimiter;
	line += User.Phone;
	return line;
}
//Method(4):
std::vector <clsUser> clsUser::_LoadUsersDataFromFile(const std::string& FileName, const std::string& delimiter)
{
	std::fstream file(FileName, std::ios::in);
	std::vector <clsUser> vUsers;
	if (file.is_open())
	{
		std::string line;
		while (std::getline(file, line))
			vUsers.push_back(_ConvertUserLineDateToUserObj(line, delimiter));

		file.close();
	}
	return vUsers;
}
//Method(5):
void clsUser::_SaveUsersDataToFile(std::vector<clsUser>& vUsers, const std::string& FileName, const std::string& delimiter)
{
	std::fstream file(FileName, std::ios::out);
	if (file.is_open())
	{
		for (clsUser& tempUser : vUsers)
		{
			if (tempUser.getEllipsis() == false)
				file << _ConvertUserObjDataToLine(tempUser, delimiter) << std::endl;
		}
		file.close();
	}
}
//Method(6):
void clsUser::_Update(const std::string& FileName, const std::string& delimiter)
{
	std::vector <clsUser> vUsers = _LoadUsersDataFromFile(FileName, delimiter);
	for (clsUser& tempUser : vUsers)
	{
		if (tempUser.UserName == UserName)
		{
			tempUser = *this;
			break;
		}
	}
	_SaveUsersDataToFile(vUsers, FileName, delimiter);
}
//Method(7):
void clsUser::_AddUserDataToFile(const std::string& FileName, const std::string& delimiter)
{
	std::fstream file(FileName, std::ios::out | std::ios::app);
	if (file.is_open())
	{
		file << _ConvertUserObjDataToLine(*this, delimiter) << std::endl;
		file.close();
	}
}
//Method(8):
void clsUser::_AddNewUser(const std::string& FileName, const std::string& delimiter)
{
	_AddUserDataToFile(FileName, delimiter);
}
//Method(9):
void clsUser::_MarkToDelete(std::vector <clsUser>& vUsers, bool& isUserDeleted)
{
	for (clsUser& tempUser : vUsers)
	{
		if (this->UserName == tempUser.UserName)
		{
			tempUser._MarkForDelete = true;
			isUserDeleted = true;
			break;
		}
	}
}
//Method(10):
std::string clsUser::_PrepareLoginRecord(const std::string& delimiter)
{
	std::string LoginRecord;

	//Prepare Login Record.
	LoginRecord = clsDate::SystemDateString() + delimiter;
	LoginRecord += UserName + delimiter;
	LoginRecord += Password + delimiter;
	LoginRecord += std::to_string(Permissions);
	return LoginRecord;
}


//Public Methods:
//Method(1):
clsUser clsUser::FindUser(const std::string& UserName, const std::string& FileName, const std::string& delimiter)
{
	std::fstream file(FileName, std::ios::in);
	if (file.is_open())
	{
		std::string line;
		while (std::getline(file, line))
		{
			clsUser user = _ConvertUserLineDateToUserObj(line, delimiter);
			if (UserName == user.UserName)
			{
				file.close();
				return user;
			}
		}
		file.close();
	}
	return _EmptyUserObj();
}
//Method(2):
clsUser clsUser::FindUser(const std::string& UserName, const std::string& Password, const std::string& FileName, const std::string& delimiter)
{

	std::fstream file(FileName, std::ios::in);
	if (file.is_open())
	{
		std::string line;
		while (std::getline(file, line))
		{
			clsUser user = _ConvertUserLineDateToUserObj(line, delimiter);
			if (UserName == user.UserName && Password == user.Password)
			{
				file.close();
				return user;
			}
		}

		file.close();
	}
	return _EmptyUserObj();
}
//Method(3):
bool clsUser::isUserExist(const std::string& UserName, const std::string& FileName, const std::string& delimiter, clsUser* UserPtr)
{
	clsUser User = FindUser(UserName, FileName, delimiter);
	if (User.Mode() != enMode::_eEmptyMode)
		if (UserPtr != nullptr)
			*UserPtr = User;
	return (!User.isEmpty());
}
//Method(4):
bool clsUser::isUserExist(const std::string& UserName, const std::string& Password, const std::string& FileName, const std::string& delimiter, clsUser* UserPtr)
{
	clsUser User = FindUser(UserName, Password, FileName, delimiter);
	if (User.Mode() != enMode::_eEmptyMode)
		if (UserPtr != nullptr)
			*UserPtr = User;
	return (!User.isEmpty());
}
//Method(5):
clsUser::enSaveResult clsUser::SaveUser(const std::string& FileName, const std::string& delimiter)
{
	switch (Mode())
	{
	case enMode::_eEmptyMode:
	{
		if (isEmpty())
			return enSaveResult::svFildEmptyObj;
		break;
	}

	case enMode::_eUpdateMode:
	{
		_Update(FileName, delimiter);
		return enSaveResult::svSuccessded;
		break;
	}

	case enMode::_eAddNewMode:
	{
		if (isUserExist(UserName, FileName, delimiter))
			return enSaveResult::svFildUserExist;
		else
		{
			_AddNewUser(FileName, delimiter);
			_Mode = enMode::_eUpdateMode;
			return enSaveResult::svSuccessded;
		}
		break;
	}
	default:
		return enSaveResult::svFildEmptyObj;
	}
}
//Method(5):
bool clsUser::DeleteUser(const std::string& FileName, const std::string& delimiter)
{
	std::vector <clsUser> vUsers = _LoadUsersDataFromFile(FileName, delimiter);
	bool isUserDeleted = false;
	_MarkToDelete(vUsers, isUserDeleted);
	_SaveUsersDataToFile(vUsers, FileName, delimiter);
	if (isUserDeleted)
		*this = _EmptyUserObj();
	return isUserDeleted;
}
//Method(6):
clsUser clsUser::AddNewUserObj(const std::string UserName)
{
	return clsUser(enMode::_eAddNewMode, UserName, "", 0, "", "", "", "");
}
//Method(7):
std::vector <clsUser> clsUser::UsersList(const std::string& FileName, const std::string& delimiter)
{
	return _LoadUsersDataFromFile(FileName, delimiter);
}
//Method(8):
void clsUser::ClearUserObj()
{
	*this = _EmptyUserObj();
}
//Method(9):
bool clsUser::HasPermission(short RequiredPermission)
{
	return (Permissions & RequiredPermission) == RequiredPermission;
}
//Method(10):
void clsUser::RegisterLogin(const std::string& LoginFile, const std::string& delimiter)
{
	std::fstream file(LoginFile, std::ios::out | std::ios::app);
	if (file.is_open())
	{
		file << _PrepareLoginRecord(delimiter) << std::endl;
		file.close();
	}
}