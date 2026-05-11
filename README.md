# Power Quality Waveform Analyser

C99 command-line tool that analyses 3-phase power quality data from a CSV log file.

Written for UWE's Programming for Engineers coursework (UGMFGT-15-1), Year 1.

## What it does

The program reads a CSV file containing 1,000 voltage samples taken from a 3-phase industrial power supply. The samples are recorded at 5 kHz over 200 milliseconds, which covers 10 full cycles of a 50 Hz waveform.

For each of the three phases (A, B, C), it works out:

- **RMS voltage** — should be around 230 V if the supply is healthy
- **Peak-to-peak amplitude** — the difference between the highest and lowest voltage
- **DC offset** — the average voltage, which should be near zero for clean AC
- **Clipping count** — how many samples hit the sensor's 324.9 V limit
- **Tolerance check** — whether the RMS is within 10% of 230 V

The results get printed to the console and also saved to `results.txt`.

## Project files

| File | What it does |
|------|--------------|
| `main.c` | The entry point. Validates input, calls everything in order, frees memory at the end. |
| `io.c` / `io.h` | Reads the CSV file and writes the results report. |
| `waveform.c` / `waveform.h` | Holds the `WaveformSample` struct and all the analysis functions. |
| `CMakeLists.txt` | The build configuration for CLion. |
| `power_quality_log.csv` | Sample input data. |
| `results.txt` | Example output (created when you run the program). |

## Compiling with GCC

**Windows**

**Repository:**
https://github.com/m0hu55ain2072-stack/Final_Power_Quality_Waveform_Analyser


