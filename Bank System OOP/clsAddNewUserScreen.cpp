#include "clsAddNewUserScreen.h"




//Private Methods:
//Method(1):
void clsAddNewUserScreen::_ReadUserInfoAddNew(clsUser& user)
{
	user.FirstName = clsInputValidate::ReadString("First Name");
	user.LastName = clsInputValidate::ReadString("Last Name ");
	user.Email = clsInputValidate::ReadString("Email     ");
	user.Phone = clsInputValidate::ReadString("Phone     ");
	user.Password = clsInputValidate::ReadString("Password  ");
	user.Permissions = _ReadPermissions();
}
//Method(2):
short clsAddNewUserScreen::_ReadPermissions()
{
	if (clsUtil::ConfirmAction("Do you want to give Full access"))
		return 127;

	std::cout << "\n=-=-==-=-==-=-==-=-==-=-==-=-==-=-==-=-==-";
	std::cout << "\n             USER PERMISSIONS";
	std::cout << "\n=-=-==-=-==-=-==-=-==-=-==-=-==-=-==-=-==-\n";
	short Permissions = 0;
	for (short i = 1; i <= 7; i++)
	{
		switch (i)
		{
		case 1:
			if (clsUtil::ConfirmAction("Allow Show Clients"))
				Permissions += 1;
			break;

		case 2:
			if (clsUtil::ConfirmAction("Allow Add New Client"))
				Permissions += 2;
				break;

		case 3:
			if (clsUtil::ConfirmAction("Allow Delete Client"))
				Permissions += 4;
			break;

		case 4:
			if (clsUtil::ConfirmAction("Allow Update Client"))
				Permissions += 8;
			break;

		case 5:
			if (clsUtil::ConfirmAction("Allow Find Client"))
				Permissions += 16;
			break;

		case 6:
			if (clsUtil::ConfirmAction("Allow Transactions"))
				Permissions += 32;
			break;

		case 7:
			if (clsUtil::ConfirmAction("Allow Manage Users"))
				Permissions += 64;
			break;

		default:
			return 0;
		}
	}
	return Permissions;
}
//Method(3):
void clsAddNewUserScreen::_PrintUserInfoAddNew(clsUser& User)
{
	std::cout << "---------------------------------";
	std::cout << "\n           User Info";
	std::cout << "\n---------------------------------";
	std::cout << "\nFirst Name: " << User.FirstName;
	std::cout << "\nLast Name : " << User.LastName;
	std::cout << "\nFull Name : " << User.FullName();
	std::cout << "\nEmail     : " << User.Email;
	std::cout << "\nPhone     : " << User.Phone;
	std::cout << "\nUser Name : " << User.UserName;
	std::cout << "\nPassword  : " << User.Password;
	std::cout << "\nPermissions: " << User.Permissions;
	std::cout << "\n---------------------------------\n";
}
//Method(4):
void clsAddNewUserScreen::_PrintSaveResult(clsUser& user, const std::string& FileName, const std::string& delimiter)
{
	switch (user.SaveUser(FileName, delimiter))
	{
	case clsUser::svSuccessded:
		clsUtil::ResetScreen();
		_PrintUserInfoAddNew(user);
		std::cout << "User Add Successfully :-)\n";
		break;

	case clsUser::svFildEmptyObj:
		clsUtil::ResetScreen();
		std::cout << "\nError user was not saved because it's Empty!\n";
		break;

	case clsUser::svFildUserExist:
		clsUtil::ResetScreen();
		std::cout << "\nError user was not saved because is used!\n";
		break;

	default:
		clsUtil::ResetScreen();
		_PrintUserInfoAddNew(user);
	}
}

//Public Methods:
//Method(1):
void clsAddNewUserScreen::_ShowAddNewUserScreen(const std::string& FileName, const std::string& delimiter)
{
	std::string UserName;
	clsScreen::_DrawScreenHeader("ADD NEW USER SCREEN");
	do
	{
		UserName = clsInputValidate::ReadString("User Name");
		if (!clsUser::isUserExist(UserName, FileName, delimiter))
		{
			system("cls");
			clsScreen::_DrawScreenHeader("ADD NEW USER SCREEN");
			break;
		}
		std::cout << "User with user name [" << UserName << "] is already exist\n\n";
	} while (true);

	clsUser user = clsUser::getAddNewUserObj(UserName);
	_ReadUserInfoAddNew(user);
	_PrintSaveResult(user, FileName, delimiter);
}