/*
* Filename: driver.cpp
* Project: OOP-assign2
* By: Jongeon Lee
* Date: Jun 03, 2023
* Description: Upgrading car radio based on requirements. The driver.cpp file implements
*			   a menu-driven program to control a car radio using the AmFmRadio class.
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "AmFmRadio.h"

using namespace std;

enum menuItems
{
    TOGGLE_POWER = 1,
    SET_VOLUME,
    TOGGLE_BAND,
    SET_PRESET_BUTTON,
    SELECT_PRESET_BUTTON,
    SHOW_CURRENT_SETTINGS,
    SCAN_UP,
    SCAN_DOWN,
    QUIT_PROGRAM
};

int main()
{
	int			button_OK = 0;
	int			buttonNum = 0;
	int			previousVolume = 0;
	char		buf[20] = { NULL };
	menuItems	choice = TOGGLE_POWER;
	AmFmRadio	jazzy = { 0 };

	do
	{
		// Print the menu options
		cout << endl << endl <<"MAIN MENU" << endl;
		cout << "=========" << endl << endl;
		cout << "1.  Toggle Power" << endl;
		cout << "2.  Set Volume" << endl;
		cout << "3.  Toggle AM / FM Band" << endl;
		cout << "4.  Set a Preset Button" << endl;
		cout << "5.  Select a Preset Button" << endl;
		cout << "6.  Show Current Settings" << endl;
		cout << "7.  Scan Up" << endl;
		cout << "8.  Scan Down" << endl;
		cout << "9.  Quit the Program" << endl;
		cout << endl << "Make a selection from the menu" << endl;
		cout << "Menu num: ";

		// Read the user's choice from input
		fgets(buf, sizeof(buf), stdin);
		choice = (menuItems)atoi(buf);

		// Perform the corresponding action based on the user's choice
		switch (choice) {
		case TOGGLE_POWER:
			jazzy.PowerToggle();
			break;
		case SET_VOLUME:
			jazzy.SetVolume();
			break;
		case TOGGLE_BAND:
			jazzy.ToggleBand();
			break;
		case SET_PRESET_BUTTON:
			cout << "Enter the button number (0-4): ";
			fgets(buf, sizeof(buf), stdin);
			buttonNum = atoi(buf);
			button_OK = jazzy.SetPresetButton(buttonNum);
			if (button_OK == 0)
			{
				cout << endl << "You entered an invalid button number!" << endl;
			}
			break;
		case SELECT_PRESET_BUTTON:
			cout << "Enter the button number (0-4): ";
			fgets(buf, sizeof(buf), stdin);
			buttonNum = atoi(buf);
			button_OK = jazzy.SelectPresetButton(buttonNum);
			if (button_OK == 0)
			{
				cout << endl << "You entered an invalid button number!" << endl;
			}
			break;
		case SHOW_CURRENT_SETTINGS:
			jazzy.ShowCurrentSettings();
			break;
		case SCAN_UP:
			jazzy.ScanUp();
			break;
		case SCAN_DOWN:
			jazzy.ScanDown();
			break;
		case QUIT_PROGRAM:
			cout << "Quitting the program." << endl;
			break;
		default:
			cout << "Invalid choice. Try again." << endl;
		}
	} while (choice != QUIT_PROGRAM);

	return 0;
}