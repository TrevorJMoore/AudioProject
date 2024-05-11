#define _USE_MATH_DEFINES
#include "SineWave.h"
#include <cmath>
#include <iostream>


SineWave::SineWave() : Wave() {
	// Set the default values for the wave
}

SineWave::SineWave(double frequency_hz, double wavelength_m, double amplitude_m) 
	: Wave(frequency_hz, wavelength_m, amplitude_m) {
	// Set the parameters
}

// Produce the sine wave for a given number of seconds
void SineWave::ProduceSineWave(double duration_seconds) {
	// The maximum amplitude is (2^bit depth / 2) - 1
	// We divide by 2 because 2^bit depth spans the entire range,
	// but half is the positive (above y-axis range) and the other half
	// is the negative (below y-axis range).
	// Subtract by 1 because 0 is included in the positive range.
	double max_amp = std::pow(2, GetBitDepth()) / 2 - 1;

	// We need to scale our amplitude with the bit depth
	double scaled_amp = GetAmplitude() * max_amp;

	// We will loop over the sample rate for the duration of the wave
	for (int sample = 0; sample < GetSampleRate() * duration_seconds; sample++) {
		// y(n) = A * sin(2*PI*(f/sample rate)*n)
		// Where n is sample index, A is amplitude, and f is frequency.
		double value = GetAmplitude()* sin(2 * M_PI * GetFrequency() / GetSampleRate() * sample);
		wave_data.push_back(value);
	}
	
}

void SineWave::PrintData() {
	for (double n : wave_data) {
		std::cout << n << "\n";
	}
}