#ifndef WAVEFORM_H
#define WAVEFORM_H

// Represents a single row from the power quality CSV log.
// One sample contains all eight fields recorded at one instant in time.
typedef struct {
    double timestamp;               // time in seconds
    double phase_A_voltage;         // phase A volts
    double phase_B_voltage;         // phase B volts
    double phase_C_voltage;         // phase C volts
    double line_current;            // current in amps
    double frequency;               // frequency in Hz
    double power_factor;            // 0 to 1
    double thd_percent;             // total harmonic distortion %
} WaveformSample;
/* Analysis function prototypes.
 * In all functions, `phase` is 0 for A, 1 for B, 2 for C. */

//  RMS voltage = sqrt(mean of squared samples). Returns volts.
double compute_rms(const WaveformSample *samples, int count, int phase);

//  Peak-to-peak amplitude = max sample - min sample. Returns volts.
double compute_peak_to_peak(const WaveformSample *samples, int count, int phase);

//  DC offset = mean voltage. Should be near zero for a clean AC signal.
double compute_dc_offset(const WaveformSample *samples, int count, int phase);

//  Count of samples where |voltage| >= 324.9 V (sensor clipping limit).
int count_clipped_samples(const WaveformSample *samples, int count, int phase);

//  Returns 1 if the supplied RMS is within 230 V +/-10% (207..253 V), else 0.
int is_within_tolerance(double rms);


#endif