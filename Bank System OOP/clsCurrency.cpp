#include "clsCurrency.h"



//Constructors.
clsCurrency::clsCurrency() {}
clsCurrency::clsCurrency(enMode Mode, const std::string& Country, const std::string& CurrencyCode, const std::string& CurrencyName, const float& Rate)
	: _Mode(Mode), _Countrry(Country), _CurrencyCode(CurrencyCode), _CurrencyName(CurrencyName), _Rate(Rate) {}

//Setter.
void clsCurrency::UpdateRate(float NewRate)
{
	_Rate = NewRate;
}

//Getter.
std::string clsCurrency::Country()
{
	return _Countrry;
}
std::string clsCurrency::CurrencyCode()
{
	return _CurrencyCode;
}
std::string clsCurrency::CurrencyName()
{
	return _CurrencyName;
}
float clsCurrency::getRate()
{
	return _Rate;
}

//Private Methods.
//Method(1):
clsCurrency clsCurrency::_ConvertCurrencyDataLineToObj(std::string& line)
{
	std::vector <std::string> vCurrencyData;
	return clsCurrency(enMode::UpdateMode, vCurrencyData[0], vCurrencyData[1], vCurrencyData[2], std::stof(vCurrencyData[3]));
}
//Method(2):
std::vector <clsCurrency> clsCurrency::_LoadCurrenciesDataFromFile()
{
	std::vector <clsCurrency> vCurrencies;
	std::fstream file(::CurrencyFileName, std::ios::in);
	if (file.is_open())
	{
		std::string line;
		while (std::getline(file, line))
			vCurrencies.push_back(_ConvertCurrencyDataLineToObj(line));

		file.close();
	}
	return vCurrencies;
}
//Method(3):
std::string clsCurrency::_ConvertCurrencyObjToLine()
{
	std::string LineData;

	LineData += this->Country() + ::delimiter;
	LineData += this->CurrencyCode() + ::delimiter;
	LineData += this->CurrencyName() + ::delimiter;
	LineData += std::to_string(this->Rate);
	return LineData;
}
//Method(4):
void clsCurrency::_SaveCurrencyDataToFile(std::vector <clsCurrency>& vCurrencies)
{
	std::fstream file(::CurrencyFileName, std::ios::out);
	if (file.is_open())
	{
		for (clsCurrency& tempCurrency : vCurrencies)
			file << tempCurrency._ConvertCurrencyObjToLine() << std::endl;

		file.close();
	}
}
//Method(5):
void clsCurrency::_UpdateCurrency()
{
	std::vector <clsCurrency> vCurrencies = _LoadCurrenciesDataFromFile();
	for (clsCurrency& tempCurrency : vCurrencies)
	{
		if (tempCurrency.CurrencyCode() == this->CurrencyCode())
		{
			tempCurrency = *this;
			break;
		}
	}
	_SaveCurrencyDataToFile(vCurrencies);
}
//Method(6):
clsCurrency clsCurrency::_EmptyCurrencyObj()
{
	return clsCurrency(enMode::EmptyMode, "", "", "", 0);
}


//Public Methods.
//Method(1):
bool clsCurrency::isEmpty()
{
	return (_Mode == enMode::EmptyMode);
}
//Method(2):
std::vector <clsCurrency>  clsCurrency::CurrencyList()
{
	return _LoadCurrenciesDataFromFile();
}
//Method(3):
clsCurrency clsCurrency::FindByCode(std::string& CurrencyCode)
{
	CurrencyCode = clsString::UpperAllLetterInString(CurrencyCode);
	std::fstream file(::CurrencyFileName , std::ios::in);
	if (file.is_open())
	{
		std::string LineData;
		clsCurrency Currency;
		while (std::getline(file, LineData))
		{
			Currency = _ConvertCurrencyDataLineToObj(LineData);
			if (Currency.CurrencyCode() == CurrencyCode)
			{
				file.close();
				return Currency;
			}
		}
		file.close();
	}
	return _EmptyCurrencyObj();
}
//Method(4):
clsCurrency clsCurrency::FindByCountry(std::string& Country)
{
	Country = clsString::UpperAllLetterInString(Country);
	std::fstream file(::CurrencyFileName, std::ios::in);
	if (file.is_open())
	{
		std::string LineData;
		clsCurrency currency;
		while (std::getline(file, LineData))
		{
			currency = _ConvertCurrencyDataLineToObj(LineData);
			if (currency.Country() == Country)
			{
				file.close();
				return currency;
			}
		}
		file.close();
	}
	return _EmptyCurrencyObj();
}
//Method(5):
bool clsCurrency::isCurrencyExist(std::string& CurrencyCode, clsCurrency* CurrencyPtr)
{
	clsCurrency currency = FindByCode(CurrencyCode);
	if (!currency.isEmpty())
	{
		if (CurrencyPtr != nullptr)
			*CurrencyPtr = currency;
		return true;
	}
	else
		return false;
}