#pragma once
#include <cstdint>
#include <vector>
// This class will define a wave parent class
// Every wave will have a frequency, wavelength, velocity, and amplitude.
class Wave {
private:
	double frequency_hz;	// Frequency is a value between [0, sample_rate/2]
	double wavelength_m;	
	double velocity_ms;		// v = f * wavelength
	double amplitude;		// Amplitude is a value between [-1,1]

	std::uint32_t sample_rate;
	std::uint16_t bit_depth;

	


public:
	// TESTING VARIABLE SET PRIVATE LATER
	std::vector<double> wave_data;
	
	// Default Constructor
	Wave();

	// Parameterized Constructor
	Wave(double frequency_hz, double wavelength_m, double amplitude);

	// Methods
	void PrintData();


	// Accessor Methods
	double GetFrequency() const;
	double GetWavelength() const;
	double GetVelocity() const;
	double GetAmplitude() const;
	std::uint32_t GetSampleRate() const;
	std::uint16_t GetBitDepth() const;

	// Mutator Methods
	void SetFrequency(double frequency_hz);
	void SetWavelength(double wavelength_m);
	void SetAmplitude(double amplitude);
	// Note that the velocity of the wave is a calculation based
	// on frequency * wavelength, so we do not have a method for it.
	
	// These methods are only included to give users more
	// control over the sampling of their sound waves.
	// Default values set in constructor should be fine.
	// If sample rates differ, we cannot add waves 
	// because a sample may exist where another does not.
	void SetSampleRate(uint32_t sample_rate);
	void SetBitDepth(uint16_t bit_depth);


};