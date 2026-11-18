#include "clsFindUserScreen.h"




//Private Methods:
//Method(1):
void clsFindUserScreen::_PrintUserInfoFindUserScreen(clsUser& user)
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


//Public Methods:
//Method(1)
void clsFindUserScreen::ShowFindUserScreen(const std::string& FileName, const std::string& delimiter)
{
	std::string UserName;
	clsUser user;
	clsScreen::_DrawScreenHeader("FIND USER SCREEN");
	std::cout << "User Name: ";
	std::getline(std::cin >> std::ws, UserName);
	if (clsUser::isUserExist(UserName, FileName, delimiter, &user))
		_PrintUserInfoFindUserScreen(user);
	else
		std::cout << "This user is not exist\n";
}