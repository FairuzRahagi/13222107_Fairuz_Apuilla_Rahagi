#include <iostream>

int main() {  
    int angka = -1;

    // Loop akan terus berjalan SELAMA kondisi bernilai benar (angka negatif)  
    while (angka < 0) {  
        std::cout << "Masukkan angka positif: ";  
        std::cin >> angka;

        if (angka < 0) {  
            std::cout << "Salah! Angka tidak boleh negatif.\n";  
        }  
    }

    std::cout << "Terima kasih. Anda memasukkan angka: " << angka << std::endl;  
    return 0;  
}