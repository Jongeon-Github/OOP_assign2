/*
* Filename: AmFmRadio.h
* Project: OOP-assign2
* By: Jongeon Lee
* Date: Jun 03, 2023
*/

#ifndef AMFMRADIO_H
#define AMFMRADIO_H

struct Freqs
{
	int AMFreq;
	float FMFreq;
};

class AmFmRadio {
private:
	Freqs	presets[5];
	Freqs	previousFreq;
	int		volume;
	bool	on;
	bool	displayOutput;

public:
	AmFmRadio(bool radioOn = false);
	AmFmRadio(bool radioOn, Freqs initPresets[5]);
	~AmFmRadio();

	void PowerToggle();
	void SetVolume();
	void SetVolume(int vol);
	void ToggleBand();
	void SetPresetButton(int buttonNum);
	void SelectPresetButton(int buttonNum);
	void ShowCurrentSettings();
	void ScanUp();
	void ScanDown();
	bool IsRadioOn();
	float GetCurrentVolume();
	Freqs* GetPresets();
	Freqs GetCurrentFrequency();
	bool GetDisplayOutput();
	void SetDisplayOutput(bool display);
};
#endif