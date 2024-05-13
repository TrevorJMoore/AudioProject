#pragma once
#include "Wave.h"
#include <vector>
class SineWave : public Wave {
private:
	// Have a list of values whose n-th index
	// represents the wave's n-th sample.
	
public:
	
	// Default Constructor
	SineWave();

	// Parameterized Constructor
	SineWave(double frequency_hz, double wavelength_m, double amplitude_m);


	void ProduceSineWave(double duration_seconds);
};