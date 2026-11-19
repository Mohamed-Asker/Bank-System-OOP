#pragma once
#include <iostream>
#include <iomanip>
#include "clsUser.h"
#include "Global.h"
#include <ctime>

#pragma warning (disable : 4996)


class clsScreen
{
private:
	//Private Methods:
	//Method(1):
	static std::string _SystemDate();
protected:
	//Public Methods:
	//Method(1):
	static void _DrawScreenHeader(const std::string& title, const std::string& subTitle = "", short width = 0);
};
