#include <iostream>
#include "clsLogin.h"

int main()
{
	for (short trail = 3; trail >=1 ; trail--)
		if (!clsLogin::ShowLoginScreen("ClientDate.txt", "UsersData.txt", "#//#"))
			break;
	
	return 0;
}