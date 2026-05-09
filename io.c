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

void write_results(const char *filename, WaveformSample *samples, int row_count) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open '%s' for writing\n", filename);
        return;
    }
    const char *phase_names[] = { "A", "B", "C" };
    fprintf(fp, "Power Quality Analysis Report\n");
    fprintf(fp, "===============================\n");
    fprintf(fp, "Loaded %d samples\n", row_count);
    for (int phase = 0; phase < 3; phase++) {
        double rms     = compute_rms(samples, row_count, phase);
        double pp      = compute_peak_to_peak(samples, row_count, phase);
        double dc      = compute_dc_offset(samples, row_count, phase);
        int    clipped = count_clipped_samples(samples, row_count, phase);
        int    in_tol  = is_within_tolerance(rms);

        fprintf(fp, "Phase %s\n", phase_names[phase]);
        fprintf(fp, "-------\n");
        fprintf(fp, "  RMS voltage:     %8.2f V   [%s]\n", rms, in_tol ? "WITHIN TOLERANCE" : "OUT OF TOLERANCE");
        fprintf(fp, "  Peak-to-peak:    %8.2f V\n", pp);
        fprintf(fp, "  DC offset:       %8.4f V\n", dc);
        fprintf(fp, "  Clipped samples: %d\n", clipped);
        fprintf(fp, "\n");
    }
    fclose(fp);
}


