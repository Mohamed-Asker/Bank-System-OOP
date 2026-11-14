#pragma once
#include <iostream>
#include <iomanip>



class clsScreen
{
protected:
	static void _DrawScreenHeader(const std::string& title, const std::string& subTitle = "", short width = 0);
};
