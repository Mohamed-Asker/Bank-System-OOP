#include "clsLogin.h"




//Private Method:
// Method(1):
void clsLogin::_login(const std::string& ClientsFileName, const std::string& UsersFileName, const std::string& delimiter)
{
	bool isLoginFaild = false;
	std::string UserName;
	std::string Password;
	do
	{
		if (isLoginFaild)
			std::cout << "Invalid Password or UserName\n\n";
		std::cout << "User Name: ";
		std::getline(std::cin >> std::ws, UserName);
		std::cout << "Password : ";
		std::getline(std::cin, Password);

		CurrentUser = clsUser::FindUser(UserName, Password, UsersFileName, delimiter);
		isLoginFaild = CurrentUser.isEmpty();
	} while (isLoginFaild);
	clsMainScreen::RunMainMenu(ClientsFileName, UsersFileName, delimiter);
}


//Public Methods:
// Method(1):
void clsLogin::ShowLoginScreen(const std::string& ClientsFileName, const std::string& UsersFileName, const std::string& delimiter)
{
	system("cls");
	clsScreen::_DrawScreenHeader("LOGIN SCREEN");
	_login(ClientsFileName, UsersFileName, delimiter);
}