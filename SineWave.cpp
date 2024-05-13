#define _USE_MATH_DEFINES
#include "SineWave.h"
#include <cmath>


SineWave::SineWave() : Wave() {
	// Set the default values for the wave
}

SineWave::SineWave(double frequency_hz, double wavelength_m, double amplitude_m) 
	: Wave(frequency_hz, wavelength_m, amplitude_m) {
	// Set the parameters
}

// Produce the sine wave for a given number of seconds
void SineWave::ProduceSineWave(double duration_seconds) {
	// We will loop over the sample rate for the duration of the wave
	for (int sample = 0; sample < GetSampleRate() * duration_seconds; sample++) {
		// y(n) = A * sin(2*PI*(f/sample rate)*n)
		// Where n is sample index, A is amplitude, and f is frequency.
		double value = GetAmplitude()* sin(2 * M_PI * GetFrequency() / GetSampleRate() * sample);
		Wave::wave_data.push_back(value);
	}
	
}