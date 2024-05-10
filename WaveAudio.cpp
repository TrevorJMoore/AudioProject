#define _USE_MATH_DEFINES

#include <fstream>
#include <cmath>
#include "WaveAudio.h"

WaveAudio::WaveAudio(const std::uint16_t num_channels, const std::uint32_t sample_rate, 
	const std::uint16_t bits_per_sample) {
	// Set the variable properties
	SetAudioFormat(1);	// 1 for PCM (I plan on changing this later to support other compression formats)
	SetNumChannels(num_channels);
	SetSampleRate(sample_rate);
	SetBitsPerSample(bits_per_sample);

	// Set the properties based on calculations
	WaveAudio::byte_rate = GetSampleRate() * GetNumChannels() * GetBitsPerSample() / 8;
	WaveAudio::block_align = GetNumChannels() * GetBitsPerSample() / 8;	

}

void WaveAudio::CreateSinWave(double frequency, double amplitude, double duration) {
	int total_samples = static_cast<int>(sample_rate * duration);
	double max_amp = std::pow(2, bits_per_sample) / 2 - 1;

	// Resize the data vector to hold the required number of bytes
	data.resize(total_samples * num_channels * (bits_per_sample / 8));
	for (int i = 0; i < total_samples; i++) {
		// Calculate the sine wave for the current sample i
		double value = amplitude * max_amp * std::sin(2 * M_PI * frequency * i / sample_rate);

		// Fill the data vector for each number of channels
		for (int channel = 0; channel < num_channels; channel++) {
			int sample_index = (i * num_channels + channel) * (bits_per_sample / 8);
			// Store value in little-endian format
			for (int byte = 0; byte < bits_per_sample / 8; byte++) {
				data[sample_index + byte] = static_cast<uint8_t>((static_cast<int>(value) >> (byte * 8)) & 0xFF);
			}
		}
	}
}

// TODO: Update the method so it can handle audio formats other than PCM.
// This means reading extra parameters and therefore shifting
// possibly using file.seekp() and file.tellp()
void WaveAudio::WriteFile(const std::string& filename) {
	std::ofstream file(filename, std::ios::binary);

	// "RIFF" Chunk
	file.write(GetChunkId().c_str(), 4);	// "RIFF" 4 bytes
	chunk_size = 36 + data.size();
	file.write(reinterpret_cast<char*>(&chunk_size), sizeof(chunk_size));
	file.write(format.c_str(), 4);			// "WAVE" 4 bytes

	// "fmt " Sub-chunk
	file.write(subchunk1_id.c_str(), 4);
	subchunk1_size = 16;
	file.write(reinterpret_cast<char*>(&subchunk1_size), sizeof(subchunk1_size));	// We could put "4" but we already used uint32_t so the sizeof is 4 bytes
	file.write(reinterpret_cast<char*>(&audio_format), sizeof(audio_format));
	file.write(reinterpret_cast<char*>(&num_channels), sizeof(num_channels));
	file.write(reinterpret_cast<char*>(&sample_rate), sizeof(sample_rate));
	file.write(reinterpret_cast<char*>(&byte_rate), sizeof(byte_rate));
	file.write(reinterpret_cast<char*>(&block_align), sizeof(block_align));
	file.write(reinterpret_cast<char*>(&bits_per_sample), sizeof(bits_per_sample));

	// "data" Sub-chunk
	file.write(subchunk2_id.c_str(), 4);
	subchunk2_size = data.size();
	file.write(reinterpret_cast<char*>(&subchunk2_size), sizeof(subchunk2_size));
	file.write(reinterpret_cast<char*>(data.data()), data.size());


	file.close();

}


// Accessor Methods
// "RIFF" Chunk
std::string WaveAudio::GetChunkId() const {
	return chunk_id;
}

std::uint32_t WaveAudio::GetChunkSize() const {
	return chunk_size;
}

std::string WaveAudio::GetFormat() const {
	return format;
}


// "fmt " Sub-chunk
std::string WaveAudio::GetSubchunk1Id() const {
	return subchunk1_id;
}

std::uint32_t WaveAudio::GetSubchunk1Size() const {
	return subchunk1_size;
}

std::uint16_t WaveAudio::GetAudioFormat() const {
	return audio_format;
}

std::uint16_t WaveAudio::GetNumChannels() const {
	return num_channels;
}

std::uint32_t WaveAudio::GetSampleRate() const {
	return sample_rate;
}

std::uint32_t WaveAudio::GetByteRate() const {
	return byte_rate;
}

std::uint16_t WaveAudio::GetBlockAlign() const {
	return block_align;
}

std::uint16_t WaveAudio::GetBitsPerSample() const {
	return bits_per_sample;
}


// "data" Sub-chunk
std::string WaveAudio::GetSubchunk2Id() const {
	return subchunk2_id;
}

std::uint32_t WaveAudio::GetSubchunk2Size() const {
	return subchunk2_size;
}

// Mutator Methods
void WaveAudio::SetAudioFormat(std::uint16_t audio_format) {
	WaveAudio::audio_format = audio_format;
}

void WaveAudio::SetNumChannels(std::uint16_t num_channels) {
	WaveAudio::num_channels = num_channels;
}

void WaveAudio::SetSampleRate(std::uint32_t sample_rate) {
	WaveAudio::sample_rate = sample_rate;
}

void WaveAudio::SetBitsPerSample(std::uint16_t bits_per_sample) {
	WaveAudio::bits_per_sample = bits_per_sample;
}