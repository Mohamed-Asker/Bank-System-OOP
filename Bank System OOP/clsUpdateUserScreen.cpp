#include "clsUpdateUserScreen.h"




//Private Methods:
//Method(1):
void clsUpdateUserScreen::_PrintUserInfoUpdateScreen(clsUser& user)
{
	std::cout << "---------------------------------";
	std::cout << "\n            User Info";
	std::cout << "\n---------------------------------";
	std::cout << "\nUsar Name : " << user.UserName;
	std::cout << "\nPassword  : " << user.Password;
	std::cout << "\nFull Name : " << user.FullName();
	std::cout << "\nEmail     : " << user.Email;
	std::cout << "\nPhone     : " << user.Phone;
	std::cout << "\nPermissions: " << user.Permissions;
	std::cout << "\n---------------------------------\n";
}
//Method(2):
void clsUpdateUserScreen::_ReadUserInfoUpdateScreen(clsUser& user)
{
	user.FirstName = clsInputValidate::ReadString("First Name");
	user.LastName = clsInputValidate::ReadString("Last Name ");
	user.Password = clsInputValidate::ReadString("Password  ");
	user.Email = clsInputValidate::ReadString("Email     ");
	user.Phone = clsInputValidate::ReadString("Phone     ");
	user.Permissions = _ReadPermissionsUpdateScreen();
}
//Method(3):
short clsUpdateUserScreen::_ReadPermissionsUpdateScreen()
{
	if (clsUtil::ConfirmAction("Do you want to give Full access"))
		return clsUser::enPermissions::pAll;

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
				Permissions += clsUser::enPermissions::pShowClientList;
			break;

		case 2:
			if (clsUtil::ConfirmAction("Allow Add New Client"))
				Permissions += clsUser::enPermissions::pAddNewClient;
			break;

		case 3:
			if (clsUtil::ConfirmAction("Allow Delete Client"))
				Permissions += clsUser::enPermissions::pDeleteClient;
			break;

		case 4:
			if (clsUtil::ConfirmAction("Allow Update Client"))
				Permissions += clsUser::enPermissions::pUpdateClient;
			break;

		case 5:
			if (clsUtil::ConfirmAction("Allow Find Client"))
				Permissions += clsUser::enPermissions::pFindClient;
			break;

		case 6:
			if (clsUtil::ConfirmAction("Allow Transactions"))
				Permissions += clsUser::enPermissions::pTransactions;
			break;

		case 7:
			if (clsUtil::ConfirmAction("Allow Manage Users"))
				Permissions += clsUser::enPermissions::pManageUsers;
			break;

		default:
			return 0;
		}
	}
	return Permissions;
}
//Method(4):
void clsUpdateUserScreen::_SaveResultUpdateScreen(clsUser& user, const std::string& FileName, const std::string& delimiter)
{
	switch (user.SaveUser(FileName, delimiter))
	{
	case clsUser::enSaveResult::svSuccessded:
		clsUtil::ResetScreen();
		_PrintUserInfoUpdateScreen(user);
		std::cout << "User update successfully\n";
		break;

	case clsUser::enSaveResult::svFildEmptyObj:
		std::cout << "\nError updates was not saved because it's Empty!\n";
		break;

	case clsUser::enSaveResult::svFildUserExist:
		std::cout << "\nError User was not saved because it's used!\n";
		break;
	}
}

//Public Methods:
//Method(1):
void clsUpdateUserScreen::ShowUpdateUserScreen(const std::string& FileName, const std::string& delimiter)
{
	std::string UserName;
	clsUser user;
	clsScreen::_DrawScreenHeader("UPDATE USER SCREEN");
	do
	{
		UserName = clsInputValidate::ReadString("User Name");
		if (UserName == "Admin")
		{
			std::cout << "The Admin account cannot be update because it is a protected account.\n\n";
			continue;
		}

		if (clsUser::isUserExist(UserName, FileName, delimiter, &user))
		{
			system("cls");
			clsScreen::_DrawScreenHeader("UPDATE USER SCREEN");
			break;
		}
		std::cout << "[" << UserName << "] is not exist, Enter another one.\n\n";
	} while (true);
	_PrintUserInfoUpdateScreen(user);
	if (clsUtil::ConfirmAction("Are you sure you want to update this user"))
	{
		_ReadUserInfoUpdateScreen(user);
		_SaveResultUpdateScreen(user, FileName, delimiter);
	}
	else
		std::cout << "User was not update.\n";
}