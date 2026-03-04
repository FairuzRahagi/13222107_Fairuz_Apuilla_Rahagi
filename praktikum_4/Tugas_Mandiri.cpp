
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
	vector<double> sensor;

	sensor.push_back(100.5);
	sensor.push_back(200.0);
	sensor.push_back(150.5);

	for (int i = 0; i < sensor.size(); i++) {
		sensor[i] = sensor[i] * 1.1;
	}

	ofstream fileOutput("hasil_kalibrasi.txt");

	if (fileOutput.is_open()) {
		cout << "File berhasil dibuat \n" << endl;
		for (int i = 0; i < sensor.size(); i++) {
			fileOutput << fixed << setprecision(2) << sensor[i] << "\n";
		}
		fileOutput.close();
		cout << "kalibrasi berhasil!" << endl;
	}
	else {
		cout << "Pembukaan file gagal!" << endl;
	}
}
