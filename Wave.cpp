#include "Wave.h"
// Default Constructor
// Create a default Wave object.
Wave::Wave() {
	// Set default values for quick creation of waveforms.
	Wave::SetFrequency(440);
	Wave::SetAmplitude(0.25);
	Wave::SetWavelength(0.78);
	Wave::velocity_ms = Wave::GetFrequency() * Wave::GetWavelength();
	
	sample_rate = 44100;
	bit_depth = 16;
}

// Parameterized Constructor
// Initialize a Wave object.
Wave::Wave(double frequency_hz, double wavelength_m, double amplitude) {
	SetFrequency(frequency_hz);
	SetWavelength(wavelength_m);
	SetAmplitude(amplitude);
	Wave::velocity_ms = frequency_hz * wavelength_m;

	sample_rate = 44100;
	bit_depth = 16;
}

// Accessor Methods

// Get frequency of current waveform
double Wave::GetFrequency() const {
	return frequency_hz;
}

// Get wavelength of current waveform
double Wave::GetWavelength() const {
	return wavelength_m;
}

// Get velocity of current waveform
double Wave::GetVelocity() const {
	return velocity_ms;
}

// Get amplitude of current waveform
double Wave::GetAmplitude() const {
	return amplitude;
}

// Get sample rate of current waveform
std::uint32_t Wave::GetSampleRate() const {
	return sample_rate;
}

// Get bit depth of current waveform
std::uint16_t Wave::GetBitDepth() const {
	return bit_depth;
}

// Mutator Methods

// Set the frequency of the current waveform
void Wave::SetFrequency(double frequency_hz) {
	Wave::frequency_hz = frequency_hz;
	Wave::velocity_ms = frequency_hz * amplitude;
}

// Set the wavelength of the current waveform
void Wave::SetWavelength(double wavelength_m) {
	Wave::wavelength_m = wavelength_m;
	Wave::velocity_ms = frequency_hz * wavelength_m;
}

// Set the amplitude of the current waveform
void Wave::SetAmplitude(double amplitude) {
	Wave::amplitude = amplitude;
}

// Set the sample rate of the current waveform
void Wave::SetSampleRate(uint32_t sample_rate) {
	Wave::sample_rate = sample_rate;
}

// Set the bit depth of the current waveform
void Wave::SetBitDepth(uint16_t bit_depth) {
	Wave::bit_depth = bit_depth;
}