#include <stdio.h>
#include <stdlib.h>
#include "io.h"
#include "waveform.h"

WaveformSample *load_csv(const char *filename, int *row_count) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file '%s'\n", filename);
        return NULL;
    }

    char line[1000];


    int line_count = 0;
    while (fgets(line, sizeof(line), fp) != NULL) {
        line_count++;
    }
    int data_rows = line_count - 1;

    rewind(fp);


    WaveformSample *samples = malloc(data_rows * sizeof(WaveformSample));
    if (samples == NULL) {
        fclose(fp);
        return NULL;
    }


    fgets(line, sizeof(line), fp);


    WaveformSample *out = samples;
    for (int i = 0; i < data_rows; i++) {

        if (fgets(line, sizeof(line), fp) != NULL) {
            int fields = sscanf(line, "%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf",
                        &out->timestamp,
                        &out->phase_A_voltage,
                        &out->phase_B_voltage,
                        &out->phase_C_voltage,
                        &out->line_current,
                        &out->frequency,
                        &out->power_factor,
                        &out->thd_percent);

            if (fields != 8) {
                free(samples);
                fclose(fp);
                return NULL;
            }
        }


        out++;
    }

    *row_count = data_rows;
    fclose(fp);
    return samples;
}


