# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Azzamy Gusalim Herfino - 109082500091</p>

## Dasar Teori
isi dengan penjelasan dasar teori disertai referensi jurnal (gunakan kurung siku [] untuk pernyataan yang mengambil refernsi dari jurnal).
contoh :
Linked list atau yang disebut juga senarai berantai adalah Salah satu bentuk struktur data yang berisi kumpulan data yang tersusun secara sekuensial, saling bersambungan, dinamis, dan terbatas[1]. Linked list terdiri dari sejumlah node atau simpul yang dihubungkan secara linier dengan bantuan pointer.

## Unguided 

### 1. Buatlah program yang menerima input-an dua buah bilangan betipe float, kemudian memberikan output-an hasil penjumlahan, pengurangan, perkalian, dan pembagian dari dua bilangan tersebut. 

```C++
source code unguided 1
#include <iostream>

using std::cin;
using std::cout;

int main() {
    double angkaPertama, angkaKedua;

    cout << "Masukkan dua bilangan float: ";
    cin >> angkaPertama >> angkaKedua;

    cout << "Penjumlahan: " << angkaPertama + angkaKedua << '\n';
    cout << "Pengurangan: " << angkaPertama - angkaKedua << '\n';
    cout << "Perkalian: " << angkaPertama * angkaKedua << '\n';

    if (angkaKedua == 0.0) {
        cout << "Pembagian: tidak dapat dilakukan karena pembagi bernilai nol.\n";
    } else {
        cout << "Pembagian: " << angkaPertama / angkaKedua << '\n';
    }
    
    return 0;
}
```
### Output Unguided 1 :

##### Output 1
https://github.com/zemmmyy07/LAPRAK-STRUKTUR-DATA/blob/main/UNGUIDED1/Screenshot%202026-09-30%20000625.png

##### Output 2
https://github.com/zemmmyy07/LAPRAK-STRUKTUR-DATA/blob/main/UNGUIDED1/Screenshot%202026-09-30%20000643.png

## penjelasan unguided 1 
Program pada nomor satu bekerja dengan membaca dua masukan bilangan bertipe float lalu secara langsung melakukan empat operasi aritmatika dasar, yaitu penjumlahan, pengurangan, perkalian, dan pembagian. Agar program tidak mengalami kesalahan sistem saat mengeksekusi perhitungan pembagian, kode dilengkapi dengan pengondisian untuk memastikan bahwa bilangan pembagi tidak bernilai nol. Seluruh hasil perhitungan tersebut kemudian dicetak kembali ke layar dengan format desimal yang rapi.

### 2. Buatlah sebuah program yang menerima masukan angka dan mengeluarkan output nilai angka tersebut dalam bentuk tulisan. Angka yang akan di- input-kan user adalah bilangan bulat positif mulai dari 0 s.d 100 

```C++
source code unguided 2
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
```
### Output Unguided 2 :

##### Output 1
https://github.com/zemmmyy07/LAPRAK-STRUKTUR-DATA/blob/main/UNGUIDED2/Screenshot%202026-09-30%20002227.png

##### Output 2
https://github.com/zemmmyy07/LAPRAK-STRUKTUR-DATA/blob/main/UNGUIDED2/Screenshot%202026-09-30%20002236.png

## penjelasan unguided 2
Program pada nomor dua bekerja dengan mengonversi angka bulat dari rentang 0 sampai 100 menjadi bentuk tulisan terbilang. Logikanya diawali dengan memvalidasi rentang input, lalu memetakan angka dasar 0 sampai 11 serta angka 100 secara langsung ke dalam kata. Untuk angka belasan di rentang 12 hingga 19, program mengambil sisa angka setelah dikurangi 10 dan menambahkan kata "belas" di belakangnya. Sedangkan untuk angka puluhan dari 20 hingga 99, program memecah nilai tersebut menggunakan operasi pembagian untuk menentukan kata puluhan dan operasi sisa bagi untuk menentukan kata satuan, lalu menggabungkannya menjadi satu kalimat terbilang yang utuh.

### 3. Buatlah program yang dapat memberikan input dan output sbb.

```C++
source code unguided 3
#include <iostream>
using namespace std;

int main() {
    int angka;
    cout << "Masukkan angka: ";
    cin >> angka;
    for (int i = 0; i < angka ; i++) {
        for (int k = 0; k < i; k++) {
            cout << "  ";
        }
        for (int j = angka-i; j > 0; j--) {
            cout << j << " ";
        }
        cout << "* ";
        for (int j = 1 ; j <= angka-i; j++) {
            cout << j << " ";
        }   
        cout << '\n';
    }
    for(int i =0; i < angka; i++)
    {
        cout << "  ";
    }
    cout << "*";
    return 0;
}
```
### Output Unguided 3 :

##### Output 1
https://github.com/zemmmyy07/LAPRAK-STRUKTUR-DATA/blob/main/UNGUIDED3/Screenshot%202026-09-30%20003820.png

##### Output 2
https://github.com/zemmmyy07/LAPRAK-STRUKTUR-DATA/blob/main/UNGUIDED3/Screenshot%202026-09-30%20003838.png

## penjelasan unguided 3
Program pada nomor tiga bekerja dengan menggunakan perulangan bertingkat untuk mencetak pola angka simetris yang semakin menyempit ke bawah. Prosesnya dikontrol oleh perulangan utama yang berjalan menurun dari angka masukan hingga mencapai nol. Pada setiap baris, program mencetak spasi di bagian awal agar tampilan terdorong ke tengah, lalu mencetak urutan angka menurun di sebelah kiri, dilanjutkan dengan karakter bintang tepat di tengah, dan diakhiri dengan urutan angka menaik di sebelah kanan. Ketika perulangan mencapai angka nol pada baris paling akhir, program hanya akan mencetak karakter bintang di tengah tanpa ada deretan angka di sekitarnya.

## Kesimpulan
### Ketiga program ini melatih logika pemrograman dasar, mulai dari penanganan tipe data desimal dan validasi pembagian nol, pemecahan angka menjadi kata terbilang, hingga penggunaan perulangan bertingkat untuk mencetak pola simetris. Secara keseluruhan, ketiga latihan ini memberikan fondasi utama dalam penyusunan alur algoritma, perhitungan logika matematika, serta manipulasi tampilan output.

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
