#include <iostream>

int main() {  
    char pilihan;

    do {  
        std::cout << "\n--- Menu Pemrosesan ---" << std::endl;  
        std::cout << "Menjalankan komputasi data..." << std::endl;  
        std::cout << "Komputasi selesai!" << std::endl;

        std::cout << "Apakah Anda ingin memproses data lagi? (Y/T): ";  
        std::cin >> pilihan;  
          
    } while (pilihan == 'Y' || pilihan == 'y');

    std::cout << "Program dihentikan." << std::endl;  
    return 0;  
}