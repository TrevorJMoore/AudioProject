#pragma once
#include "Wave.h"
class SquareWave : public Wave {
private:


public:
	// Default Constructor
	SquareWave();

	// Parameterized Constructor
	SquareWave(double frequency_hz, double wavelength_m, double amplitude_m);

	void ProduceSquareWave(double duration_seconds);

};