// Trevor Moore - 5/1/24
// The purpose of this project is to re-familiarize myself with the C++ language and learn about digital audio.
// The project's scope is currently limited to receiving and outputting audio.

// Include statements:
// #include "foo/server/bar.h" ~ User-defined headers
// #include <stdlib.h> ~ C system headers
// #include <iostream> ~ C++ standard library headers

// Naming conventions:
// SortArray() ~ Functions use pascal case
// student_id ~ Variables are lowercase; underscore separated words

// Preprocessor Directive (examined before actual compilation)
#include <iostream>
#include <fstream>
#include <cmath>
#include "WaveAudio.h"

using namespace std;

// Header information for WAVE file format

// Riff Chunk (Resource Interchange File Format)
const string chunk_id = "RIFF";
// Chunk size (4-bytes) calculate later
const string chunk_size = "----";
const string format = "WAVE";

// FMT Sub-chunk
const string subchunk1_id = "fmt ";
// 16 for PCM
const int subchunk1_size = 16;
// 1 for PCM
const int audio_format = 1;
// 2 for stereo
const int num_channels = 2;
const int sample_rate = 44100;
const int byte_rate = sample_rate * num_channels * (subchunk1_size / 8);
const int block_align = num_channels * (subchunk1_size / 8);
const int bits_per_sample = 16;

// Data Sub-chunk
const string subchunk2_id = "data";
const string subchunk2_size = "----";

const int duration = 10;
// Int is 4 bytes (32 bits) we are using 16 bit so 2^16/2 32768
const int max_amplitude = 32760;
const double frequency = 698;

void write_as_bytes(ofstream &file, int value, int byte_size) {
    file.write(reinterpret_cast<const char*>(&value), byte_size);
}



int main()
{
    WaveAudio wave(1, 1, 44100, 16);
    wave.CreateSinWave(440, 0.5, 5);
    wave.WriteFile("output.wav");
    /*ofstream wav;
    wav.open("test.wav", ios::binary);

    if (wav.is_open()) {
        // Write headers
        // Rift Chunk
        wav << chunk_id;
        wav << chunk_size;
        wav << format;
        // FMT Sub-chunk
        wav << subchunk1_id;
        write_as_bytes(wav, subchunk1_size, 4);
        write_as_bytes(wav, audio_format, 2);
        write_as_bytes(wav, num_channels, 2);
        write_as_bytes(wav, sample_rate, 4);
        write_as_bytes(wav, byte_rate, 4);
        write_as_bytes(wav, block_align, 2);
        write_as_bytes(wav, bits_per_sample, 2);
        // Data Sub-chunk
        wav << subchunk2_id;
        wav << subchunk2_size;

        // Gets the position in the file
        int start_audio = wav.tellp();
        double j = 4410;
        // For loop goes 88, 000 times this is essentially the sample rate
        for (int i = 0; i < sample_rate * duration; i++, j-=0.01) {
            // Respect max amplitude
            // Operate as a wave
            //double amplitude = (double)i / sample_rate * max_amplitude;
            //double value = sin((2 * 3.14 * i * frequency) / sample_rate);
            //double amplitude = (double)i / sample_rate * max_amplitude;
            double amplitude = max_amplitude;
            double value = sin(2*3.14*i*frequency/sample_rate);

            // a * sin()
            double channel1 = amplitude * value;
            double channel2 = channel1;
            //double channel2 = amplitude * value / 2;
            //double channel2 = (max_amplitude - amplitude) * value;

            write_as_bytes(wav, channel1, 2);
            write_as_bytes(wav, channel2, 2);
        }
        
        

        // Gets the position in the file
        int end_audio = wav.tellp();

        // Go to the start position - 4 bytes
        wav.seekp(start_audio - 4);
        // Subchunk 2 size write (the size is the end - start of chunk)
        write_as_bytes(wav, end_audio - start_audio, 4);

        // Go to 4 bytes after the beggining of the file
        wav.seekp(4, ios::beg);
        write_as_bytes(wav, end_audio - 8, 4);
    }
    wav.close();
    */
    return 0;
}
