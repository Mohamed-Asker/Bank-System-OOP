#pragma once
#include <iostream>
#include <string>
#include "clsUser.h"
#include "clsScreen.h"
#include "clsMainScreen.h"
#include "Global.h"


class clsLogin : protected clsScreen
{
private:
	//Private Methods:
	// Method(1):
	static bool _login(const std::string& LoginFile, const std::string& ClientsFileName, const std::string& UsersFileName, const std::string& delimiter);

public:
	//Public Methods:
	// Method(1):
	static bool ShowLoginScreen(const std::string& LoginFile, const std::string& ClientsFileName, const std::string& UsersFileName, const std::string& delimiter);

};