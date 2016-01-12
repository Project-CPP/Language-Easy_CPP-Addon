#ifndef LANGUAGEEASY_H
#define LANGUAGEEASY_H


#include <iostream>
#include <string>
#include <sstream>
#include <Windows.h>

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

// Windows 
class WindowMessage
{
public:

	// Default Constructor
	WindowMessage();

	// Overload Constructor
	WindowMessage(string, string);

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
