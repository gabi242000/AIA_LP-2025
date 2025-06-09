
@echo off
cls
echo === Compilare simulator C++ ===
g++ simulare.cpp -o simulator.exe

if exist simulator.exe (
    echo === RULARE SIMULATOR + INTERFATA ===

    :loop
    echo --- Actualizare sim.json ---
    simulator.exe
    timeout /t 1 >nul
    echo --- Redeschidere interfata grafica ---
    start python interfata_grafica.py
    timeout /t 1 >nul
    taskkill /im python.exe >nul
    goto loop
) else (
    echo EROARE: Compilarea a eșuat!
)

pause
