#include <iostream>
#include <string>

using namespace std;

string terbilang(int angka) {
	string satuan[] = {"nol", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan"};

	if (angka < 10) {
		return satuan[angka];
	}
	if (angka == 10) {
		return "sepuluh";
	}
	if (angka == 11) {
		return "sebelas";
	}
	if (angka < 20) {
		return satuan[angka - 10] + " belas";
	}
	if (angka == 100) {
		return "seratus";
	}
	if (angka < 100) {
		int puluhan = angka / 10;
		int sisa = angka % 10;
		string hasil = satuan[puluhan] + " puluh";
		if (sisa != 0) {
			hasil += " " + satuan[sisa];
		}
		return hasil;
	}

	return "";
}

int main() {
	int angka;
	cout << "Masukkan angka (0-100): ";
	cin >> angka;

	if (cin.fail() || angka < 0 || angka > 100) {
		cout << "Input harus berupa bilangan bulat dari 0 sampai 100." << endl;
		return 1;
	}

	cout << terbilang(angka) << endl;
	return 0;
}