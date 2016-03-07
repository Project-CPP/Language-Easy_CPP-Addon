#include "LanguageEasy.h"

//WindowsMessage
WindowsMessage::WindowsMessage()
{
	MessageName = "";
	Message = "";
}
WindowsMessage::WindowsMessage(string NewMessageName, string NewMessage)
{
	MessageName = NewMessageName;
	Message = NewMessage;
}
void WindowsMessage::OutputWindow()
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



// WindowsWlan
WindowsWlan::WindowsWlan(bool IsWifiPresent)
{

}
int WindowsWlan::Console_Out_In_Depth_Wifi_Information()
{


#ifndef UNICODE
#define UNICODE
#endif

	// Need to link with Wlanapi.lib and Ole32.lib
#pragma comment(lib, "wlanapi.lib")
#pragma comment(lib, "ole32.lib")


		// Declare and initialize variables.

		HANDLE hClient = NULL;
		DWORD dwMaxClient = 2;      //    
		DWORD dwCurVersion = 0;
		DWORD dwResult = 0;
		DWORD dwRetVal = 0;
		int iRet = 0;

		WCHAR GuidString[39] = { 0 };

		unsigned int i, j, k;

		/* variables used for WlanEnumInterfaces  */

		PWLAN_INTERFACE_INFO_LIST pIfList = NULL;
		PWLAN_INTERFACE_INFO pIfInfo = NULL;

		PWLAN_AVAILABLE_NETWORK_LIST pBssList = NULL;
		PWLAN_AVAILABLE_NETWORK pBssEntry = NULL;

		int iRSSI = 0;

		dwResult = WlanOpenHandle(dwMaxClient, NULL, &dwCurVersion, &hClient);
		if (dwResult != ERROR_SUCCESS) {
			wprintf(L"WlanOpenHandle failed with error: %u\n", dwResult);
			return 1;
			// You can use FormatMessage here to find out why the function failed
		}

		dwResult = WlanEnumInterfaces(hClient, NULL, &pIfList);
		if (dwResult != ERROR_SUCCESS) {
			wprintf(L"WlanEnumInterfaces failed with error: %u\n", dwResult);
			return 1;
			// You can use FormatMessage here to find out why the function failed
		}
		else {
			wprintf(L"Num Entries: %lu\n", pIfList->dwNumberOfItems);
			wprintf(L"Current Index: %lu\n", pIfList->dwIndex);
			for (i = 0; i < (int)pIfList->dwNumberOfItems; i++) {
				pIfInfo = (WLAN_INTERFACE_INFO *)&pIfList->InterfaceInfo[i];
				wprintf(L"  Interface Index[%u]:\t %lu\n", i, i);
				iRet = StringFromGUID2(pIfInfo->InterfaceGuid, (LPOLESTR)&GuidString,
					sizeof(GuidString) / sizeof(*GuidString));
				// For c rather than C++ source code, the above line needs to be
				// iRet = StringFromGUID2(&pIfInfo->InterfaceGuid, (LPOLESTR) &GuidString, 
				//     sizeof(GuidString)/sizeof(*GuidString)); 
				if (iRet == 0)
					wprintf(L"StringFromGUID2 failed\n");
				else {
					wprintf(L"  InterfaceGUID[%d]: %ws\n", i, GuidString);
				}
				wprintf(L"  Interface Description[%d]: %ws", i,
					pIfInfo->strInterfaceDescription);
				wprintf(L"\n");
				wprintf(L"  Interface State[%d]:\t ", i);
				switch (pIfInfo->isState) {
				case wlan_interface_state_not_ready:
					wprintf(L"Not ready\n");
					break;
				case wlan_interface_state_connected:
					wprintf(L"Connected\n");
					break;
				case wlan_interface_state_ad_hoc_network_formed:
					wprintf(L"First node in a ad hoc network\n");
					break;
				case wlan_interface_state_disconnecting:
					wprintf(L"Disconnecting\n");
					break;
				case wlan_interface_state_disconnected:
					wprintf(L"Not connected\n");
					break;
				case wlan_interface_state_associating:
					wprintf(L"Attempting to associate with a network\n");
					break;
				case wlan_interface_state_discovering:
					wprintf(L"Auto configuration is discovering settings for the network\n");
					break;
				case wlan_interface_state_authenticating:
					wprintf(L"In process of authenticating\n");
					break;
				default:
					wprintf(L"Unknown state %ld\n", pIfInfo->isState);
					break;
				}
				wprintf(L"\n");

				dwResult = WlanGetAvailableNetworkList(hClient,
					&pIfInfo->InterfaceGuid,
					0,
					NULL,
					&pBssList);

				if (dwResult != ERROR_SUCCESS) {
					wprintf(L"WlanGetAvailableNetworkList failed with error: %u\n",
						dwResult);
					dwRetVal = 1;
					// You can use FormatMessage to find out why the function failed
				}
				else {
					wprintf(L"WLAN_AVAILABLE_NETWORK_LIST for this interface\n");

					wprintf(L"  Num Entries: %lu\n\n", pBssList->dwNumberOfItems);

					for (j = 0; j < pBssList->dwNumberOfItems; j++) {
						pBssEntry =
							(WLAN_AVAILABLE_NETWORK *)& pBssList->Network[j];

						wprintf(L"  Profile Name[%u]:  %ws\n", j, pBssEntry->strProfileName);

						wprintf(L"  SSID[%u]:\t\t ", j);
						if (pBssEntry->dot11Ssid.uSSIDLength == 0)
							wprintf(L"\n");
						else {
							for (k = 0; k < pBssEntry->dot11Ssid.uSSIDLength; k++) {
								wprintf(L"%c", (int)pBssEntry->dot11Ssid.ucSSID[k]);
							}
							wprintf(L"\n");
						}

						wprintf(L"  BSS Network type[%u]:\t ", j);
						switch (pBssEntry->dot11BssType) {
						case dot11_BSS_type_infrastructure:
							wprintf(L"Infrastructure (%u)\n", pBssEntry->dot11BssType);
							break;
						case dot11_BSS_type_independent:
							wprintf(L"Infrastructure (%u)\n", pBssEntry->dot11BssType);
							break;
						default:
							wprintf(L"Other (%lu)\n", pBssEntry->dot11BssType);
							break;
						}

						wprintf(L"  Number of BSSIDs[%u]:\t %u\n", j, pBssEntry->uNumberOfBssids);

						wprintf(L"  Connectable[%u]:\t ", j);
						if (pBssEntry->bNetworkConnectable)
							wprintf(L"Yes\n");
						else {
							wprintf(L"No\n");
							wprintf(L"  Not connectable WLAN_REASON_CODE value[%u]:\t %u\n", j,
								pBssEntry->wlanNotConnectableReason);
						}

						wprintf(L"  Number of PHY types supported[%u]:\t %u\n", j, pBssEntry->uNumberOfPhyTypes);

						if (pBssEntry->wlanSignalQuality == 0)
							iRSSI = -100;
						else if (pBssEntry->wlanSignalQuality == 100)
							iRSSI = -50;
						else
							iRSSI = -100 + (pBssEntry->wlanSignalQuality / 2);

						wprintf(L"  Signal Quality[%u]:\t %u (RSSI: %i dBm)\n", j,
							pBssEntry->wlanSignalQuality, iRSSI);

						wprintf(L"  Security Enabled[%u]:\t ", j);
						if (pBssEntry->bSecurityEnabled)
							wprintf(L"Yes\n");
						else
							wprintf(L"No\n");

						wprintf(L"  Default AuthAlgorithm[%u]: ", j);
						switch (pBssEntry->dot11DefaultAuthAlgorithm) {
						case DOT11_AUTH_ALGO_80211_OPEN:
							wprintf(L"802.11 Open (%u)\n", pBssEntry->dot11DefaultAuthAlgorithm);
							break;
						case DOT11_AUTH_ALGO_80211_SHARED_KEY:
							wprintf(L"802.11 Shared (%u)\n", pBssEntry->dot11DefaultAuthAlgorithm);
							break;
						case DOT11_AUTH_ALGO_WPA:
							wprintf(L"WPA (%u)\n", pBssEntry->dot11DefaultAuthAlgorithm);
							break;
						case DOT11_AUTH_ALGO_WPA_PSK:
							wprintf(L"WPA-PSK (%u)\n", pBssEntry->dot11DefaultAuthAlgorithm);
							break;
						case DOT11_AUTH_ALGO_WPA_NONE:
							wprintf(L"WPA-None (%u)\n", pBssEntry->dot11DefaultAuthAlgorithm);
							break;
						case DOT11_AUTH_ALGO_RSNA:
							wprintf(L"RSNA (%u)\n", pBssEntry->dot11DefaultAuthAlgorithm);
							break;
						case DOT11_AUTH_ALGO_RSNA_PSK:
							wprintf(L"RSNA with PSK(%u)\n", pBssEntry->dot11DefaultAuthAlgorithm);
							break;
						default:
							wprintf(L"Other (%lu)\n", pBssEntry->dot11DefaultAuthAlgorithm);
							break;
						}

						wprintf(L"  Default CipherAlgorithm[%u]: ", j);
						switch (pBssEntry->dot11DefaultCipherAlgorithm) {
						case DOT11_CIPHER_ALGO_NONE:
							wprintf(L"None (0x%x)\n", pBssEntry->dot11DefaultCipherAlgorithm);
							break;
						case DOT11_CIPHER_ALGO_WEP40:
							wprintf(L"WEP-40 (0x%x)\n", pBssEntry->dot11DefaultCipherAlgorithm);
							break;
						case DOT11_CIPHER_ALGO_TKIP:
							wprintf(L"TKIP (0x%x)\n", pBssEntry->dot11DefaultCipherAlgorithm);
							break;
						case DOT11_CIPHER_ALGO_CCMP:
							wprintf(L"CCMP (0x%x)\n", pBssEntry->dot11DefaultCipherAlgorithm);
							break;
						case DOT11_CIPHER_ALGO_WEP104:
							wprintf(L"WEP-104 (0x%x)\n", pBssEntry->dot11DefaultCipherAlgorithm);
							break;
						case DOT11_CIPHER_ALGO_WEP:
							wprintf(L"WEP (0x%x)\n", pBssEntry->dot11DefaultCipherAlgorithm);
							break;
						default:
							wprintf(L"Other (0x%x)\n", pBssEntry->dot11DefaultCipherAlgorithm);
							break;
						}

						wprintf(L"  Flags[%u]:\t 0x%x", j, pBssEntry->dwFlags);
						if (pBssEntry->dwFlags) {
							if (pBssEntry->dwFlags & WLAN_AVAILABLE_NETWORK_CONNECTED)
								wprintf(L" - Currently connected");
							if (pBssEntry->dwFlags & WLAN_AVAILABLE_NETWORK_CONNECTED)
								wprintf(L" - Has profile");
						}
						wprintf(L"\n");

						wprintf(L"\n");
					}
				}
			}

		}
		if (pBssList != NULL) {
			WlanFreeMemory(pBssList);
			pBssList = NULL;
		}

		if (pIfList != NULL) {
			WlanFreeMemory(pIfList);
			pIfList = NULL;
		}
		cin.get();
			return dwRetVal;
	}
int WindowsWlan::Get_Wifi_Signal_As_Integer()
{
#ifndef UNICODE
#define UNICODE
#endif

	// Need to link with Wlanapi.lib and Ole32.lib
#pragma comment(lib, "wlanapi.lib")
#pragma comment(lib, "ole32.lib")


	// Declare and initialize variables.

	HANDLE hClient = 0;
	DWORD dwMaxClient = 2;      //    
	DWORD dwCurVersion = 0;
	DWORD dwResult = 0;
	DWORD dwRetVal = 0;
	int iRet = 0;

	WCHAR GuidString[39] = { 0 };

	unsigned int i = 0, j = 0, k = 0;

	/* variables used for WlanEnumInterfaces  */

	PWLAN_INTERFACE_INFO_LIST pIfList = 0;
	PWLAN_INTERFACE_INFO pIfInfo = 0;

	PWLAN_AVAILABLE_NETWORK_LIST pBssList = 0;
	PWLAN_AVAILABLE_NETWORK pBssEntry = 0;

	int GetiRSSI = 0;
	int iRSSI = 0;

	

	dwResult = WlanOpenHandle(dwMaxClient, NULL, &dwCurVersion, &hClient);
	if (dwResult != ERROR_SUCCESS) {
		//wprintf(L"WlanOpenHandle failed with error: %u\n", dwResult);
		// You can use FormatMessage here to find out why the function failed
	}

	dwResult = WlanEnumInterfaces(hClient, NULL, &pIfList);
	if (dwResult != ERROR_SUCCESS) {
		//wprintf(L"WlanEnumInterfaces failed with error: %u\n", dwResult);
		// You can use FormatMessage here to find out why the function failed
	}
	else {

		for (i = 0; i < (int)pIfList->dwNumberOfItems; i++) {
			pIfInfo = (WLAN_INTERFACE_INFO *)&pIfList->InterfaceInfo[i];
			//wprintf(L"  Interface Index[%u]:\t %lu\n", i, i);
			iRet = StringFromGUID2(pIfInfo->InterfaceGuid, (LPOLESTR)&GuidString,
				sizeof(GuidString) / sizeof(*GuidString));
			// For c rather than C++ source code, the above line needs to be
			// iRet = StringFromGUID2(&pIfInfo->InterfaceGuid, (LPOLESTR) &GuidString, 
			//     sizeof(GuidString)/sizeof(*GuidString)); 
			//wprintf(L"  Interface Description[%d]: %ws", i,
				//pIfInfo->strInterfaceDescription);
			//wprintf(L"\n");
			//wprintf(L"  Interface State[%d]:\t ", i);
			wprintf(L"");

			dwResult = WlanGetAvailableNetworkList(hClient,
				&pIfInfo->InterfaceGuid,
				0,
				NULL,
				&pBssList);

			if (dwResult != ERROR_SUCCESS) {
				//wprintf(L"WlanGetAvailableNetworkList failed with error: %u\n",
					//dwResult);
				dwRetVal = 1;
				// You can use FormatMessage to find out why the function failed
			}
			else {
				//wprintf(L"WLAN_AVAILABLE_NETWORK_LIST for this interface\n");


				for (j = 0; j < pBssList->dwNumberOfItems; j++) {
					pBssEntry =
						(WLAN_AVAILABLE_NETWORK *)& pBssList->Network[j];

					//wprintf(L"  Profile Name[%u]:  %ws\n", j, pBssEntry->strProfileName);

					//wprintf(L"  SSID[%u]:\t\t ", j);
					if (pBssEntry->dot11Ssid.uSSIDLength == 0)
						wprintf(L"\n");
					else {
						for (k = 0; k < pBssEntry->dot11Ssid.uSSIDLength; k++) {
							//wprintf(L"%c", (int)pBssEntry->dot11Ssid.ucSSID[k]);
						}
						//wprintf(L"\n");
					}

					//wprintf(L"  BSS Network type[%u]:\t ", j);
					switch (pBssEntry->dot11BssType) {
					case dot11_BSS_type_infrastructure:
						//wprintf(L"Infrastructure (%u)\n", pBssEntry->dot11BssType);
						break;
					case dot11_BSS_type_independent:
						//wprintf(L"Infrastructure (%u)\n", pBssEntry->dot11BssType);
						break;
					default:
						//wprintf(L"Other (%lu)\n", pBssEntry->dot11BssType);
						break;
					}

					//wprintf(L"  Number of BSSIDs[%u]:\t %u\n", j, pBssEntry->uNumberOfBssids);

					//wprintf(L"  Connectable[%u]:\t ", j);

					//wprintf(L"  Number of PHY types supported[%u]:\t %u\n", j, pBssEntry->uNumberOfPhyTypes);

					if (pBssEntry->wlanSignalQuality == 0)
						iRSSI = -100;
					else if (pBssEntry->wlanSignalQuality == 100)
						iRSSI = -50;
					else
						iRSSI = -100 + (pBssEntry->wlanSignalQuality / 2);
					//wprintf(L"  Signal Quality[%u]:\t %u (RSSI: %i dBm)\n", j,
						//pBssEntry->wlanSignalQuality, iRSSI);

					int GetiRSSI = 0;
					if (j == 0)
					{
						GetiRSSI = iRSSI;
						return GetiRSSI;
					}


					wprintf(L"  Security Enabled[%u]:\t ", j);
					if (pBssEntry->bSecurityEnabled)
						wprintf(L"Yes\n");
					else
						wprintf(L"No\n");

					wprintf(L"  Default AuthAlgorithm[%u]: ", j);
					switch (pBssEntry->dot11DefaultAuthAlgorithm) {
					case DOT11_AUTH_ALGO_80211_OPEN:
						wprintf(L"802.11 Open (%u)\n", pBssEntry->dot11DefaultAuthAlgorithm);
						break;
					case DOT11_AUTH_ALGO_80211_SHARED_KEY:
						wprintf(L"802.11 Shared (%u)\n", pBssEntry->dot11DefaultAuthAlgorithm);
						break;
					case DOT11_AUTH_ALGO_WPA:
						wprintf(L"WPA (%u)\n", pBssEntry->dot11DefaultAuthAlgorithm);
						break;
					case DOT11_AUTH_ALGO_WPA_PSK:
						wprintf(L"WPA-PSK (%u)\n", pBssEntry->dot11DefaultAuthAlgorithm);
						break;
					case DOT11_AUTH_ALGO_WPA_NONE:
						wprintf(L"WPA-None (%u)\n", pBssEntry->dot11DefaultAuthAlgorithm);
						break;
					case DOT11_AUTH_ALGO_RSNA:
						wprintf(L"RSNA (%u)\n", pBssEntry->dot11DefaultAuthAlgorithm);
						break;
					case DOT11_AUTH_ALGO_RSNA_PSK:
						wprintf(L"RSNA with PSK(%u)\n", pBssEntry->dot11DefaultAuthAlgorithm);
						break;
					default:
						wprintf(L"Other (%lu)\n", pBssEntry->dot11DefaultAuthAlgorithm);
						break;
					}

					wprintf(L"  Default CipherAlgorithm[%u]: ", j);
					switch (pBssEntry->dot11DefaultCipherAlgorithm) {
					case DOT11_CIPHER_ALGO_NONE:
						wprintf(L"None (0x%x)\n", pBssEntry->dot11DefaultCipherAlgorithm);
						break;
					case DOT11_CIPHER_ALGO_WEP40:
						wprintf(L"WEP-40 (0x%x)\n", pBssEntry->dot11DefaultCipherAlgorithm);
						break;
					case DOT11_CIPHER_ALGO_TKIP:
						wprintf(L"TKIP (0x%x)\n", pBssEntry->dot11DefaultCipherAlgorithm);
						break;
					case DOT11_CIPHER_ALGO_CCMP:
						wprintf(L"CCMP (0x%x)\n", pBssEntry->dot11DefaultCipherAlgorithm);
						break;
					case DOT11_CIPHER_ALGO_WEP104:
						wprintf(L"WEP-104 (0x%x)\n", pBssEntry->dot11DefaultCipherAlgorithm);
						break;
					case DOT11_CIPHER_ALGO_WEP:
						wprintf(L"WEP (0x%x)\n", pBssEntry->dot11DefaultCipherAlgorithm);
						break;
					default:
						wprintf(L"Other (0x%x)\n", pBssEntry->dot11DefaultCipherAlgorithm);
						break;
					}

					wprintf(L"  Flags[%u]:\t 0x%x", j, pBssEntry->dwFlags);
					if (pBssEntry->dwFlags) {
						if (pBssEntry->dwFlags & WLAN_AVAILABLE_NETWORK_CONNECTED)
							wprintf(L" - Currently connected");
						if (pBssEntry->dwFlags & WLAN_AVAILABLE_NETWORK_CONNECTED)
							wprintf(L" - Has profile");
					}
					wprintf(L"\n");

					wprintf(L"\n");
				}
			}
		}
		if (pBssList != NULL) {
			WlanFreeMemory(pBssList);
			pBssList = NULL;
		}

		if (pIfList != NULL) {
			WlanFreeMemory(pIfList);
			pIfList = NULL;
		}

			return GetiRSSI;
	}




}
string WindowsWlan::Get_Wifi_Signal_As_String(){
#ifndef UNICODE
#define UNICODE
#endif

	// Need to link with Wlanapi.lib and Ole32.lib
#pragma comment(lib, "wlanapi.lib")
#pragma comment(lib, "ole32.lib")


	// Declare and initialize variables.

	HANDLE hClient = 0;
	DWORD dwMaxClient = 2;      //    
	DWORD dwCurVersion = 0;
	DWORD dwResult = 0;
	DWORD dwRetVal = 0;
	int iRet = 0;

	WCHAR GuidString[39] = { 0 };

	unsigned int i = 0, j = 0, k = 0;

	/* variables used for WlanEnumInterfaces  */

	PWLAN_INTERFACE_INFO_LIST pIfList = 0;
	PWLAN_INTERFACE_INFO pIfInfo = 0;

	PWLAN_AVAILABLE_NETWORK_LIST pBssList = 0;
	PWLAN_AVAILABLE_NETWORK pBssEntry = 0;

	int GetiRSSI = 0;
	int iRSSI = 0;
	string GetiRSSIString = "";


	dwResult = WlanOpenHandle(dwMaxClient, NULL, &dwCurVersion, &hClient);
	if (dwResult != ERROR_SUCCESS) {
		//wprintf(L"WlanOpenHandle failed with error: %u\n", dwResult);
		// You can use FormatMessage here to find out why the function failed
	}

	dwResult = WlanEnumInterfaces(hClient, NULL, &pIfList);
	if (dwResult != ERROR_SUCCESS) {
		//wprintf(L"WlanEnumInterfaces failed with error: %u\n", dwResult);
		// You can use FormatMessage here to find out why the function failed
	}
	else {

		for (i = 0; i < (int)pIfList->dwNumberOfItems; i++) {
			pIfInfo = (WLAN_INTERFACE_INFO *)&pIfList->InterfaceInfo[i];
			//wprintf(L"  Interface Index[%u]:\t %lu\n", i, i);
			iRet = StringFromGUID2(pIfInfo->InterfaceGuid, (LPOLESTR)&GuidString,
				sizeof(GuidString) / sizeof(*GuidString));
			// For c rather than C++ source code, the above line needs to be
			// iRet = StringFromGUID2(&pIfInfo->InterfaceGuid, (LPOLESTR) &GuidString, 
			//     sizeof(GuidString)/sizeof(*GuidString)); 
			//wprintf(L"  Interface Description[%d]: %ws", i,
			//pIfInfo->strInterfaceDescription);
			//wprintf(L"\n");
			//wprintf(L"  Interface State[%d]:\t ", i);
			wprintf(L"");

			dwResult = WlanGetAvailableNetworkList(hClient,
				&pIfInfo->InterfaceGuid,
				0,
				NULL,
				&pBssList);

			if (dwResult != ERROR_SUCCESS) {
				//wprintf(L"WlanGetAvailableNetworkList failed with error: %u\n",
				//dwResult);
				dwRetVal = 1;
				// You can use FormatMessage to find out why the function failed
			}
			else {
				//wprintf(L"WLAN_AVAILABLE_NETWORK_LIST for this interface\n");


				for (j = 0; j < pBssList->dwNumberOfItems; j++) {
					pBssEntry =
						(WLAN_AVAILABLE_NETWORK *)& pBssList->Network[j];

					//wprintf(L"  Profile Name[%u]:  %ws\n", j, pBssEntry->strProfileName);

					//wprintf(L"  SSID[%u]:\t\t ", j);
					if (pBssEntry->dot11Ssid.uSSIDLength == 0)
						wprintf(L"\n");
					else {
						for (k = 0; k < pBssEntry->dot11Ssid.uSSIDLength; k++) {
							//wprintf(L"%c", (int)pBssEntry->dot11Ssid.ucSSID[k]);
						}
						//wprintf(L"\n");
					}

					//wprintf(L"  BSS Network type[%u]:\t ", j);
					switch (pBssEntry->dot11BssType) {
					case dot11_BSS_type_infrastructure:
						//wprintf(L"Infrastructure (%u)\n", pBssEntry->dot11BssType);
						break;
					case dot11_BSS_type_independent:
						//wprintf(L"Infrastructure (%u)\n", pBssEntry->dot11BssType);
						break;
					default:
						//wprintf(L"Other (%lu)\n", pBssEntry->dot11BssType);
						break;
					}

					//wprintf(L"  Number of BSSIDs[%u]:\t %u\n", j, pBssEntry->uNumberOfBssids);

					//wprintf(L"  Connectable[%u]:\t ", j);

					//wprintf(L"  Number of PHY types supported[%u]:\t %u\n", j, pBssEntry->uNumberOfPhyTypes);

					if (pBssEntry->wlanSignalQuality == 0)
						iRSSI = -100;
					else if (pBssEntry->wlanSignalQuality == 100)
						iRSSI = -50;
					else
						iRSSI = -100 + (pBssEntry->wlanSignalQuality / 2);
					//wprintf(L"  Signal Quality[%u]:\t %u (RSSI: %i dBm)\n", j,
					//pBssEntry->wlanSignalQuality, iRSSI);

				
					if (j == 0)
					{
						
						GetiRSSI = iRSSI;
						stringstream WifiIntegerToString;
						WifiIntegerToString << GetiRSSI;
						GetiRSSIString = WifiIntegerToString.str();
						return GetiRSSIString;
					}


					wprintf(L"  Security Enabled[%u]:\t ", j);
					if (pBssEntry->bSecurityEnabled)
						wprintf(L"Yes\n");
					else
						wprintf(L"No\n");

					wprintf(L"  Default AuthAlgorithm[%u]: ", j);
					switch (pBssEntry->dot11DefaultAuthAlgorithm) {
					case DOT11_AUTH_ALGO_80211_OPEN:
						wprintf(L"802.11 Open (%u)\n", pBssEntry->dot11DefaultAuthAlgorithm);
						break;
					case DOT11_AUTH_ALGO_80211_SHARED_KEY:
						wprintf(L"802.11 Shared (%u)\n", pBssEntry->dot11DefaultAuthAlgorithm);
						break;
					case DOT11_AUTH_ALGO_WPA:
						wprintf(L"WPA (%u)\n", pBssEntry->dot11DefaultAuthAlgorithm);
						break;
					case DOT11_AUTH_ALGO_WPA_PSK:
						wprintf(L"WPA-PSK (%u)\n", pBssEntry->dot11DefaultAuthAlgorithm);
						break;
					case DOT11_AUTH_ALGO_WPA_NONE:
						wprintf(L"WPA-None (%u)\n", pBssEntry->dot11DefaultAuthAlgorithm);
						break;
					case DOT11_AUTH_ALGO_RSNA:
						wprintf(L"RSNA (%u)\n", pBssEntry->dot11DefaultAuthAlgorithm);
						break;
					case DOT11_AUTH_ALGO_RSNA_PSK:
						wprintf(L"RSNA with PSK(%u)\n", pBssEntry->dot11DefaultAuthAlgorithm);
						break;
					default:
						wprintf(L"Other (%lu)\n", pBssEntry->dot11DefaultAuthAlgorithm);
						break;
					}

					wprintf(L"  Default CipherAlgorithm[%u]: ", j);
					switch (pBssEntry->dot11DefaultCipherAlgorithm) {
					case DOT11_CIPHER_ALGO_NONE:
						wprintf(L"None (0x%x)\n", pBssEntry->dot11DefaultCipherAlgorithm);
						break;
					case DOT11_CIPHER_ALGO_WEP40:
						wprintf(L"WEP-40 (0x%x)\n", pBssEntry->dot11DefaultCipherAlgorithm);
						break;
					case DOT11_CIPHER_ALGO_TKIP:
						wprintf(L"TKIP (0x%x)\n", pBssEntry->dot11DefaultCipherAlgorithm);
						break;
					case DOT11_CIPHER_ALGO_CCMP:
						wprintf(L"CCMP (0x%x)\n", pBssEntry->dot11DefaultCipherAlgorithm);
						break;
					case DOT11_CIPHER_ALGO_WEP104:
						wprintf(L"WEP-104 (0x%x)\n", pBssEntry->dot11DefaultCipherAlgorithm);
						break;
					case DOT11_CIPHER_ALGO_WEP:
						wprintf(L"WEP (0x%x)\n", pBssEntry->dot11DefaultCipherAlgorithm);
						break;
					default:
						wprintf(L"Other (0x%x)\n", pBssEntry->dot11DefaultCipherAlgorithm);
						break;
					}

					wprintf(L"  Flags[%u]:\t 0x%x", j, pBssEntry->dwFlags);
					if (pBssEntry->dwFlags) {
						if (pBssEntry->dwFlags & WLAN_AVAILABLE_NETWORK_CONNECTED)
							wprintf(L" - Currently connected");
						if (pBssEntry->dwFlags & WLAN_AVAILABLE_NETWORK_CONNECTED)
							wprintf(L" - Has profile");
					}
					wprintf(L"\n");

					wprintf(L"\n");
				}
			}
		}
		if (pBssList != NULL) {
			WlanFreeMemory(pBssList);
			pBssList = NULL;
		}

		if (pIfList != NULL) {
			WlanFreeMemory(pIfList);
			pIfList = NULL;
		}

		return GetiRSSIString;
	}
}
int WindowsWlan::Get_Other_Wifi_Signal_Geo()
{
#ifndef UNICODE
#define UNICODE
#endif

	// Need to link with Wlanapi.lib and Ole32.lib
#pragma comment(lib, "wlanapi.lib")
#pragma comment(lib, "ole32.lib")

	// Declare and initialize variables.

	HANDLE hClient = NULL;
	DWORD dwMaxClient = 2;      //    
	DWORD dwCurVersion = 0;
	DWORD dwResult = 0;
	DWORD dwRetVal = 0;
	int iRet = 0;

	WCHAR GuidString[39] = { 0 };

	unsigned int i, j, k;

	/* variables used for WlanEnumInterfaces  */

	PWLAN_INTERFACE_INFO_LIST pIfList = NULL;
	PWLAN_INTERFACE_INFO pIfInfo = NULL;

	PWLAN_AVAILABLE_NETWORK_LIST pBssList = NULL;
	PWLAN_AVAILABLE_NETWORK pBssEntry = NULL;

	int GetiRSSI = 0;
	int iRSSI = 0;



	dwResult = WlanOpenHandle(dwMaxClient, NULL, &dwCurVersion, &hClient);
	if (dwResult != ERROR_SUCCESS) {
		//wprintf(L"WlanOpenHandle failed with error: %u\n", dwResult);
		// You can use FormatMessage here to find out why the function failed
	}

	dwResult = WlanEnumInterfaces(hClient, NULL, &pIfList);
	if (dwResult != ERROR_SUCCESS) {
		//wprintf(L"WlanEnumInterfaces failed with error: %u\n", dwResult);
		// You can use FormatMessage here to find out why the function failed
	}
	else {

		for (i = 0; i < (int)pIfList->dwNumberOfItems; i++) {
			pIfInfo = (WLAN_INTERFACE_INFO *)&pIfList->InterfaceInfo[i];
			//wprintf(L"  Interface Index[%u]:\t %lu\n", i, i);
			iRet = StringFromGUID2(pIfInfo->InterfaceGuid, (LPOLESTR)&GuidString,
				sizeof(GuidString) / sizeof(*GuidString));
			// For c rather than C++ source code, the above line needs to be
			// iRet = StringFromGUID2(&pIfInfo->InterfaceGuid, (LPOLESTR) &GuidString, 
			//     sizeof(GuidString)/sizeof(*GuidString)); 
			//wprintf(L"  Interface Description[%d]: %ws", i,
			//pIfInfo->strInterfaceDescription);
			//wprintf(L"\n");
			//wprintf(L"  Interface State[%d]:\t ", i);
			wprintf(L"");

			dwResult = WlanGetAvailableNetworkList(hClient,
				&pIfInfo->InterfaceGuid,
				0,
				NULL,
				&pBssList);

			if (dwResult != ERROR_SUCCESS) {
				//wprintf(L"WlanGetAvailableNetworkList failed with error: %u\n",
				//dwResult);
				dwRetVal = 1;
				// You can use FormatMessage to find out why the function failed
			}
			else {
				//wprintf(L"WLAN_AVAILABLE_NETWORK_LIST for this interface\n");


				for (j = 2; j < pBssList->dwNumberOfItems; j++) {
					pBssEntry =
						(WLAN_AVAILABLE_NETWORK *)& pBssList->Network[j];

					//wprintf(L"  Profile Name[%u]:  %ws\n", j, pBssEntry->strProfileName);

					//wprintf(L"  SSID[%u]:\t\t ", j);
					if (pBssEntry->dot11Ssid.uSSIDLength == 0)
						wprintf(L"\n");
					else {
						for (k = 0; k < pBssEntry->dot11Ssid.uSSIDLength; k++) {
							//wprintf(L"%c", (int)pBssEntry->dot11Ssid.ucSSID[k]);
						}
						//wprintf(L"\n");
					}

					//wprintf(L"  BSS Network type[%u]:\t ", j);
					switch (pBssEntry->dot11BssType) {
					case dot11_BSS_type_infrastructure:
						//wprintf(L"Infrastructure (%u)\n", pBssEntry->dot11BssType);
						break;
					case dot11_BSS_type_independent:
						//wprintf(L"Infrastructure (%u)\n", pBssEntry->dot11BssType);
						break;
					default:
						//wprintf(L"Other (%lu)\n", pBssEntry->dot11BssType);
						break;
					}

					//wprintf(L"  Number of BSSIDs[%u]:\t %u\n", j, pBssEntry->uNumberOfBssids);

					//wprintf(L"  Connectable[%u]:\t ", j);

					//wprintf(L"  Number of PHY types supported[%u]:\t %u\n", j, pBssEntry->uNumberOfPhyTypes);

					if (pBssEntry->wlanSignalQuality == 0)
						iRSSI = -100;
					else if (pBssEntry->wlanSignalQuality == 100)
						iRSSI = -50;
					else
						iRSSI = -100 + (pBssEntry->wlanSignalQuality / 2);
					//wprintf(L"  Signal Quality[%u]:\t %u (RSSI: %i dBm)\n", j,
					//pBssEntry->wlanSignalQuality, iRSSI);

					int GetiRSSI = 0;
					if (j == 2)
					{
						GetiRSSI = iRSSI;
						return GetiRSSI;
					}


					wprintf(L"  Security Enabled[%u]:\t ", j);
					if (pBssEntry->bSecurityEnabled)
						wprintf(L"Yes\n");
					else
						wprintf(L"No\n");

					wprintf(L"  Default AuthAlgorithm[%u]: ", j);
					switch (pBssEntry->dot11DefaultAuthAlgorithm) {
					case DOT11_AUTH_ALGO_80211_OPEN:
						wprintf(L"802.11 Open (%u)\n", pBssEntry->dot11DefaultAuthAlgorithm);
						break;
					case DOT11_AUTH_ALGO_80211_SHARED_KEY:
						wprintf(L"802.11 Shared (%u)\n", pBssEntry->dot11DefaultAuthAlgorithm);
						break;
					case DOT11_AUTH_ALGO_WPA:
						wprintf(L"WPA (%u)\n", pBssEntry->dot11DefaultAuthAlgorithm);
						break;
					case DOT11_AUTH_ALGO_WPA_PSK:
						wprintf(L"WPA-PSK (%u)\n", pBssEntry->dot11DefaultAuthAlgorithm);
						break;
					case DOT11_AUTH_ALGO_WPA_NONE:
						wprintf(L"WPA-None (%u)\n", pBssEntry->dot11DefaultAuthAlgorithm);
						break;
					case DOT11_AUTH_ALGO_RSNA:
						wprintf(L"RSNA (%u)\n", pBssEntry->dot11DefaultAuthAlgorithm);
						break;
					case DOT11_AUTH_ALGO_RSNA_PSK:
						wprintf(L"RSNA with PSK(%u)\n", pBssEntry->dot11DefaultAuthAlgorithm);
						break;
					default:
						wprintf(L"Other (%lu)\n", pBssEntry->dot11DefaultAuthAlgorithm);
						break;
					}

					wprintf(L"  Default CipherAlgorithm[%u]: ", j);
					switch (pBssEntry->dot11DefaultCipherAlgorithm) {
					case DOT11_CIPHER_ALGO_NONE:
						wprintf(L"None (0x%x)\n", pBssEntry->dot11DefaultCipherAlgorithm);
						break;
					case DOT11_CIPHER_ALGO_WEP40:
						wprintf(L"WEP-40 (0x%x)\n", pBssEntry->dot11DefaultCipherAlgorithm);
						break;
					case DOT11_CIPHER_ALGO_TKIP:
						wprintf(L"TKIP (0x%x)\n", pBssEntry->dot11DefaultCipherAlgorithm);
						break;
					case DOT11_CIPHER_ALGO_CCMP:
						wprintf(L"CCMP (0x%x)\n", pBssEntry->dot11DefaultCipherAlgorithm);
						break;
					case DOT11_CIPHER_ALGO_WEP104:
						wprintf(L"WEP-104 (0x%x)\n", pBssEntry->dot11DefaultCipherAlgorithm);
						break;
					case DOT11_CIPHER_ALGO_WEP:
						wprintf(L"WEP (0x%x)\n", pBssEntry->dot11DefaultCipherAlgorithm);
						break;
					default:
						wprintf(L"Other (0x%x)\n", pBssEntry->dot11DefaultCipherAlgorithm);
						break;
					}

					wprintf(L"  Flags[%u]:\t 0x%x", j, pBssEntry->dwFlags);
					if (pBssEntry->dwFlags) {
						if (pBssEntry->dwFlags & WLAN_AVAILABLE_NETWORK_CONNECTED)
							wprintf(L" - Currently connected");
						if (pBssEntry->dwFlags & WLAN_AVAILABLE_NETWORK_CONNECTED)
							wprintf(L" - Has profile");
					}
					wprintf(L"\n");

					wprintf(L"\n");
				}
			}
		}
		if (pBssList != NULL) {
			WlanFreeMemory(pBssList);
			pBssList = NULL;
		}

		if (pIfList != NULL) {
			WlanFreeMemory(pIfList);
			pIfList = NULL;
		}

		return GetiRSSI;
	}


}
int WindowsWlan::Get_Other_Wifi_Signal_Geo2()
{
#ifndef UNICODE
#define UNICODE
#endif

	// Need to link with Wlanapi.lib and Ole32.lib
#pragma comment(lib, "wlanapi.lib")
#pragma comment(lib, "ole32.lib")


	// Declare and initialize variables.

	HANDLE hClient = NULL;
	DWORD dwMaxClient = 2;      //    
	DWORD dwCurVersion = 0;
	DWORD dwResult = 0;
	DWORD dwRetVal = 0;
	int iRet = 0;

	WCHAR GuidString[39] = { 0 };

	unsigned int i, j, k;

	/* variables used for WlanEnumInterfaces  */

	PWLAN_INTERFACE_INFO_LIST pIfList = NULL;
	PWLAN_INTERFACE_INFO pIfInfo = NULL;

	PWLAN_AVAILABLE_NETWORK_LIST pBssList = NULL;
	PWLAN_AVAILABLE_NETWORK pBssEntry = NULL;

	int GetiRSSI = 0;
	int iRSSI = 0;



	dwResult = WlanOpenHandle(dwMaxClient, NULL, &dwCurVersion, &hClient);
	if (dwResult != ERROR_SUCCESS) {
		//wprintf(L"WlanOpenHandle failed with error: %u\n", dwResult);
		// You can use FormatMessage here to find out why the function failed
	}

	dwResult = WlanEnumInterfaces(hClient, NULL, &pIfList);
	if (dwResult != ERROR_SUCCESS) {
		//wprintf(L"WlanEnumInterfaces failed with error: %u\n", dwResult);
		// You can use FormatMessage here to find out why the function failed
	}
	else {

		for (i = 0; i < (int)pIfList->dwNumberOfItems; i++) {
			pIfInfo = (WLAN_INTERFACE_INFO *)&pIfList->InterfaceInfo[i];
			//wprintf(L"  Interface Index[%u]:\t %lu\n", i, i);
			iRet = StringFromGUID2(pIfInfo->InterfaceGuid, (LPOLESTR)&GuidString,
				sizeof(GuidString) / sizeof(*GuidString));
			// For c rather than C++ source code, the above line needs to be
			// iRet = StringFromGUID2(&pIfInfo->InterfaceGuid, (LPOLESTR) &GuidString, 
			//     sizeof(GuidString)/sizeof(*GuidString)); 
			//wprintf(L"  Interface Description[%d]: %ws", i,
			//pIfInfo->strInterfaceDescription);
			//wprintf(L"\n");
			//wprintf(L"  Interface State[%d]:\t ", i);
			wprintf(L"");

			dwResult = WlanGetAvailableNetworkList(hClient,
				&pIfInfo->InterfaceGuid,
				0,
				NULL,
				&pBssList);

			if (dwResult != ERROR_SUCCESS) {
				//wprintf(L"WlanGetAvailableNetworkList failed with error: %u\n",
				//dwResult);
				dwRetVal = 1;
				// You can use FormatMessage to find out why the function failed
			}
			else {
				//wprintf(L"WLAN_AVAILABLE_NETWORK_LIST for this interface\n");


				for (j = 3; j < pBssList->dwNumberOfItems; j++) {
					pBssEntry =
						(WLAN_AVAILABLE_NETWORK *)& pBssList->Network[j];

					//wprintf(L"  Profile Name[%u]:  %ws\n", j, pBssEntry->strProfileName);

					//wprintf(L"  SSID[%u]:\t\t ", j);
					if (pBssEntry->dot11Ssid.uSSIDLength == 0)
						wprintf(L"\n");
					else {
						for (k = 0; k < pBssEntry->dot11Ssid.uSSIDLength; k++) {
							//wprintf(L"%c", (int)pBssEntry->dot11Ssid.ucSSID[k]);
						}
						//wprintf(L"\n");
					}

					//wprintf(L"  BSS Network type[%u]:\t ", j);
					switch (pBssEntry->dot11BssType) {
					case dot11_BSS_type_infrastructure:
						//wprintf(L"Infrastructure (%u)\n", pBssEntry->dot11BssType);
						break;
					case dot11_BSS_type_independent:
						//wprintf(L"Infrastructure (%u)\n", pBssEntry->dot11BssType);
						break;
					default:
						//wprintf(L"Other (%lu)\n", pBssEntry->dot11BssType);
						break;
					}

					//wprintf(L"  Number of BSSIDs[%u]:\t %u\n", j, pBssEntry->uNumberOfBssids);

					//wprintf(L"  Connectable[%u]:\t ", j);

					//wprintf(L"  Number of PHY types supported[%u]:\t %u\n", j, pBssEntry->uNumberOfPhyTypes);

					if (pBssEntry->wlanSignalQuality == 0)
						iRSSI = -100;
					else if (pBssEntry->wlanSignalQuality == 100)
						iRSSI = -50;
					else
						iRSSI = -100 + (pBssEntry->wlanSignalQuality / 2);
					//wprintf(L"  Signal Quality[%u]:\t %u (RSSI: %i dBm)\n", j,
					//pBssEntry->wlanSignalQuality, iRSSI);

					int GetiRSSI = 0;
					if (j == 3)
					{
						GetiRSSI = iRSSI;
						return GetiRSSI;
					}


					wprintf(L"  Security Enabled[%u]:\t ", j);
					if (pBssEntry->bSecurityEnabled)
						wprintf(L"Yes\n");
					else
						wprintf(L"No\n");

					wprintf(L"  Default AuthAlgorithm[%u]: ", j);
					switch (pBssEntry->dot11DefaultAuthAlgorithm) {
					case DOT11_AUTH_ALGO_80211_OPEN:
						wprintf(L"802.11 Open (%u)\n", pBssEntry->dot11DefaultAuthAlgorithm);
						break;
					case DOT11_AUTH_ALGO_80211_SHARED_KEY:
						wprintf(L"802.11 Shared (%u)\n", pBssEntry->dot11DefaultAuthAlgorithm);
						break;
					case DOT11_AUTH_ALGO_WPA:
						wprintf(L"WPA (%u)\n", pBssEntry->dot11DefaultAuthAlgorithm);
						break;
					case DOT11_AUTH_ALGO_WPA_PSK:
						wprintf(L"WPA-PSK (%u)\n", pBssEntry->dot11DefaultAuthAlgorithm);
						break;
					case DOT11_AUTH_ALGO_WPA_NONE:
						wprintf(L"WPA-None (%u)\n", pBssEntry->dot11DefaultAuthAlgorithm);
						break;
					case DOT11_AUTH_ALGO_RSNA:
						wprintf(L"RSNA (%u)\n", pBssEntry->dot11DefaultAuthAlgorithm);
						break;
					case DOT11_AUTH_ALGO_RSNA_PSK:
						wprintf(L"RSNA with PSK(%u)\n", pBssEntry->dot11DefaultAuthAlgorithm);
						break;
					default:
						wprintf(L"Other (%lu)\n", pBssEntry->dot11DefaultAuthAlgorithm);
						break;
					}

					wprintf(L"  Default CipherAlgorithm[%u]: ", j);
					switch (pBssEntry->dot11DefaultCipherAlgorithm) {
					case DOT11_CIPHER_ALGO_NONE:
						wprintf(L"None (0x%x)\n", pBssEntry->dot11DefaultCipherAlgorithm);
						break;
					case DOT11_CIPHER_ALGO_WEP40:
						wprintf(L"WEP-40 (0x%x)\n", pBssEntry->dot11DefaultCipherAlgorithm);
						break;
					case DOT11_CIPHER_ALGO_TKIP:
						wprintf(L"TKIP (0x%x)\n", pBssEntry->dot11DefaultCipherAlgorithm);
						break;
					case DOT11_CIPHER_ALGO_CCMP:
						wprintf(L"CCMP (0x%x)\n", pBssEntry->dot11DefaultCipherAlgorithm);
						break;
					case DOT11_CIPHER_ALGO_WEP104:
						wprintf(L"WEP-104 (0x%x)\n", pBssEntry->dot11DefaultCipherAlgorithm);
						break;
					case DOT11_CIPHER_ALGO_WEP:
						wprintf(L"WEP (0x%x)\n", pBssEntry->dot11DefaultCipherAlgorithm);
						break;
					default:
						wprintf(L"Other (0x%x)\n", pBssEntry->dot11DefaultCipherAlgorithm);
						break;
					}

					wprintf(L"  Flags[%u]:\t 0x%x", j, pBssEntry->dwFlags);
					if (pBssEntry->dwFlags) {
						if (pBssEntry->dwFlags & WLAN_AVAILABLE_NETWORK_CONNECTED)
							wprintf(L" - Currently connected");
						if (pBssEntry->dwFlags & WLAN_AVAILABLE_NETWORK_CONNECTED)
							wprintf(L" - Has profile");
					}
					wprintf(L"\n");

					wprintf(L"\n");
				}
			}
		}
		if (pBssList != NULL) {
			WlanFreeMemory(pBssList);
			pBssList = NULL;
		}

		if (pIfList != NULL) {
			WlanFreeMemory(pIfList);
			pIfList = NULL;
		}

		return GetiRSSI;
	}


}
int WindowsWlan::Get_Other_Wifi_Signal_Geo3()
{
#ifndef UNICODE
#define UNICODE
#endif

	// Need to link with Wlanapi.lib and Ole32.lib
#pragma comment(lib, "wlanapi.lib")
#pragma comment(lib, "ole32.lib")


	// Declare and initialize variables.

	HANDLE hClient = NULL;
	DWORD dwMaxClient = 2;      //    
	DWORD dwCurVersion = 0;
	DWORD dwResult = 0;
	DWORD dwRetVal = 0;
	int iRet = 0;

	WCHAR GuidString[39] = { 0 };

	unsigned int i, j, k;

	/* variables used for WlanEnumInterfaces  */

	PWLAN_INTERFACE_INFO_LIST pIfList = NULL;
	PWLAN_INTERFACE_INFO pIfInfo = NULL;

	PWLAN_AVAILABLE_NETWORK_LIST pBssList = NULL;
	PWLAN_AVAILABLE_NETWORK pBssEntry = NULL;

	int GetiRSSI = 0;
	int iRSSI = 0;



	dwResult = WlanOpenHandle(dwMaxClient, NULL, &dwCurVersion, &hClient);
	if (dwResult != ERROR_SUCCESS) {
		//wprintf(L"WlanOpenHandle failed with error: %u\n", dwResult);
		// You can use FormatMessage here to find out why the function failed
	}

	dwResult = WlanEnumInterfaces(hClient, NULL, &pIfList);
	if (dwResult != ERROR_SUCCESS) {
		//wprintf(L"WlanEnumInterfaces failed with error: %u\n", dwResult);
		// You can use FormatMessage here to find out why the function failed
	}
	else {

		for (i = 0; i < (int)pIfList->dwNumberOfItems; i++) {
			pIfInfo = (WLAN_INTERFACE_INFO *)&pIfList->InterfaceInfo[i];
			//wprintf(L"  Interface Index[%u]:\t %lu\n", i, i);
			iRet = StringFromGUID2(pIfInfo->InterfaceGuid, (LPOLESTR)&GuidString,
				sizeof(GuidString) / sizeof(*GuidString));
			// For c rather than C++ source code, the above line needs to be
			// iRet = StringFromGUID2(&pIfInfo->InterfaceGuid, (LPOLESTR) &GuidString, 
			//     sizeof(GuidString)/sizeof(*GuidString)); 
			//wprintf(L"  Interface Description[%d]: %ws", i,
			//pIfInfo->strInterfaceDescription);
			//wprintf(L"\n");
			//wprintf(L"  Interface State[%d]:\t ", i);
			wprintf(L"");

			dwResult = WlanGetAvailableNetworkList(hClient,
				&pIfInfo->InterfaceGuid,
				0,
				NULL,
				&pBssList);

			if (dwResult != ERROR_SUCCESS) {
				//wprintf(L"WlanGetAvailableNetworkList failed with error: %u\n",
				//dwResult);
				dwRetVal = 1;
				// You can use FormatMessage to find out why the function failed
			}
			else {
				//wprintf(L"WLAN_AVAILABLE_NETWORK_LIST for this interface\n");


				for (j = 4; j < pBssList->dwNumberOfItems; j++) {
					pBssEntry =
						(WLAN_AVAILABLE_NETWORK *)& pBssList->Network[j];

					//wprintf(L"  Profile Name[%u]:  %ws\n", j, pBssEntry->strProfileName);

					//wprintf(L"  SSID[%u]:\t\t ", j);
					if (pBssEntry->dot11Ssid.uSSIDLength == 0)
						wprintf(L"\n");
					else {
						for (k = 0; k < pBssEntry->dot11Ssid.uSSIDLength; k++) {
							//wprintf(L"%c", (int)pBssEntry->dot11Ssid.ucSSID[k]);
						}
						//wprintf(L"\n");
					}

					//wprintf(L"  BSS Network type[%u]:\t ", j);
					switch (pBssEntry->dot11BssType) {
					case dot11_BSS_type_infrastructure:
						//wprintf(L"Infrastructure (%u)\n", pBssEntry->dot11BssType);
						break;
					case dot11_BSS_type_independent:
						//wprintf(L"Infrastructure (%u)\n", pBssEntry->dot11BssType);
						break;
					default:
						//wprintf(L"Other (%lu)\n", pBssEntry->dot11BssType);
						break;
					}

					//wprintf(L"  Number of BSSIDs[%u]:\t %u\n", j, pBssEntry->uNumberOfBssids);

					//wprintf(L"  Connectable[%u]:\t ", j);

					//wprintf(L"  Number of PHY types supported[%u]:\t %u\n", j, pBssEntry->uNumberOfPhyTypes);

					if (pBssEntry->wlanSignalQuality == 0)
						iRSSI = -100;
					else if (pBssEntry->wlanSignalQuality == 100)
						iRSSI = -50;
					else
						iRSSI = -100 + (pBssEntry->wlanSignalQuality / 2);
					//wprintf(L"  Signal Quality[%u]:\t %u (RSSI: %i dBm)\n", j,
					//pBssEntry->wlanSignalQuality, iRSSI);

					int GetiRSSI = 0;
					if (j == 4)
					{
						GetiRSSI = iRSSI;
						return GetiRSSI;
					}


					wprintf(L"  Security Enabled[%u]:\t ", j);
					if (pBssEntry->bSecurityEnabled)
						wprintf(L"Yes\n");
					else
						wprintf(L"No\n");

					wprintf(L"  Default AuthAlgorithm[%u]: ", j);
					switch (pBssEntry->dot11DefaultAuthAlgorithm) {
					case DOT11_AUTH_ALGO_80211_OPEN:
						wprintf(L"802.11 Open (%u)\n", pBssEntry->dot11DefaultAuthAlgorithm);
						break;
					case DOT11_AUTH_ALGO_80211_SHARED_KEY:
						wprintf(L"802.11 Shared (%u)\n", pBssEntry->dot11DefaultAuthAlgorithm);
						break;
					case DOT11_AUTH_ALGO_WPA:
						wprintf(L"WPA (%u)\n", pBssEntry->dot11DefaultAuthAlgorithm);
						break;
					case DOT11_AUTH_ALGO_WPA_PSK:
						wprintf(L"WPA-PSK (%u)\n", pBssEntry->dot11DefaultAuthAlgorithm);
						break;
					case DOT11_AUTH_ALGO_WPA_NONE:
						wprintf(L"WPA-None (%u)\n", pBssEntry->dot11DefaultAuthAlgorithm);
						break;
					case DOT11_AUTH_ALGO_RSNA:
						wprintf(L"RSNA (%u)\n", pBssEntry->dot11DefaultAuthAlgorithm);
						break;
					case DOT11_AUTH_ALGO_RSNA_PSK:
						wprintf(L"RSNA with PSK(%u)\n", pBssEntry->dot11DefaultAuthAlgorithm);
						break;
					default:
						wprintf(L"Other (%lu)\n", pBssEntry->dot11DefaultAuthAlgorithm);
						break;
					}

					wprintf(L"  Default CipherAlgorithm[%u]: ", j);
					switch (pBssEntry->dot11DefaultCipherAlgorithm) {
					case DOT11_CIPHER_ALGO_NONE:
						wprintf(L"None (0x%x)\n", pBssEntry->dot11DefaultCipherAlgorithm);
						break;
					case DOT11_CIPHER_ALGO_WEP40:
						wprintf(L"WEP-40 (0x%x)\n", pBssEntry->dot11DefaultCipherAlgorithm);
						break;
					case DOT11_CIPHER_ALGO_TKIP:
						wprintf(L"TKIP (0x%x)\n", pBssEntry->dot11DefaultCipherAlgorithm);
						break;
					case DOT11_CIPHER_ALGO_CCMP:
						wprintf(L"CCMP (0x%x)\n", pBssEntry->dot11DefaultCipherAlgorithm);
						break;
					case DOT11_CIPHER_ALGO_WEP104:
						wprintf(L"WEP-104 (0x%x)\n", pBssEntry->dot11DefaultCipherAlgorithm);
						break;
					case DOT11_CIPHER_ALGO_WEP:
						wprintf(L"WEP (0x%x)\n", pBssEntry->dot11DefaultCipherAlgorithm);
						break;
					default:
						wprintf(L"Other (0x%x)\n", pBssEntry->dot11DefaultCipherAlgorithm);
						break;
					}

					wprintf(L"  Flags[%u]:\t 0x%x", j, pBssEntry->dwFlags);
					if (pBssEntry->dwFlags) {
						if (pBssEntry->dwFlags & WLAN_AVAILABLE_NETWORK_CONNECTED)
							wprintf(L" - Currently connected");
						if (pBssEntry->dwFlags & WLAN_AVAILABLE_NETWORK_CONNECTED)
							wprintf(L" - Has profile");
					}
					wprintf(L"\n");

					wprintf(L"\n");
				}
			}
		}
		if (pBssList != NULL) {
			WlanFreeMemory(pBssList);
			pBssList = NULL;
		}

		if (pIfList != NULL) {
			WlanFreeMemory(pIfList);
			pIfList = NULL;
		}

		return GetiRSSI;
	}


}
int WindowsWlan::Get_Other_Wifi_Signal_Geo4()
{
#ifndef UNICODE
#define UNICODE
#endif

	// Need to link with Wlanapi.lib and Ole32.lib
#pragma comment(lib, "wlanapi.lib")
#pragma comment(lib, "ole32.lib")


	// Declare and initialize variables.

	HANDLE hClient = NULL;
	DWORD dwMaxClient = 2;      //    
	DWORD dwCurVersion = 0;
	DWORD dwResult = 0;
	DWORD dwRetVal = 0;
	int iRet = 0;

	WCHAR GuidString[39] = { 0 };

	unsigned int i, j, k;

	/* variables used for WlanEnumInterfaces  */

	PWLAN_INTERFACE_INFO_LIST pIfList = NULL;
	PWLAN_INTERFACE_INFO pIfInfo = NULL;

	PWLAN_AVAILABLE_NETWORK_LIST pBssList = NULL;
	PWLAN_AVAILABLE_NETWORK pBssEntry = NULL;

	int GetiRSSI = 0;
	int iRSSI = 0;



	dwResult = WlanOpenHandle(dwMaxClient, NULL, &dwCurVersion, &hClient);
	if (dwResult != ERROR_SUCCESS) {
		//wprintf(L"WlanOpenHandle failed with error: %u\n", dwResult);
		// You can use FormatMessage here to find out why the function failed
	}

	dwResult = WlanEnumInterfaces(hClient, NULL, &pIfList);
	if (dwResult != ERROR_SUCCESS) {
		//wprintf(L"WlanEnumInterfaces failed with error: %u\n", dwResult);
		// You can use FormatMessage here to find out why the function failed
	}
	else {

		for (i = 0; i < (int)pIfList->dwNumberOfItems; i++) {
			pIfInfo = (WLAN_INTERFACE_INFO *)&pIfList->InterfaceInfo[i];
			//wprintf(L"  Interface Index[%u]:\t %lu\n", i, i);
			iRet = StringFromGUID2(pIfInfo->InterfaceGuid, (LPOLESTR)&GuidString,
				sizeof(GuidString) / sizeof(*GuidString));
			// For c rather than C++ source code, the above line needs to be
			// iRet = StringFromGUID2(&pIfInfo->InterfaceGuid, (LPOLESTR) &GuidString, 
			//     sizeof(GuidString)/sizeof(*GuidString)); 
			//wprintf(L"  Interface Description[%d]: %ws", i,
			//pIfInfo->strInterfaceDescription);
			//wprintf(L"\n");
			//wprintf(L"  Interface State[%d]:\t ", i);
			wprintf(L"");

			dwResult = WlanGetAvailableNetworkList(hClient,
				&pIfInfo->InterfaceGuid,
				0,
				NULL,
				&pBssList);

			if (dwResult != ERROR_SUCCESS) {
				//wprintf(L"WlanGetAvailableNetworkList failed with error: %u\n",
				//dwResult);
				dwRetVal = 1;
				// You can use FormatMessage to find out why the function failed
			}
			else {
				//wprintf(L"WLAN_AVAILABLE_NETWORK_LIST for this interface\n");


				for (j = 4; j < pBssList->dwNumberOfItems; j++) {
					pBssEntry =
						(WLAN_AVAILABLE_NETWORK *)& pBssList->Network[j];

					//wprintf(L"  Profile Name[%u]:  %ws\n", j, pBssEntry->strProfileName);

					//wprintf(L"  SSID[%u]:\t\t ", j);
					if (pBssEntry->dot11Ssid.uSSIDLength == 0)
						wprintf(L"\n");
					else {
						for (k = 0; k < pBssEntry->dot11Ssid.uSSIDLength; k++) {
							//wprintf(L"%c", (int)pBssEntry->dot11Ssid.ucSSID[k]);
						}
						//wprintf(L"\n");
					}

					//wprintf(L"  BSS Network type[%u]:\t ", j);
					switch (pBssEntry->dot11BssType) {
					case dot11_BSS_type_infrastructure:
						//wprintf(L"Infrastructure (%u)\n", pBssEntry->dot11BssType);
						break;
					case dot11_BSS_type_independent:
						//wprintf(L"Infrastructure (%u)\n", pBssEntry->dot11BssType);
						break;
					default:
						//wprintf(L"Other (%lu)\n", pBssEntry->dot11BssType);
						break;
					}

					//wprintf(L"  Number of BSSIDs[%u]:\t %u\n", j, pBssEntry->uNumberOfBssids);

					//wprintf(L"  Connectable[%u]:\t ", j);

					//wprintf(L"  Number of PHY types supported[%u]:\t %u\n", j, pBssEntry->uNumberOfPhyTypes);

					if (pBssEntry->wlanSignalQuality == 0)
						iRSSI = -100;
					else if (pBssEntry->wlanSignalQuality == 100)
						iRSSI = -50;
					else
						iRSSI = -100 + (pBssEntry->wlanSignalQuality / 2);
					//wprintf(L"  Signal Quality[%u]:\t %u (RSSI: %i dBm)\n", j,
					//pBssEntry->wlanSignalQuality, iRSSI);

					int GetiRSSI = 0;
					if (j == 4)
					{
						GetiRSSI = iRSSI;
						return GetiRSSI;
					}


					wprintf(L"  Security Enabled[%u]:\t ", j);
					if (pBssEntry->bSecurityEnabled)
						wprintf(L"Yes\n");
					else
						wprintf(L"No\n");

					wprintf(L"  Default AuthAlgorithm[%u]: ", j);
					switch (pBssEntry->dot11DefaultAuthAlgorithm) {
					case DOT11_AUTH_ALGO_80211_OPEN:
						wprintf(L"802.11 Open (%u)\n", pBssEntry->dot11DefaultAuthAlgorithm);
						break;
					case DOT11_AUTH_ALGO_80211_SHARED_KEY:
						wprintf(L"802.11 Shared (%u)\n", pBssEntry->dot11DefaultAuthAlgorithm);
						break;
					case DOT11_AUTH_ALGO_WPA:
						wprintf(L"WPA (%u)\n", pBssEntry->dot11DefaultAuthAlgorithm);
						break;
					case DOT11_AUTH_ALGO_WPA_PSK:
						wprintf(L"WPA-PSK (%u)\n", pBssEntry->dot11DefaultAuthAlgorithm);
						break;
					case DOT11_AUTH_ALGO_WPA_NONE:
						wprintf(L"WPA-None (%u)\n", pBssEntry->dot11DefaultAuthAlgorithm);
						break;
					case DOT11_AUTH_ALGO_RSNA:
						wprintf(L"RSNA (%u)\n", pBssEntry->dot11DefaultAuthAlgorithm);
						break;
					case DOT11_AUTH_ALGO_RSNA_PSK:
						wprintf(L"RSNA with PSK(%u)\n", pBssEntry->dot11DefaultAuthAlgorithm);
						break;
					default:
						wprintf(L"Other (%lu)\n", pBssEntry->dot11DefaultAuthAlgorithm);
						break;
					}

					wprintf(L"  Default CipherAlgorithm[%u]: ", j);
					switch (pBssEntry->dot11DefaultCipherAlgorithm) {
					case DOT11_CIPHER_ALGO_NONE:
						wprintf(L"None (0x%x)\n", pBssEntry->dot11DefaultCipherAlgorithm);
						break;
					case DOT11_CIPHER_ALGO_WEP40:
						wprintf(L"WEP-40 (0x%x)\n", pBssEntry->dot11DefaultCipherAlgorithm);
						break;
					case DOT11_CIPHER_ALGO_TKIP:
						wprintf(L"TKIP (0x%x)\n", pBssEntry->dot11DefaultCipherAlgorithm);
						break;
					case DOT11_CIPHER_ALGO_CCMP:
						wprintf(L"CCMP (0x%x)\n", pBssEntry->dot11DefaultCipherAlgorithm);
						break;
					case DOT11_CIPHER_ALGO_WEP104:
						wprintf(L"WEP-104 (0x%x)\n", pBssEntry->dot11DefaultCipherAlgorithm);
						break;
					case DOT11_CIPHER_ALGO_WEP:
						wprintf(L"WEP (0x%x)\n", pBssEntry->dot11DefaultCipherAlgorithm);
						break;
					default:
						wprintf(L"Other (0x%x)\n", pBssEntry->dot11DefaultCipherAlgorithm);
						break;
					}

					wprintf(L"  Flags[%u]:\t 0x%x", j, pBssEntry->dwFlags);
					if (pBssEntry->dwFlags) {
						if (pBssEntry->dwFlags & WLAN_AVAILABLE_NETWORK_CONNECTED)
							wprintf(L" - Currently connected");
						if (pBssEntry->dwFlags & WLAN_AVAILABLE_NETWORK_CONNECTED)
							wprintf(L" - Has profile");
					}
					wprintf(L"\n");

					wprintf(L"\n");
				}
			}
		}
		if (pBssList != NULL) {
			WlanFreeMemory(pBssList);
			pBssList = NULL;
		}

		if (pIfList != NULL) {
			WlanFreeMemory(pIfList);
			pIfList = NULL;
		}

		return GetiRSSI;
	}


}