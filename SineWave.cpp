#define _USE_MATH_DEFINES
#include "SineWave.h"
#include <cmath>


SineWave::SineWave() {
	// Set the default values for the wave
	SineWave::Wave();

	
}

// Calculate the sine wave
void SineWave::CalculateSineWave() {
	// The maximum amplitude is (2^bit depth / 2) - 1
	// We divide by 2 because 2^bit depth spans the entire range,
	// but half is the positive (above y-axis range) and the other half
	// is the negative (below y-axis range).
	// Subtract by 1 because 0 is included in the positive range.
	double max_amp = std::pow(2, GetBitDepth()) / 2 - 1;
	// We will loop over the sample rate for the duration of the wave
	for (int sample = 0; sample < GetSampleRate(); sample++) {
		// y(n) = A * sin(2*PI*(f/sample rate)*n)
		// Where n is sample index, A is amplitude, and f is frequency.

		wave_data.push_back(GetAmplitude() * sin(2 * M_PI * GetFrequency() / GetSampleRate() * sample));
	}
	
}