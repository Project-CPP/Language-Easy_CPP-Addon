#ifndef LANGUAGEEASY_H
#define LANGUAGEEASY_H


#include <iostream>
#include <string>
#include <Windows.h>
#include <wlanapi.h>
#include <sstream>
#include <objbase.h>
#include <wtypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <fstream>





using namespace std;


#define MainDoor int main()
#define Say cout <<
#define SayEnd ;
#define SuccessReturn return 0;
#define Failreturn return 1;
#define Getinput cin.get();
#define PauseWindow cin.get();
#define Integer int
#define IntegerEnd ;
#define Word string
#define WordEnd ;

// String Syntax
#define Nothing ""
#define NoTitle ""



//Greetings
#define GreetingMessage "Hey!"
#define GreetingMessage2 "Hello!"
#define GreetingMessage3 "Good to see you!"
#define GreetingMessage4 "Nice to see you!"
#define GreetingMessage5 "Long time no see!"
#define GreetingMessage6 "It’s been a while. Good to see you!"
#define SlangGreetingMessage "Yo!"
#define SlangGreetingMessage2 "Howdy!"
#define SlangGreetingMessage3 "Good day mate!"








// Windows 
class WindowsMessage
{
public:

	// Default Constructor
	WindowsMessage();

	// Overload Construtor
	WindowsMessage(string, string);

	//Accessors 
	void OutputWindow();

private:
	string Message;
	string MessageName;

};


class WindowsBattery
{
public:
	// Default Constructor
	WindowsBattery(bool IsBatteryPresent);

	//Accessors
	string Output_Battery_Percentage_As_String();
	double Output_Battery_Percentage_As_Double();
	int Output_Battery_Percentage_As_Integer();
	double Output_Battery_Flag_As_Double();
	int Output_Battery_Flag_As_Integer();
	bool Output_Battery_Flag_As_Boolean();
	double Output_Is_Computer_Plugged_In_As_Double();
	int Output_Is_Computer_Plugged_In_As_Integer();
	bool Output_Is_Computer_Plugged_In_As_Boolean();
	
	
	
	

private:

};

class WindowsWlan
{
public:

	//Default Constructor
	WindowsWlan(bool);

	// Accessors
	int Get_Wifi_Signal_As_Integer();
	string Get_Wifi_Signal_As_String();
	int Get_Other_Wifi_Signal_Geo();
	int Get_Other_Wifi_Signal_Geo2();
	int Get_Other_Wifi_Signal_Geo3();
	int Get_Other_Wifi_Signal_Geo4();
	int Console_Out_In_Depth_Wifi_Information();


private:

};









#endif