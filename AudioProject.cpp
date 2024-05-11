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
#include "SineWave.h"

using namespace std;


int main()
{
    SineWave wave(440.0, 1.0, 25.0);
    wave.ProduceSineWave(0.005);
    wave.PrintData();
    return 0;
}
