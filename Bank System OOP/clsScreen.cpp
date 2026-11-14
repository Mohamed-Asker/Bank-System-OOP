#include <iostream>
#include "clsScreen.h"


//Methods:
//Method (1):
void clsScreen::_DrawScreenHeader(const std::string& title, const std::string& subTitle)
{
	std::cout << "========================================";
	std::cout << "\n               " << title;
	if (subTitle != "")
		std::cout << "\n               " << subTitle;
	std::cout << "\n========================================";
}