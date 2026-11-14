#include <iostream>
#include "clsMainScreen.h"


//Public Methods:
//Method(1);
void clsMainScreen::ShowMainMenu(const std::string& FileName, const std::string& delimiter)
{
	clsScreen::_DrawScreenHeader("MAIN MENU");
	std::cout << "\n[1]" << " Show Client List";
	std::cout << "\n[2]" << " Add New Client";
	std::cout << "\n[3]" << "Delete Client";
	std::cout << "\n[4]" << "Update Client Info";
	std::cout << "\n[5]" << "Find Client";
	std::cout << "\n[6]" << "Transaction Menu";
	std::cout << "\n[7]" << "Manage Users";
	std::cout << "\n[8]" << "Logout";
	std::cout << "\n----------------------------------------";
}