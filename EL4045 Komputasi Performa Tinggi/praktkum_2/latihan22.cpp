#include <iostream>

// Menggunakan simbol & (reference) agar mengakses memori asli di fungsi main  
void tukarNilai(int &a, int &b) {  
    int sementara = a; // Simpan nilai A agar tidak hilang ditimpa  
    a = b;             // Timpa A dengan B  
    b = sementara;     // Isi B dengan nilai A yang lama  
}

int main() {  
    int x = 100, y = 500;  
      
    std::cout << "Sebelum ditukar : x = " << x << ", y = " << y << std::endl;  
    tukarNilai(x, y);   
    std::cout << "Setelah ditukar : x = " << x << ", y = " << y << std::endl;  
      
    return 0;  
}