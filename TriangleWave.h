#pragma once
#include "Wave.h"
class TriangleWave : public Wave {
private:


public:
	// Default Constructor
	TriangleWave();

	// Parameterized Constructor
	TriangleWave(double frequency_hz, double wavelength_m, double amplitude_m);

	void ProduceTriangleWave(double duration_seconds);

};