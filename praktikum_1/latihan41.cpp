#include <iostream>

int main() {  
    int batas_atas;  
    int total_jumlah = 0; // Akumulator

    std::cout << "Masukkan batas atas angka: ";  
    std::cin >> batas_atas;

    // for(inisialisasi; kondisi; update)  
    for (int i = 1; i <= batas_atas; i++) {  
        total_jumlah = total_jumlah + i;  
    }

    std::cout << "Total penjumlahan dari 1 hingga "  
              << batas_atas  
              << " adalah: "  
              << total_jumlah << std::endl;

    return 0;  
}