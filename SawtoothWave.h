#pragma once
#include "Wave.h"
class SawtoothWave : public Wave {
private:


public:
	// Default Constructor
	SawtoothWave();

	// Parameterized Constructor
	SawtoothWave(double frequency_hz, double wavelength_m, double amplitude_m);

	void ProduceSawtoothWave(double duration_seconds);

};