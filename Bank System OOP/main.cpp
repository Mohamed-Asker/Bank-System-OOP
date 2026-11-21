#include <iostream>
#include "clsLogin.h"

int main()
{
	while (clsLogin::ShowLoginScreen("Login Register.txt", "ClientDate.txt", "UsersData.txt", "#//#")) {}
	
	return 0;
}