#include <iostream>
#include "clsMainScreen.h"
#include "../../Utility Library/Utility Library/clsUtil.h"
#include "../../Input Validate Library/Input Validate Library/clsInputValidate.h"

//Priavte Methods:
//Method(1);
void clsMainScreen::_ShowClientListScreen(const std::string& FileNam, const std::string& delimiter)
{
	clsUtil::ResetScreen();
	std::cout << "Client list screen will be here soon";
	clsUtil::PressAnyKey("Press any key to go back to main menu");
}
//Method(2);
void clsMainScreen::_ShowAddNewClientScreen(const std::string& FileNam, const std::string& delimiter)
{
	clsUtil::ResetScreen();
	std::cout << "Add new client screen will be here soon";
	clsUtil::PressAnyKey("Press any key to go back to main menu");
}
//Method(3);
void clsMainScreen::_ShowDeleteClientScreen(const std::string& FileNam, const std::string& delimiter)
{
	clsUtil::ResetScreen();
	std::cout << "Delete client screen will be here soon";
	clsUtil::PressAnyKey("Press any key to go back to main menu");
}
//Method(4);
void clsMainScreen::_ShowUpdateClientScreen(const std::string& FileNam, const std::string& delimiter)
{
	clsUtil::ResetScreen();
	std::cout << "Update client screen will be here soon";
	clsUtil::PressAnyKey("Press any key to go back to main menu");
}
//Method(5);
void clsMainScreen::_ShowFindClientScreen(const std::string& FileNam, const std::string& delimiter)
{
	clsUtil::ResetScreen();
	std::cout << "Find client screen will be here soon";
	clsUtil::PressAnyKey("Press any key to go back to main menu");
}
//Method(6);
void clsMainScreen::_ShowTransactionScreen(const std::string& FileNam, const std::string& delimiter)
{
	clsUtil::ResetScreen();
	std::cout << "Transaction screen will be here soon";
	clsUtil::PressAnyKey("Press any key to go back to main menu");
}
//Method(7);
void clsMainScreen::_ShowManageUserScreen(const std::string& FileNam, const std::string& delimiter)
{
	clsUtil::ResetScreen();
	std::cout << "Manage users screen will be here soon";
	clsUtil::PressAnyKey("Press any key to go back to main menu");
}


//Public Methods:
//Method(1);
void clsMainScreen::ShowMainMenu(const std::string& FileName, const std::string& delimiter)
{
	clsScreen::_DrawScreenHeader("MAIN MENU");
	std::cout << "\n[1]" << " Show Client List";
	std::cout << "\n[2]" << " Add New Client";
	std::cout << "\n[3]" << " Delete Client";
	std::cout << "\n[4]" << " Update Client Info";
	std::cout << "\n[5]" << " Find Client";
	std::cout << "\n[6]" << " Transaction Menu";
	std::cout << "\n[7]" << " Manage Users";
	std::cout << "\n[8]" << " Logout";
	std::cout << "\n----------------------------------------\n";
}
//Method(2);
clsMainScreen::enMainMenuOptions clsMainScreen::ReadMainMenuOption(short from, short to, const std::string& msg)
{
	return enMainMenuOptions(clsInputValidate::ReadShortNumberBetween(msg , from, to));
}
//Method(3);
bool clsMainScreen::PerformMainMenuOprtion(enMainMenuOptions UserChoose, const std::string& FileName, const std::string& delimiter)
{
	switch (UserChoose)
	{
	case enMainMenuOptions::ShowClientList:
		_ShowClientListScreen(FileName, delimiter);
		return true;

	case enMainMenuOptions::AddNewClient:
		_ShowAddNewClientScreen(FileName, delimiter);
		return true;

	case enMainMenuOptions::DeleteClient:
		_ShowDeleteClientScreen(FileName, delimiter);
		return true;

	case enMainMenuOptions::UpdateClient:
		_ShowUpdateClientScreen(FileName, delimiter);
		return true;

	case enMainMenuOptions::FindClient:
		_ShowFindClientScreen(FileName, delimiter);
		return true;

	case enMainMenuOptions::Transactions:
		_ShowTransactionScreen(FileName, delimiter);
		return true;

	case enMainMenuOptions::ManageUsers:
		_ShowManageUserScreen(FileName, delimiter);
		return true;

	case enMainMenuOptions::Exit:
		return false;

	default:
		return true;
	}
}