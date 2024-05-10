#pragma once
#include <vector>
#include <string>


// This class enables audio to be created and editted within a .WAV file.
class WaveAudio {
private:
	std::vector<std::uint8_t> data;

	// Header information for WAVE file format

	// "RIFF" Chunk
	const std::string chunk_id = "RIFF";	// RIFF
	std::uint32_t chunk_size;
	const std::string format = "WAVE";		// WAVE

	// "fmt " Sub-chunk
	const std::string subchunk1_id = "fmt ";
	std::uint32_t subchunk1_size;
	std::uint16_t audio_format;
	std::uint16_t num_channels;
	std::uint32_t sample_rate;
	std::uint32_t byte_rate;
	std::uint16_t block_align;
	std::uint16_t bits_per_sample;

	// "data" Sub-chunk
	const std::string subchunk2_id = "data";
	std::uint32_t subchunk2_size;




public:
	// Create a .WAV file of given number of channels, sample rate, and bits-per-sample.
	WaveAudio(const std::uint16_t num_channels, const std::uint32_t sample_rate, 
		const std::uint16_t bits_per_sample);

	void CreateSinWave(double frequency, double amplitude, double duration);

	void WriteFile(const std::string& filename);


	// Accessor Methods:
	std::string GetChunkId() const;
	std::uint32_t GetChunkSize() const;
	std::string GetFormat() const;

	std::string GetSubchunk1Id() const;
	std::uint32_t GetSubchunk1Size() const;
	std::uint16_t GetAudioFormat() const;
	std::uint16_t GetNumChannels() const;
	std::uint32_t GetSampleRate() const;
	std::uint32_t GetByteRate() const;
	std::uint16_t GetBlockAlign() const;
	std::uint16_t GetBitsPerSample() const;

	std::string GetSubchunk2Id() const;
	std::uint32_t GetSubchunk2Size() const;

	// Mutator Methods:
	// ChunkID may not be set. It is always "RIFF". Well it could be "RIFX" for big-endian, but we aren't doing that.
	// ChunkSize may not be set publicly. It is based on a calculation.
	// Format may not be set. It is always "WAVE".

	// Subchunk1ID may not be set. It is always "fmt ".
	// Subchunk1Size may not be set publicly. It is based on a calculation.
	void SetAudioFormat(std::uint16_t audio_format);
	void SetNumChannels(std::uint16_t num_channels);
	void SetSampleRate(std::uint32_t sample_rate);
	// ByteRate may not be set publicly. It is based on a caculation.
	// BlockAlign may not be set publicly. It is based on a calculation.
	void SetBitsPerSample(std::uint16_t bits_per_sample);

	// Subchunk2ID may not be set. It is always "data".
	// Subchunk2Size may not be set publicly. It is based on a caculation.
	//void SetData();
	

};