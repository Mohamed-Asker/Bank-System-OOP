#include "clsLogin.h"




//Private Method:
// Method(1):
bool clsLogin::_login(const std::string& LoginFile, const std::string& ClientsFileName, const std::string& UsersFileName, const std::string& delimiter)
{
	bool isLoginFaild = false;
	short LoginFialdCount = 0;
	std::string UserName;
	std::string Password;
	do
	{
		//Print Result of Input.
		if (isLoginFaild)
		{
			LoginFialdCount++;
			std::cout << "Invalid Password or UserName\n";
			std::cout << "You have " << (3 - LoginFialdCount) << " trail to login\n\n";
		}

		//Check if Login Fiail == 3.
		if (LoginFialdCount == 3)
		{
			std::cout << "You are locked after 3 faild trails.\n";
			return false;
		}

		//Read UserName and Password.
		std::cout << "User Name: ";
		std::getline(std::cin >> std::ws, UserName);
		std::cout << "Password : ";
		std::getline(std::cin, Password);

		//Try to Find User and Check if he is Empty.
		CurrentUser = clsUser::FindUser(UserName, Password, UsersFileName, delimiter);
		isLoginFaild = CurrentUser.isEmpty();

	} while (isLoginFaild);
	//Save Login to Login Register File.
	CurrentUser.RegisterLogin(LoginFile, delimiter);
	clsMainScreen::RunMainMenu(ClientsFileName, UsersFileName, LoginFile, delimiter);
	return true;
}

//Public Methods:
// Method(1):
bool clsLogin::ShowLoginScreen(const std::string& LoginFile, const std::string& ClientsFileName, const std::string& UsersFileName, const std::string& delimiter)
{
	system("cls");
	clsScreen::_DrawScreenHeader("LOGIN SCREEN");
	return _login(LoginFile, ClientsFileName, UsersFileName, delimiter);
}