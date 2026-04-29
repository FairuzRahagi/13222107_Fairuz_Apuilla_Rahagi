#include <mpi.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <string>

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (argc != 2) {
        if (rank == 0) {
            std::cerr << "Error: Nama file tidak disertakan." << std::endl;
            std::cerr << "Cara pakai: mpiexec -n <jumlah_core> openMPI.exe <nama_file.txt>" << std::endl;
        }
        MPI_Finalize();
        return 1;
    }

    std::vector<double> data;
    int total_elements = 0;
    double start_time = 0.0, end_time = 0.0;
    std::string filename = argv[1]; // Mengambil nama file dari argumen terminal

    // 2. Proses Root (Rank 0) membaca data dan mencatat waktu mulai
    if (rank == 0) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Error: Tidak dapat membuka file dataset: " << filename << std::endl;
            MPI_Abort(MPI_COMM_WORLD, 1);
        }

        double val;
        while (file >> val) {
            data.push_back(val);
        }
        file.close();
        total_elements = data.size();

        // Mencatat waktu mulai eksekusi setelah I/O selesai
        start_time = MPI_Wtime();
    }

    // Broadcast jumlah elemen ke semua proses agar bisa mengalokasikan memori
    MPI_Bcast(&total_elements, 1, MPI_INT, 0, MPI_COMM_WORLD);

    if (total_elements == 0) {
        if (rank == 0) std::cerr << "Peringatan: File dataset kosong atau format tidak sesuai." << std::endl;
        MPI_Finalize();
        return 0;
    }

    // Menghitung ukuran array untuk didistribusikan
    std::vector<int> sendcounts(size);
    std::vector<int> displs(size);
    int rem = total_elements % size;
    int offset = 0;

    for (int i = 0; i < size; ++i) {
        sendcounts[i] = total_elements / size + (i < rem ? 1 : 0);
        displs[i] = offset;
        offset += sendcounts[i];
    }

    // Alokasi memori lokal untuk setiap proses
    std::vector<double> local_data(sendcounts[rank]);

    // 3. Scatter: Membagikan data secara merata ke seluruh proses
    MPI_Scatterv(rank == 0 ? data.data() : nullptr, sendcounts.data(), displs.data(), MPI_DOUBLE,
        local_data.data(), sendcounts[rank], MPI_DOUBLE, 0, MPI_COMM_WORLD);

    // 4. Komputasi Paralel: Setiap proses mengurutkan bagian array-nya
    std::sort(local_data.begin(), local_data.end());

    // 5. Gather: Mengumpulkan kembali potongan array yang sudah terurut ke Root
    MPI_Gatherv(local_data.data(), sendcounts[rank], MPI_DOUBLE,
        rank == 0 ? data.data() : nullptr, sendcounts.data(), displs.data(), MPI_DOUBLE, 0, MPI_COMM_WORLD);

    // 6. Penggabungan & Validasi (Proses Root)
    if (rank == 0) {
        // Melakukan final merge
        int current_size = sendcounts[0];
        for (int i = 1; i < size; ++i) {
            std::inplace_merge(data.begin(), data.begin() + current_size, data.begin() + current_size + sendcounts[i]);
            current_size += sendcounts[i];
        }

        // Mencatat waktu akhir komputasi
        end_time = MPI_Wtime();

        // Output Validasi
        std::cout << "====== Laporan Eksekusi (Parallel Merge Sort) ======" << std::endl;
        std::cout << "File Dataset         : " << filename << std::endl;
        std::cout << "Total Data Diurutkan : " << total_elements << " elemen" << std::endl;
        std::cout << "Jumlah Proses (Rank) : " << size << " proses" << std::endl;
        std::cout << "Waktu Komputasi      : " << std::fixed << std::setprecision(6) << (end_time - start_time) << " detik" << std::endl;
        std::cout << "====================================================" << std::endl;

        std::cout << "\n[10 Angka Pertama (Terkecil)]:\n";
        for (int i = 0; i < std::min(10, total_elements); ++i) {
            std::cout << data[i] << "  ";
        }
        std::cout << "\n";

        std::cout << "\n[10 Angka Terakhir (Terbesar)]:\n";
        for (int i = std::max(0, total_elements - 10); i < total_elements; ++i) {
            std::cout << data[i] << "  ";
        }
        std::cout << "\n" << std::endl;
    }

    MPI_Finalize();
    return 0;
}