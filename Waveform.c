#include <math.h>
#include "waveform.h"

static double get_voltage(const WaveformSample *s, int phase) {
    if (phase == 0) return s->phase_A_voltage;
    if (phase == 1) return s->phase_B_voltage;
    return s->phase_C_voltage;
}

// RMS = sqrt(mean of squared samples)
double compute_rms(const WaveformSample *samples, int count, int phase) {
    double sum_squares = 0.0;
    for (const WaveformSample *p = samples; p < samples + count; p++) {
        double v = get_voltage(p, phase);
        sum_squares += v * v;
    }
    return sqrt(sum_squares / count);
}