/*
* Filename: AmFmRadio.h
* Project: OOP-assign2
* By: Jongeon Lee
* Date: Jun 03, 2023
*/

#ifndef _CARRADIO_H
#define _CARRADIO_H

struct Freqs
{
	int AMFreq;
	float FMFreq;
};

class AmFmRadio
{
private:
	Freqs	button[5];
	double	current_station;
	char	band[3];
	int		volume;
	bool	on;

public:
	// Default constructor; sets the default values
	AmFmRadio();

	// Constructor; takes a bool parameter to set the initial power state
	AmFmRadio(bool radioOn);

	// Constructor; takes a bool parameter for power state and an array of Freqs for presets
	AmFmRadio(bool radioOn, Freqs presets[5]);



	// Destructor; displays "Destroying AmFmRadio"
	~AmFmRadio();





	 




	/*

	//sets the each button to the lowest frequency, sets the current station, sets the
	//frequency to AM, sets the volume to 0 and sets on to false
	AmFmRadio();

	//sets on to true
	void PowerToggle();

	//returns a true if the radio is currently powered on, and false if the radio is in
	//the off position
	bool IsRadioOn();

	//toggles frequency between AM and FM and sets current station
	void ToggleBand();

	//sets button (radio preset) with current station by being passed a button number
	int SetPresetButton(int button_num);

	//sets current station to radio preset by being passed a button number
	int SelectPresetButton(int button_num);

	//sets volume
	int SetVolume();

	//shows volume, button settings, current station, AM or FM
	void ShowCurrentSettings();

	//changes frequency up in increments of .2 for FM, 10 for AM
	void ScanUp();

	*/


};
#endif