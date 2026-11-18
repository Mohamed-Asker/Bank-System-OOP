#include "clsUsersListScreen.h"




//Private Methods:
//Method(1):
void clsUsersListScreen::_PrintHeaderOfUsersListScreen()
{
	std::cout << std::string(120, '=');
	std::cout << std::setw(20) << std::left << "User Name";
	std::cout << std::setw(13) << std::left << "Password";
	std::cout << std::setw(28) << std::left << "Full Name";
	std::cout << std::setw(20) << std::left << "Phone";
	std::cout << std::setw(27) << std::left << "Email";
	std::cout << std::setw(12) << std::left << "Permissions";
	std::cout << std::string(120, '=');
}
//Method(2):
void clsUsersListScreen::_PrintUserInfoListScreen(clsUser& user)
{
	std::cout << std::setw(20) << std::left << user.UserName;
	std::cout << std::setw(13) << std::left << user.Password;
	std::cout << std::setw(28) << std::left << user.FullName();
	std::cout << std::setw(20) << std::left << user.Phone;
	std::cout << std::setw(27) << std::left << user.Email;
	std::cout << std::setw(12) << std::left << user.Permissions;
}

//Public Methods:
//Method(1):
void clsUsersListScreen::ShowUsersListScreen(const std::string& FileName, const std::string& delimiter)
{
	std::vector <clsUser> vUsers = clsUser::UsersList(FileName, delimiter);
	short NumberOfUsers = vUsers.size();
	clsScreen::_DrawScreenHeader("USERS LIST SCREEN", "(" + std::to_string(NumberOfUsers) + ") USER" + clsUtil::FormWord(NumberOfUsers, false), 38);
	_PrintHeaderOfUsersListScreen();
	if (NumberOfUsers == 0)
	{
		std::cout << std::setw(77) << std::right << "No users Available In the System!\n";
		std::cout << std::string(120, '=');
	}
	else
	{
		short counter = 0;
		for (clsUser& tempUser : vUsers)
		{
			counter++;
			_PrintUserInfoListScreen(tempUser);
			std::cout << std::endl;
			if (counter != NumberOfUsers)
				std::cout << std::string(120, '-');
			else
				std::cout << std::string(120, '=');
		}
	}
}