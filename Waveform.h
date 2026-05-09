#ifndef WAVEFORM_H
#define WAVEFORM_H


typedef struct {
    double timestamp;
    double phase_A_voltage;
    double phase_B_voltage;
    double phase_C_voltage;
    double line_current;
    double frequency;
    double power_factor;
    double thd_percent;
} WaveformSample;
double compute_rms(const WaveformSample *samples, int count, int phase);
double compute_peak_to_peak(const WaveformSample *samples, int count, int phase);
double compute_dc_offset(const WaveformSample *samples, int count, int phase);
#endif