@echo off
echo ========================================================
echo Memulai Pengujian Otomatis MPI Parallel Merge Sort
echo ========================================================
echo.

:: Deklarasi variabel
set APP=openMPI.exe
set DATASETS=data_10000.txt data_100000.txt data_1000000.txt
set CORES=1 2 4 8

:: Looping untuk setiap dataset
for %%d in (%DATASETS%) do (
    echo ========================================================
    echo MENGUJI DATASET: %%d
    echo ========================================================
    
    :: Looping untuk setiap konfigurasi prosesor
    for %%c in (%CORES%) do (
        echo [Menjalankan dengan %%c Prosesor...]
        mpiexec -n %%c %APP% %%d
        echo.
    )
)

echo Pengujian Selesai! Tekan tombol apa saja untuk keluar.
pause