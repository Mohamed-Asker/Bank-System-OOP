#include "clsRegisterLoginScreen.h"




//Private Methods:
//Method(1):
void clsRegisterLoginScreen::_PrintHeaderOfRegisterLoginScreen()
{
	std::cout << std::string(120, '=');
	std::cout << std::setw(40) << std::left << "Data/Time";
	std::cout << std::setw(30) << std::left << "UserName";
	std::cout << std::setw(25) << std::left << "Password";
	std::cout << std::setw(25) << std::left << "Permissions";
	std::cout << std::string(120, '=');
}
//Method(2):
void clsRegisterLoginScreen::_PrintLoginRegisterRecord(clsUser::stLoginRegisterRecord& LoginRegister)
{
	std::cout << std::setw(40) << LoginRegister.DateAndTime;
	std::cout << std::setw(30) << LoginRegister.UserName;
	std::cout << std::setw(25) << LoginRegister.Password;
	std::cout << std::setw(25) << LoginRegister.Permissions;
}

//Public Methods:
//Method(1):
void clsRegisterLoginScreen::ShowRegisterLoginScreen(const std::string& FileName, const std::string& delimiter)
{
	if (!CurrentUser.HasPermission(clsUser::pLoginRegister))
	{
		std::cout << "Access Denied! Contact Your Admin\n";
		return;
	}
		
	//Obtaining Login Registers.
	std::vector <clsUser::stLoginRegisterRecord> vLoginRegisterRecords = clsUser::LoginRegisterList(FileName, delimiter);
	short NumberOfRegister = vLoginRegisterRecords.size();

	//Draw Main Header.
	clsScreen::_DrawScreenHeader("LOGIN REGISTER LIST SCREEN", "(" + std::to_string(NumberOfRegister) + " ) RGISTER" + clsUtil::FormWord(NumberOfRegister, false), 38);
	//Draw Sub Header.
	_PrintHeaderOfRegisterLoginScreen();

	if (NumberOfRegister == 0)
	{
		std::cout << std::setw(78) << std::right << "No Logins Available In the System!\n";
		std::cout << std::string(120, '=');
	}
	else
	{
		short counter = 0; 
		//Print All Registers Login.
		for (clsUser::stLoginRegisterRecord& tempLoginRegister : vLoginRegisterRecords)
		{
			counter++;
			_PrintLoginRegisterRecord(tempLoginRegister);
			std::cout << std::endl;
			if (counter != NumberOfRegister)
				std::cout << std::string(120, '-');
			else
				std::cout << std::string(120, '=');
		}
	}
}