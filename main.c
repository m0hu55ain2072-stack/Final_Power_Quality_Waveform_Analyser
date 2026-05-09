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
        int clipped = count_clipped_samples(samples, count, phase);
        int in_tol  = is_within_tolerance(rms);

        printf("\nPhase %s:\n", phase_names[phase]);
        printf("  RMS voltage:    %.2f V  [%s]\n", rms, in_tol ?  "WITHIN TOLERANCE" : "OUT OF TOLERANCE");
        printf("  Peak-to-peak:   %.2f V\n", pp);
        printf("  DC offset:      %.4f V\n", dc);
        printf("  Clipped samples: %d\n\n", clipped);
}
 free(samples);
    return 0;
}
