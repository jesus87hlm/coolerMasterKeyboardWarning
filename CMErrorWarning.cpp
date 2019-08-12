// CMErrorWarning.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <windows.h> 
#include <iostream>
#include <fstream>
#include "includes/SDKDLL.h"
#include <nlohmann/json.hpp>


BYTE r = 0;
BYTE g = 0;
BYTE b = 0;
BYTE R = 255;
BYTE G = 255;
BYTE B = 255;
BYTE Rs = 100;
BYTE Gs = 100;
BYTE Bs = 100;
bool exiter = false;

using json = nlohmann::json;

using namespace std;

void alarm(int numberOfBlinks) {
	//Basically turns on and off LEDs 20 times
	for (int x = 1; x < numberOfBlinks; x++) {
		Sleep(100);
		r = 255;
		g = 0;// full brightness
		b = 0;
		SetFullLedColor(r, g, b);
		Sleep(300);
		r = 0;
		g = 0;// no brightness
		b = 0;
		SetFullLedColor(r, g, b);
	}
}

void resetColors(json colors, EFF_INDEX effectIndex) {
	R = colors["r"];
	G = colors["g"];
	B = colors["b"];
	SetFullLedColor(R, G, B);

	SwitchLedEffect(effectIndex);
}

BOOL CtrlHandler(DWORD fdwCtrlType)
{
	switch (fdwCtrlType)
	{
		// Handle the CTRL-C signal. 
	case CTRL_C_EVENT:
		printf("Ctrl-C event\n\n");
		Beep(750, 300);
		::exiter = true;
		return(TRUE);

		// CTRL-CLOSE: confirm that the user wants to exit. 
	case CTRL_CLOSE_EVENT:
		Beep(600, 200);
		printf("Ctrl-Close event\n\n");
		EnableLedControl(false);
		return(TRUE);

		// Pass other signals to the next handler. 
	case CTRL_BREAK_EVENT:
		Beep(900, 200);
		printf("Ctrl-Break event\n\n");
		return FALSE;

	case CTRL_LOGOFF_EVENT:
		Beep(1000, 200);
		printf("Ctrl-Logoff event\n\n");
		return FALSE;

	case CTRL_SHUTDOWN_EVENT:
		Beep(750, 500);
		printf("Ctrl-Shutdown event\n\n");
		return FALSE;

	default:
		return FALSE;
	}
}


int main(int argc, char** argv)
{

	// settings file

	std::ifstream i("settings.json");
	if (!i.is_open()) {
		cout << "No settings file detected";
		return 0;
	}

	json settings = json::parse(i);

	int numberBlinks = settings["number_blinks"];

	SetControlDevice(settings["model"]);

	if (SetConsoleCtrlHandler((PHANDLER_ROUTINE)CtrlHandler, TRUE))
	{
		printf("\nAlarm is active!.\n");
	}

	EnableLedControl(true);
	alarm(numberBlinks);

	resetColors(settings["reset_color"], settings["effect_index"]);

	EnableLedControl(false);
	return 0;

}
