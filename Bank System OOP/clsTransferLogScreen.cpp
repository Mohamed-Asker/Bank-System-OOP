#include "clsTransferLogScreen.h"




//Private Methods:
//Private Methods:
//Method(1):
void clsTransferLogScreen::_PrintHeaderOfTransferLogScreen(short NumberOfRecords)
{
	std::cout << std::string(120, '=');
	std::cout << std::setw(23) << std::left << "Data/Time";
	std::cout << std::setw(18) << std::left << "S.Account Number";
	std::cout << std::setw(18) << std::left << "D.Account Number";
	std::cout << std::setw(17) << std::left << "Transfer Amount";
	std::cout << std::setw(18) << std::left << "S.Balance";
	std::cout << std::setw(18) << std::left << "D.Balance";
	std::cout << std::setw(8) << std::left << "UserName";
	std::cout << std::string(120, '=');
}
//Method(1):
void clsTransferLogScreen::_PrintTransferLogRecordLine(clsBankClient::stTransferLogRecord& TransferLogRecord)
{
	std::cout << std::setw(23) << std::left << TransferLogRecord.DateAndTime;
	std::cout << std::setw(18) << std::left << TransferLogRecord.SourecAccNumber;
	std::cout << std::setw(18) << std::left << TransferLogRecord.SourecAccNumber;
	std::cout << std::setw(17) << std::left << TransferLogRecord.TransferAmount;
	std::cout << std::setw(18) << std::left << TransferLogRecord.SourecBalance;
	std::cout << std::setw(18) << std::left << TransferLogRecord.DestinationBalance;
	std::cout << std::setw(8) << std::left << TransferLogRecord.UserName;
}

//Public Methods:
//Method(1):
void clsTransferLogScreen::ShowTransferLogScreen()
{
	std::vector <clsBankClient::stTransferLogRecord> vTransferLogRecords = clsBankClient::TransferLogList();
	short NumberOfRecords = vTransferLogRecords.size();

	//Draw Main Header.
	clsScreen::_DrawScreenHeader("TRANSFERLOG SCREEN", "(" + std::to_string(NumberOfRecords) + ") RECORD" + clsUtil::FormWord(NumberOfRecords, false), 38);

	//Draw Sub Header.
	_PrintHeaderOfTransferLogScreen(NumberOfRecords);

	if (NumberOfRecords == 0)
	{
		std::cout << std::setw(77) << std::right << "No TransferLog Available In the System!\n";
		std::cout << std::string(120, '=');
	}
	else
	{
		short counter = 0;
		for (clsBankClient::stTransferLogRecord& tempTransferLogRecord : vTransferLogRecords)
		{
			counter++;
			_PrintTransferLogRecordLine(tempTransferLogRecord);
			std::cout << std::endl;

			if (counter != NumberOfRecords)
				std::cout << std::string(120, '-');
			else
				std::cout << std::string(120, '=');
		}
	}
}