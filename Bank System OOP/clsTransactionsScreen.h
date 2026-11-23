#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsDepositScreen.h"
#include "clsWithDrawScreen.h"
#include "clsTotalBalaceScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"
#include "clsUser.h"
#include "Global.h"
#include "../../Input Validate Library/Input Validate Library/clsInputValidate.h"
#include "../../Utility Library/Utility Library/clsUtil.h"



class clsTransactionsScreen : protected clsScreen
{
private:
	//Enums
	enum enTransactionsMenuOptions
	{
		tDeposit = 1,
		tWithdraw = 2,
		tTotalBalance = 3,
		tTransfer = 4,
		tTransferLog = 5,
		tMainMenu = 6
	};

	//Private Methods:
	//Method(1):
	static void _ShowTransactionsMenuScreen();
	//Method(2):
	static enTransactionsMenuOptions _ReadTransactionsMenuOptions(const std::string& msg, short from, short to);
	//Method(3):
	static bool _PerformTransactionMenuOption(enTransactionsMenuOptions UserChoose, const std::string& FileName, const std::string& delimiter);
	//Method(4):
	static void _ShowDepositScreen(const std::string& FileName, const std::string& delimiter);
	//Method(5):
	static void _ShowWithdrawScreen(const std::string& FileName, const std::string& delimiter);
	//Method(6):
	static void _ShowTotalBalanceScreen(const std::string& FileName, const std::string& delimiter);
	//Method(7):
	static void _ShowTransferScreen(const std::string& FileName, const std::string& delimiter);
	//Method(8):
	static void _ShowTransferLogScreen();

public: 

	//Public Methods:
	//Method(1):
	static void RunTransactionsMenu(const std::string& FileName, const std::string& delimiter);
};

