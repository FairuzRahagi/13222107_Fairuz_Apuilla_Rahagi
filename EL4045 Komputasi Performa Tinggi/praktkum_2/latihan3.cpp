#include <iostream>

int main() {  
    const int ukuran = 5; // Ukuran array klasik harus statis (diketahui dari awal)  
      
    int vektorA[ukuran] = {1, 2, 3, 4, 5};  
    int vektorB[ukuran] = {10, 20, 30, 40, 50};  
    int hasil[ukuran];

    // Iterasi memproses elemen yang sejajar satu per satu  
    for(int i = 0; i < ukuran; i++) {  
        hasil[i] = vektorA[i] + vektorB[i];  
        std::cout << "Elemen indeks ke-" << i << ": " << hasil[i] << std::endl;  
    }  
      
    return 0;  
}