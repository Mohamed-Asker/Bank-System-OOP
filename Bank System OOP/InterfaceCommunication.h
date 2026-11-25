#pragma once
#include <iostream>


class InterfaceCommunication
{
public:
	virtual void SendEmail(const std::string& Title, const std::string& Body) = 0;
	virtual void SendFax(const std::string& Title, const std::string& Body) = 0;
	virtual void SendSMS(const std::string& Title, const std::string& Body) = 0;
};

