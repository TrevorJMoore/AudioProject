#include "WaveAudio.h"

WaveAudio::WaveAudio(int audio_format, int num_channels, int sample_rate, int bits_per_sample) {
	// Set the variable properties
	SetAudioFormat(audio_format);
	SetNumChannels(num_channels);
	SetSampleRate(sample_rate);
	SetBitsPerSample(bits_per_sample);

	// TODO: Add a check on audio_format. If it is not PCM (value of 1), 
	// then we have extra parameters we need to handle.

	// Set the properties based on calculations
	WaveAudio::byte_rate = GetSampleRate() * GetNumChannels() * GetBitsPerSample() / 8;
	WaveAudio::block_align = GetNumChannels() * GetBitsPerSample() / 8;

	WaveAudio::subchunk1_size = 16;
	
	

}

// Accessor Methods
std::uint32_t WaveAudio::GetChunkSize() {
	return chunk_size;
}

std::uint32_t WaveAudio::GetSubchunk1Size() {
	return subchunk1_size;
}

std::uint16_t WaveAudio::GetAudioFormat() {
	return audio_format;
}

std::uint16_t WaveAudio::GetNumChannels() {
	return num_channels;
}

std::uint32_t WaveAudio::GetSampleRate() {
	return sample_rate;
}

std::uint32_t WaveAudio::GetByteRate() {
	return byte_rate;
}

std::uint16_t WaveAudio::GetBlockAlign() {
	return block_align;
}

std::uint16_t WaveAudio::GetBitsPerSample() {
	return bits_per_sample;
}

std::uint32_t WaveAudio::GetSubchunk2Size() {
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