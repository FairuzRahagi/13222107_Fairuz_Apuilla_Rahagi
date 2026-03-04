#include <iostream>

int main() {  
    // Matriks 2 dimensi: [2 Baris] x [3 Kolom]  
    int matriks[2][3] = {   
        {1, 2, 3},   
        {4, 5, 6}   
    };  
    int pengali = 2;  
      
    // Loop Baris (Dimensi 1 - Luar)  
    for(int i = 0; i < 2; i++) {  
          
        // Loop Kolom (Dimensi 2 - Dalam)  
        for(int j = 0; j < 3; j++) {  
            matriks[i][j] = matriks[i][j] * pengali;  
            std::cout << matriks[i][j] << "\t"; // \t untuk spasi Tab  
        }  
          
        std::cout << std::endl; // Pindah baris setelah 1 baris kolom selesai  
    }  
      
    return 0;  
}