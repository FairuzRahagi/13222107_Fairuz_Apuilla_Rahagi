#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class RekeningBank {
private:
    double saldo;

public:
    RekeningBank(double saldoAwal) {
        if (saldoAwal >= 0) {
            saldo = saldoAwal;
        }
        else {
            saldo = 0;
            cout << "Peringatan: Saldo awal tidak boleh negatif. Set ke 0." << endl;
        }
    }

    void setor(double jumlah) {
        saldo += jumlah;
        cout << "Berhasil setor: " << fixed << setprecision(0) << jumlah << ". Saldo sekarang: " << saldo << endl;
    }

    void tarik(double jumlah) {
        if (jumlah > saldo) {
            cout << "Penarikan Gagal!" << endl;
        }
        else {
            saldo -= jumlah;
            cout << "Penarikan Berhasil. Sisa saldo: " << fixed << setprecision(0) << saldo << endl;
        }
    }

    double cekSaldo() {
        return saldo;
    }
};

int main() {
    RekeningBank rekeningSaya(1000000);

    cout << "--- Simulasi Transaksi Bank ---" << endl;
    cout << "Saldo Awal: " << fixed << setprecision(0) << rekeningSaya.cekSaldo() << endl;

    rekeningSaya.setor(500000);
    rekeningSaya.tarik(200000);
    rekeningSaya.tarik(2000000);

    return 0;
}