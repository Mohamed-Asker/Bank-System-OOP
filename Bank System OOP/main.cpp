#include <iostream>
#include "clsLogin.h"

int main()
{
	while (true)
	{
		clsLogin::ShowLoginScreen("ClientDate.txt", "UsersData.txt", "#//#");
	}
	
	return 0;
}