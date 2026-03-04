#include <iostream>

int main() {  
    int angka = 100;  
    int *ptr_angka = &angka; // Pointer menyimpan alamat memori dari variabel 'angka'

    std::cout << "Nilai variabel angka: " << angka << std::endl;  
    std::cout << "Alamat memori angka (&angka): " << &angka << std::endl;  
    std::cout << "Isi dari pointer ptr_angka: " << ptr_angka << std::endl;  
    std::cout << "Nilai yang ditunjuk pointer (*ptr_angka): " << *ptr_angka << std::endl;

    return 0;  
}