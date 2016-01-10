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