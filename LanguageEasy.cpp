#include "LanguageEasy.h"

//Windows
WindowMessage::WindowMessage()
{
	MessageName = "";
	Message = "";
}

WindowMessage::WindowMessage(string NewMessageName, string NewMessage)
{
	MessageName = NewMessageName;
	Message = NewMessage;
}

void WindowMessage::OutputWindow()
{
	char MessageBuffer[9999];
	char MessageNameBuffer[9999];
	sprintf_s(MessageBuffer, Message.c_str());
	sprintf_s(MessageNameBuffer, MessageName.c_str());
	MessageBoxA(NULL, MessageBuffer, MessageNameBuffer, MB_OK);
}




// WindowsBattery

WindowsBattery::WindowsBattery(bool IsBatteryPresent)
{

}
double WindowsBattery::Output_Battery_Flag_As_Double()
{

	double BatteryFlag = false;
	SYSTEM_POWER_STATUS spsPwr;
	if (GetSystemPowerStatus(&spsPwr)) {
		BatteryFlag = static_cast<double>(spsPwr.BatteryFlag);
	}
	return BatteryFlag;
}
int WindowsBattery::Output_Battery_Flag_As_Integer()
{

	int BatteryFlag = false;
	SYSTEM_POWER_STATUS spsPwr;
	if (GetSystemPowerStatus(&spsPwr)) {
		BatteryFlag = static_cast<int>(spsPwr.BatteryFlag);
	}
	return BatteryFlag;
}
bool WindowsBattery::Output_Battery_Flag_As_Boolean()
{

	bool BatteryFlag = false;
	SYSTEM_POWER_STATUS spsPwr;
	if (GetSystemPowerStatus(&spsPwr)) {
		BatteryFlag = static_cast<bool>(spsPwr.BatteryFlag);
	}
	return BatteryFlag;
}
string WindowsBattery::Output_Battery_Percentage_As_String()
{
	string BatteryPercent = "";
	SYSTEM_POWER_STATUS spsPwr;
	if (GetSystemPowerStatus(&spsPwr)) {
		double Battery = static_cast<double>(spsPwr.BatteryLifePercent);
		stringstream BatteryString;
		BatteryString << static_cast<double>(spsPwr.BatteryLifePercent);
		BatteryPercent = BatteryString.str();
	}
	return BatteryPercent;
}
double WindowsBattery::Output_Battery_Percentage_As_Double()
{
	double BatteryPercent = 0;
	SYSTEM_POWER_STATUS spsPwr;
	if (GetSystemPowerStatus(&spsPwr)) {
		BatteryPercent = static_cast<double>(spsPwr.BatteryLifePercent);
	}
	return BatteryPercent;
}
int WindowsBattery::Output_Battery_Percentage_As_Integer()
{
	int BatteryPercent = 0;
	SYSTEM_POWER_STATUS spsPwr;
	if (GetSystemPowerStatus(&spsPwr)) {
		BatteryPercent = static_cast<int>(spsPwr.BatteryLifePercent);
	}
	return BatteryPercent;
}
double WindowsBattery::Output_Is_Computer_Plugged_In_As_Double()
{

	double IsPCPluggedIn = false;
	SYSTEM_POWER_STATUS spsPwr;
	if (GetSystemPowerStatus(&spsPwr)) {
		IsPCPluggedIn = static_cast<double>(spsPwr.ACLineStatus);
	}
	return IsPCPluggedIn;
}
int WindowsBattery::Output_Is_Computer_Plugged_In_As_Integer()
{

	int IsPCPluggedIn = false;
	SYSTEM_POWER_STATUS spsPwr;
	if (GetSystemPowerStatus(&spsPwr)) {
		IsPCPluggedIn = static_cast<int>(spsPwr.ACLineStatus);
	}
	return IsPCPluggedIn;
}
bool WindowsBattery::Output_Is_Computer_Plugged_In_As_Boolean()
{

	bool IsPCPluggedIn = false;
	SYSTEM_POWER_STATUS spsPwr;
	if (GetSystemPowerStatus(&spsPwr)) {
		IsPCPluggedIn = static_cast<bool>(spsPwr.ACLineStatus);
	}
	return IsPCPluggedIn;
}
