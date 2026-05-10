<img width="637" height="359" alt="Screenshot 2026-05-09 231632" src="https://github.com/user-attachments/assets/08d990e8-c8ba-4ceb-b319-4514070a3604" />


To compile this app with GCC

Windows
gcc main.c io.c waveform.c -o PowerQualityAnalyser.exe -lm

Linux/MacOS
gcc main.c io.c waveform.c -o PowerQualityAnalyser -lm

To run with gcc

Windows
./PowerQualityAnalyser.exe power_quality_log.csv

Linux/MacOS
./PowerQualityAnalyser power_quality_log.csv
