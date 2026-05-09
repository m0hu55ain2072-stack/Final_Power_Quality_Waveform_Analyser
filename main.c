#include <stdio.h>
#include <stdlib.h>
#include "waveform.h"
#include "io.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <csv_filename>\n", argv[0]);
        return 1;
    }

    int count = 0;
    WaveformSample *samples = load_csv(argv[1], &count);
    if (samples == NULL) {
        return 1;
    }

    printf("Loaded %d samples from %s\n\n", count, argv[1]);

    const char *phase_names[] = { "A", "B", "C" };
    for (int phase = 0; phase < 3; phase++) {
        double rms = compute_rms(samples, count, phase);
        double pp  = compute_peak_to_peak(samples, count, phase);
        double dc  = compute_dc_offset(samples, count, phase);

        printf("\nPhase %s:\n", phase_names[phase]);
        printf("  RMS:          %.2f V\n", rms);
        printf("  Peak-to-peak:   %.2f V\n", pp);
        printf("  DC offset:      %.4f V\n", dc);
}
 free(samples);
    return 0;
}
