#include <iostream>
#include <iomanip>
#include "clsMainScreen.h"

void RunApplication(const std::string& FileName, const std::string& delimiter)
{
	bool Exit = true;
	do
	{
		system("cls");
		clsMainScreen::ShowMainMenu(FileName, delimiter);
		Exit = clsMainScreen::PerformMainMenuOprtion(clsMainScreen::ReadMainMenuOption(1, 8, "Choose What do you want to do[1 to 8]"), FileName, delimiter);
	} while (Exit);
}

int main()
{
	RunApplication("ClientDate.txt", "#//#");
	return 0;
}