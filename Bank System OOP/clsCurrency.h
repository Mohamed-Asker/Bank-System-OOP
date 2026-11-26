#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Global.h"
#include "../../String Library/String Library/clsString.h"

class clsCurrency
{
private:
	//Enums.
	enum enMode
	{
		EmptyMode = 1,
		UpdateMode = 2
	};
	
	//Data Members.
	enMode _Mode;
	std::string _Countrry;
	std::string _CurrencyCode;
	std::string _CurrencyName;
	float _Rate;

	//Private Methods.
	//Method(1):
	static clsCurrency _ConvertCurrencyDataLineToObj(std::string& line);
	//Method(2):
	static std::vector <clsCurrency> _LoadCurrenciesDataFromFile();
	//Method(3):
	std::string _ConvertCurrencyObjToLine();
	//Method(4):
	void _SaveCurrencyDataToFile(std::vector <clsCurrency>& vCurrencies);
	//Method(5):
	void _UpdateCurrency();
	//Method(6):
	static clsCurrency _EmptyCurrencyObj();

public:
	//Constructors.
	clsCurrency();
	clsCurrency(enMode Mode, const std::string& Country, const std::string& CurrencyCode, const std::string& CurrencyName, const float& Rate);

	//Setter.
	void UpdateRate(float NewRate);

	//Getter.
	std::string Country();
	std::string CurrencyCode();
	std::string CurrencyName();
	float getRate();

	//Property.
	__declspec(property(get = getRate, put = UpdateRate))float Rate;
	
	//Public Methods.
	//Method(1):
	bool isEmpty();
	//Method(2):
	static std::vector <clsCurrency>  CurrencyList();
	//Method(3):
	static clsCurrency FindByCode(std::string& CurrencyCode);
	//Method(4):
	static clsCurrency FindByCountry(std::string& Country);
	//Method(5):
	static bool isCurrencyCodeExist(std::string& CurrencyCode, clsCurrency* CurrencyPtr = nullptr);
	//Method(6):
	static bool isCountryCurrencyExist(std::string& CountryCurrency, clsCurrency* CurrencyPtr = nullptr);
	
};

