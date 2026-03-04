#include <iostream>

int main() {  
    double nilai;  
    std::cout << "Masukkan nilai observasi (0 - 100): ";  
    std::cin >> nilai;

    if (nilai < 0 || nilai > 100) {  
        std::cout << "Error: Nilai di luar batas wajar (Anomali)." << std::endl;  
    } else if (nilai >= 70) {  
        std::cout << "Status: Valid dan Memenuhi Syarat." << std::endl;  
    } else {  
        std::cout << "Status: Valid tapi Tidak Memenuhi Syarat." << std::endl;  
    }

    return 0;  
}