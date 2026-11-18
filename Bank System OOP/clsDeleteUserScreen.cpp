#include "clsDeleteUserScreen.h"



//Private Methods:
//Method(1):
void clsDeleteUserScreen::_PrintUserInfoDeleteScreen(clsUser& user)
{
	std::cout << "---------------------------------";
	std::cout << "\n           User Info";
	std::cout << "\n---------------------------------";
	std::cout << "\nUser Name : " << user.UserName;
	std::cout << "\nPassword  : " << user.Password;
	std::cout << "\nFull Name : " << user.FullName();
	std::cout << "\nEmail     : " << user.Email;
	std::cout << "\nPhone     : " << user.Phone;
	std::cout << "\nPermissions: " << user.Permissions;
	std::cout << "\n---------------------------------\n";
}

//Public Methods:
//Method(1):
void clsDeleteUserScreen::ShowDeleteUserScreen(const std::string& FileName, const std::string& delimiter)
{
	std::string UserName;
	clsUser user;
	clsScreen::_DrawScreenHeader("DELETE USER SCREEN");
	do
	{
		std::cout << "User Name: ";
		std::getline(std::cin >> std::ws, UserName);
		if (UserName == "Admin")
		{
			std::cout << "The Admin account cannot be deleted because it is a protected account.\n\n";
			continue;
		}

		if (clsUser::isUserExist(UserName, FileName, delimiter, &user))
		{
			system("cls");
			clsScreen::_DrawScreenHeader("DELETE USER SCREEN");
			break;
		}
		std::cout << UserName << " is not exist, Enter another one.\n\n";
	} while (true);
	_PrintUserInfoDeleteScreen(user);
	if (clsUtil::ConfirmAction("Are you sure you want to delete this user"))
	{
		if (user.DeleteUser(FileName, delimiter))
			std::cout << "User deleted successfully\n";
		else
			std::cout << "Error User was not deleted.\n";
	}
	else
		std::cout << "User was not deleted\n";
}