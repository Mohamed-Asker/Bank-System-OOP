#include <iostream>
#include "clsScreen.h"


//Methods:
//Method (1):
void clsScreen::_DrawScreenHeader(const std::string& title, const std::string& subTitle, short width)
{
	short SeparatorWidth = 42;
	// Draw Top Separator
	std::cout << std::string(width, ' ') << std::string(SeparatorWidth, '=') << "\n";

	// Draw Title
	short TitleSpace = (SeparatorWidth - title.length()) / 2;
	std::cout << std::string(width + TitleSpace, ' ') << title << "\n";

	// Draw SubTitle
	if (!subTitle.empty())
	{
		short subTitleSpace = (SeparatorWidth - subTitle.length()) / 2;
		std::cout << std::string(width + subTitleSpace, ' ') << subTitle << "\n";
	}

	// Draw Bottom Separator
	std::cout << std::string(width, ' ') << std::string(SeparatorWidth, '=') << "\n";
}