
#include <iostream>
double hitungRataRata(double arr[], int size) {
	double sum = 0;
	for (int i = 0; i < size; i++) {
		sum += arr[i];
	}
	return sum / size;
}

int main() {
	double arr[5] = { 2,3,1,2,4 };
	std::cout << hitungRataRata(arr, 5);
}