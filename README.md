# Power Quality Waveform Analyser

A C99 command-line tool that analyses 3-phase power quality data from a CSV log file.

## What it does

Given a CSV of 1,000 voltage samples from a 3-phase industrial power supply (sampled at 5 kHz over 200 ms — 10 cycles of a 50 Hz waveform), this program computes:

- **RMS voltage** for each phase
- **Peak-to-peak amplitude**
- **DC offset** (should be near zero for clean AC)
- **Clipping detection** (samples reaching the 324.9 V sensor threshold)
- **Tolerance compliance** (whether each phase is within 230 V ±10%)

Results are printed to the console and written to `results.txt`.

## Project structure

| File | Purpose |
|------|---------|
| `main.c` | Entry point; orchestrates loading, analysis, and reporting |
| `io.c` / `io.h` | CSV loading and report writing |
| `waveform.c` / `waveform.h` | `WaveformSample` struct and analysis functions |
| `CMakeLists.txt` | Build configuration |

## To compile this app with GCC

**Windows**
