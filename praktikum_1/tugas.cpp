#include <iostream>

int main() {
    int total = 0;
    int angka;

    // Input 5 angka
    for (int i = 1; i < 6; i++){
        while (true) {
            std::cout << "Masukkan angka positif ke-" << i << std::endl;
            std::cin >> angka;
            if (std::cin.fail()) {
                std::cout << "Input tidak valid, input harus berupa integer \n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else{
                if (angka > 0) {
                    total += angka;
                }
                break;
            }
        }
    }

    std::cout << "Total angka positif anda: " << total << std::endl;
    return 0;
}