#include <iostream>

// Mendefinisikan fungsi (Tipe Kembalian: double, Nama: hitungVolumeBalok)  
double hitungVolumeBalok(double panjang, double lebar, double tinggi) {  
    return panjang * lebar * tinggi; // Mengembalikan hasil perhitungan  
}

int main() {  
    // Memanggil fungsi dan menyimpannya ke variabel 'volume'  
    double volume = hitungVolumeBalok(10.5, 5.0, 2.0);  
      
    std::cout << "Volume balok: " << volume << std::endl;  
    return 0;  
}