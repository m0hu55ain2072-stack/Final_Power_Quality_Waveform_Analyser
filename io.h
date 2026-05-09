#ifndef IO_H
#define IO_H
#include "waveform.h"

WaveformSample *load_csv(const char *filename, int *row_count);
// Writes formatted analysis report to the named file
void write_results(const char *filename, WaveformSample *samples, int row_count);

#endif