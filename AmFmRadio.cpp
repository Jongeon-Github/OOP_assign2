/*
* Filename: AmFmRadio.cpp
* Project: OOP-assign2
* By: Jongeon Lee
* Date: Jun 03, 2023
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "AmFmRadio.h"

#pragma warning(disable:4996)

AmFmRadio::AmFmRadio()
{
	for( int i = 0; i < 5; ++i )
	{
		button[i].AMFreq = 530;
	}
	for( int j = 0; j < 5; ++j )
	{
		button[j].FMFreq = (float)87.9;
	}
	current_station = 530;
	strcpy(band, "AM");
	volume = 0;
	on = false;
}

AmFmRadio::AmFmRadio(bool radioOn)
{
	for (int i = 0; i < 5; ++i)
	{
		button[i].AMFreq = 530;
	}
	for (int j = 0; j < 5; ++j)
	{
		button[j].FMFreq = (float)87.9;
	}
	current_station = 530;
	strcpy(band, "AM");
	volume = 0;
	on = radioOn;
}

AmFmRadio::AmFmRadio(bool radioOn, Freqs presets[5])
{
	for (int i = 0; i < 5; ++i)
	{
		button[i].AMFreq = presets[i].AMFreq;
		button[i].FMFreq = presets[i].FMFreq;
	}
	current_station = presets[0].AMFreq; // Set the current station to the first AM preset
	strcpy(band, "AM");
	volume = 0;
	on = radioOn;
}

AmFmRadio::~AmFmRadio()
{
	printf("Destroying AmFmRadio\n");
}
















/*

void AmFmRadio::PowerToggle()
{
	if( on == false )
	{
		on = true;
	}
	else
	{
		on = false;
	}
}

bool AmFmRadio::IsRadioOn()
{
	return on;
}

int AmFmRadio::SetVolume()
{
	char buf[20] = "";

	printf("\nEnter the volume level (0 - 100). ");
	fgets(buf, sizeof buf, stdin);
	volume = atoi(buf);

	if( volume < 0 ) //if user enters volume less than 0, volume = 0
	{
		volume = 0;
		return 0;
	}

	if( volume > 100 ) //if user enters volume greater than 100, volume = 100
	{
		volume = 100;
		return 2;
	}
	return 1;


}

void AmFmRadio::ToggleBand()
{
	if( strcmp(band, "AM") == 0 )
	{
		strcpy(band, "FM");
		current_station = 87.9;
	}
	else
	{
		strcpy(band, "AM");
		current_station = 530;
	}
}

int AmFmRadio::SetPresetButton(int button_num)
{
	if( (button_num >= 0) && (button_num <= 4) )
	{
		if( strcmp("AM", band) == 0 )
		{
			button[button_num].AMFreq = (int)current_station;
		}
		else
		{
			button[button_num].FMFreq = (float)current_station;
		}
		return 1;

	}
	return 0;

}

int AmFmRadio::SelectPresetButton(int button_num)
{
	if( (button_num >= 0) && (button_num <= 4) )
	{
		if( strcmp("AM", band) == 0 )
		{
			current_station = button[button_num].AMFreq;
		}
		else
		{
			current_station = button[button_num].FMFreq;
		}

		return 1;
	}
	return 0;


}

void AmFmRadio::ShowCurrentSettings()
{

	if( on == true )
	{
		printf("\n\nRadio is on. \n");
	}
	else
	{
		printf("\n\nRadio is off. \n");
	}

	printf("\nRadio Band: %s\n", band);
	printf("Volume: %d\n", volume);
	printf("Current Station: %.1f %s\n", current_station, band);
	printf("AM Button Settings: ");
	for( int i = 0; i < 5; ++i )
	{
		printf("%d) %6d ", i + 1, button[i].AMFreq);
	}

	printf("\nFM Button Settings: ");
	for( int j = 0; j < 5; ++j )
	{
		printf("%d) %6.1f ", j + 1, button[j].FMFreq);
	}
}

void AmFmRadio::ScanUp()
{
	if( strcmp("AM", band) == 0 )
	{
		//if current_station is 1700, the current_station becomes 530
		if( current_station == 1700 )
		{
			current_station = 530;
		}
		else
		{
			current_station = current_station + 10;
		}
	}
	else
	{
		//if the current_station is 107.9, the current_station becomes 87.9
		//Note: car radios jump .2 for the FM. That's how it's modeled here.
		if( current_station >= 107.9 )
		{
			current_station = 87.9;
		}
		else
		{
			current_station = current_station + .2;
		}
	}
	printf("\nCurrent station: %f %s\n", current_station, band);
}


*/