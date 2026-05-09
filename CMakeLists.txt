cmake_minimum_required(VERSION 4.1)
project(Final_Power_Quality_Waveform_Analyser C)

set(CMAKE_C_STANDARD 99)

add_executable(Final_Power_Quality_Waveform_Analyser
        main.c
        Waveform.c
        Waveform.h
        io.c
        io.h)
