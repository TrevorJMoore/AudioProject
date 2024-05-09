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


int main()
{
    WaveAudio wave(1, 44100, 16);
    wave.CreateSinWave(440, 0.5, 5);
    wave.WriteFile("output.wav");
    return 0;
}
