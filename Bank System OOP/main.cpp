#include <iostream>
#include <iomanip>
#include "clsMainScreen.h"

void RunApplication(const std::string& ClientFileName, const std::string& UserFileName, const std::string& delimiter)
{
	bool Exit = true;
	do
	{
		system("cls");
		clsMainScreen::ShowMainMenu();
		Exit = clsMainScreen::PerformMainMenuOprtion(clsMainScreen::ReadMainMenuOption(1, 8, "Choose What do you want to do[1 to 8]"), ClientFileName, UserFileName, delimiter);
	} while (Exit);
}

int main()
{
	RunApplication("ClientDate.txt", "UsersData.txt", "#//#");
	
	return 0;
}