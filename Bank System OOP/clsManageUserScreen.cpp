#include "clsManageUserScreen.h"




//Private Methods:
//Method(1):
void clsManageUserScreen::_ShowManageUserMenu()
{
	std::cout << "[1] List Users";
	std::cout << "\n[2] Add New User";
	std::cout << "\n[3] Delete User";
	std::cout << "\n[4] Update User";
	std::cout << "\n[5] Find User";
	std::cout << "\n[6] Main Menu";
	std::cout << "\n------------------------------------------\n";
}
//Method(2):
bool clsManageUserScreen::_PerformUserMenuOption(enUserMenuOptions UserChoose, const std::string& FileName, const std::string& delimiter)
{
	switch (UserChoose)
	{
	case enUserMenuOptions::uListUser:
		_ShowUsersListScreen(FileName, delimiter);
		clsUtil::PressAnyKey("Press any key to go back to Users menu");
		return true;

	case enUserMenuOptions::uAddNewUser:
		_ShowAddNewUserScreen(FileName, delimiter);
		clsUtil::PressAnyKey("Press any key to go back to Users menu");
		return true;

	case enUserMenuOptions::uDeleteUser:
		_ShowDeleteUserScreen(FileName, delimiter);
		clsUtil::PressAnyKey("Press any key to go back to Users menu");
		return true;

	case enUserMenuOptions::uUpdateUser:
		_ShowUpdateUserScreen(FileName, delimiter);
		clsUtil::PressAnyKey("Press any key to go back to Users menu");
		return true;

	case enUserMenuOptions::uFindUser:
		_ShowFindUserScreen(FileName, delimiter);
		clsUtil::PressAnyKey("Press any key to go back to Users menu");
		return true;

	case enUserMenuOptions::uMainMenu:
		return false;

	default:
		return true;
	}
}
//Method(3):
clsManageUserScreen::enUserMenuOptions clsManageUserScreen::_ReadUserMenuOption()
{
	return static_cast<enUserMenuOptions>(clsInputValidate::ReadShortNumberBetween("Choose whar do you want to do from 1 to 6", 1, 6));
}
//Method(4):
void clsManageUserScreen::_ShowUsersListScreen(const std::string& FileName, const std::string& delimiter)
{
	system("cls");
	clsUsersListScreen::ShowUsersListScreen(FileName, delimiter);
}
//Method(5):
void clsManageUserScreen::_ShowAddNewUserScreen(const std::string& FileName, const std::string& delimiter)
{
	system("cls");
	clsAddNewUserScreen::_ShowAddNewUserScreen(FileName, delimiter);
}
//Method(6):
void clsManageUserScreen::_ShowDeleteUserScreen(const std::string& FileName, const std::string& delimiter)
{
	system("cls");
	clsDeleteUserScreen::ShowDeleteUserScreen(FileName, delimiter);
}
//Method(7):
void clsManageUserScreen::_ShowUpdateUserScreen(const std::string& FileName, const std::string& delimiter)
{
	system("cls");
	std::cout << "Update User Screen Will be here Soon...\n";
}
//Method(8):
void clsManageUserScreen::_ShowFindUserScreen(const std::string& FileName, const std::string& delimiter)
{
	system("cls");
	std::cout << "Find User Screen Will be here Soon...\n";
}


//Public Methods:
//Method(1):
void clsManageUserScreen::RunUserMenuScreen(const std::string& FileName, const std::string& delimiter)
{
	bool GoMainMenu = true;
	do
	{
		system("cls"); 
		clsScreen::_DrawScreenHeader("MANAGE USERS SCREEN");
		_ShowManageUserMenu();
		GoMainMenu = _PerformUserMenuOption(_ReadUserMenuOption(), FileName, delimiter);
	} while (GoMainMenu);
}