#include "clsScreen.h"




//Private Methods:
//Method(1):
std::string clsScreen::_SystemDate()
{
	std::time_t Now = std::time(0);
	return std::ctime(&Now);
}


//Public Methods:
//Method(1):
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

	//Print User and Date
	std::string UserName = CurrentUser.FullName();
	if (UserName != " ")
	{
		std::cout << std::string(width, ' ') << "UserName: " << UserName << "\n";
		std::cout << std::string(width, ' ') << "Date    : " << _SystemDate();
	}

	// Draw Bottom Separator
	std::cout << std::string(width, ' ') << std::string(SeparatorWidth, '=') << "\n";
}