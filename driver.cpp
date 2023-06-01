/*
* Filename: driver.cpp
* Project: OOP-assign2
* By: Jongeon Lee
* Date: Jun 03, 2023
* Description: Upgrading your car radio
*/

#include <stdio.h>
#include <stdlib.h>
#include "AmFmRadio.h"

#include <iostream>

#pragma warning(disable:4996)

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

	int			volume_OK = 0;
	int			button_OK = 0;
	int			button_num = 0;
	menuItems	choice = TOGGLE_POWER;
	char		buf[20] = { 0 };
	bool		on = false;

	AmFmRadio jazzy(true);

	do
	{
		printf("\n\nMAIN MENU\n");
		printf("=========\n\n");
		printf("1.  Toggle Power\n");
		printf("2.  Set Volume\n");
		printf("3.  Toggle AM / FM Band\n");
		printf("4.  Set a Preset Button \n");
		printf("5.  Select a Preset Button \n");
		printf("6.  Show Current Settings\n");
		printf("7.  Scan Up \n");
		printf("8.  Scan Down\n");
		printf("9.  Quit the Program\n");
		printf("\nMake a selection from the menu\n");
		fgets(buf, sizeof(buf), stdin);
		choice = (menuItems)atoi(buf);

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
			printf("Enter the button number (0-4): ");
			int buttonNum;
			sscanf(buf, "%d", &buttonNum);
			jazzy.SetPresetButton(buttonNum);
			break;
		case SELECT_PRESET_BUTTON:
			printf("Enter the button number (0-4): ");
			fgets(buf, sizeof(buf), stdin);
			sscanf(buf, "%d", &buttonNum);
			jazzy.SelectPresetButton(buttonNum);
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
			printf("Quitting the program.\n");
			break;
		default:
			printf("Invalid choice. Try again.\n");
		}
	} while (choice != QUIT_PROGRAM);

	return 0;
}