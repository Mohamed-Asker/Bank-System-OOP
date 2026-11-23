#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "Global.h"
#include "../../Utility Library/Utility Library/clsUtil.h"



class clsTransferLogScreen :protected clsScreen
{
private:
	//Private Methods:
	//Method(1):
	static void _PrintHeaderOfTransferLogScreen(short NumberOfRecords);
	//Method(2):
	static void _PrintTransferLogRecordLine(clsBankClient::stTransferLogRecord& TransferLogRecord);
public:
	//Public Methods:
	//Method(1):
	static void ShowTransferLogScreen();
};