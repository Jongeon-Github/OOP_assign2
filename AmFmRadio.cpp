/*
* Filename: AmFmRadio.cpp
* Project: OOP-assign2
* By: Jongeon Lee
* Date: Jun 03, 2023
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include "AmFmRadio.h"

#pragma warning(disable:4996)

using namespace std;

AmFmRadio::AmFmRadio(bool radioOn) {
    on = radioOn;
    volume = 0;
    displayOutput = false;
}

AmFmRadio::AmFmRadio(bool radioOn, Freqs initialPresets[5]) {
    on = radioOn;
    volume = 0.0;
    displayOutput = false;

    for (int i = 0; i < 5; i++) {
        presets[i] = initialPresets[i];

    }
}

AmFmRadio::~AmFmRadio() {
    cout << "Destroying AmFmRadio" << endl;
}

void AmFmRadio::PowerToggle() {
    if (on) {
        on = false;
        volume = 0.0;
    }
    else {
        on = true;
        volume = previousFreq.AMFreq != 0.0 ? previousFreq.AMFreq : previousFreq.FMFreq;
    }
}

void AmFmRadio::SetVolume() {
    cout << "Enter the volume level: ";
    cin >> volume;
    cin.ignore();
}

void AmFmRadio::SetVolume(int vol) {
    volume = vol;
}

void AmFmRadio::ToggleBand() {
    if (on) {
        previousFreq = GetCurrentFrequency();
        volume = previousFreq.AMFreq != 0.0 ? previousFreq.AMFreq : previousFreq.FMFreq;
    }
}

void AmFmRadio::SetPresetButton(int buttonNum) {
    if (on && buttonNum >= 0 && buttonNum < 5) {
        presets[buttonNum] = GetCurrentFrequency();
    }
}

void AmFmRadio::SelectPresetButton(int buttonNum) {
    if (on && buttonNum >= 0 && buttonNum < 5) {
        Freqs selectedFreq = presets[buttonNum];
        previousFreq = selectedFreq;
        volume = selectedFreq.AMFreq != 0.0 ? selectedFreq.AMFreq : selectedFreq.FMFreq;
    }
}

void AmFmRadio::ShowCurrentSettings() {
    if (displayOutput) {
        cout << "Current Settings:" << endl;
        cout << "Power: " << (on ? "On" : "Off") << endl;
        cout << "Volume: " << volume << endl;
        cout << "Current Frequency: AM - " << previousFreq.AMFreq << ", FM - " << previousFreq.FMFreq << endl;
        cout << endl;
    }
}

void AmFmRadio::ScanUp() {
    if (on) {
        if (previousFreq.AMFreq != 0.0) {
            previousFreq.AMFreq += 10.0;
            if (previousFreq.AMFreq > 1700.0) {
                previousFreq.AMFreq = 530.0;
            }
        }
        else {
            previousFreq.FMFreq += 0.2;
            if (previousFreq.FMFreq > 107.9) {
                previousFreq.FMFreq = 87.9;
            }
        }
    }
}

void AmFmRadio::ScanDown() {
    if (on) {
        if (previousFreq.AMFreq != 0.0) {
            previousFreq.AMFreq -= 10.0;
            if (previousFreq.AMFreq < 530.0) {
                previousFreq.AMFreq = 1700.0;
            }
        }
        else {
            previousFreq.FMFreq -= 0.2;
            if (previousFreq.FMFreq < 87.9) {
                previousFreq.FMFreq = 107.9;
            }
        }
    }
}

bool AmFmRadio::IsRadioOn() {
    return on;
}

float AmFmRadio::GetCurrentVolume() {
    return volume;
}

Freqs* AmFmRadio::GetPresets() {
    return presets;
}

Freqs AmFmRadio::GetCurrentFrequency() {
    return previousFreq;
}

bool AmFmRadio::GetDisplayOutput() {
    return displayOutput;
}

void AmFmRadio::SetDisplayOutput(bool display) {
    displayOutput = display;
}