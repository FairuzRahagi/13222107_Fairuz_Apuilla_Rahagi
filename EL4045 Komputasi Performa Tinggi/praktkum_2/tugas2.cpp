#include <iostream>

void kuadratkan(int* val) {
	*val = (*val) * (*val);
}

int main() {
	int angka = 5;
	kuadratkan(&angka);
	std::cout << "Nilai kuadrat: " << angka << std::endl;
	return 0;
}