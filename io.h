#ifndef IO_H
#define IO_H
#include "waveform.h"

//  Opens the CSV file and reads all rows into a new array.
//  Sets *row_count to how many rows were loaded.
//  Returns the array, or NULL if something went wrong.
//  The caller must call free() on the returned array.
WaveformSample *load_csv(const char *filename, int *row_count);

// Writes formatted analysis report to the named file
void write_results(const char *filename, WaveformSample *samples, int row_count);

#endif