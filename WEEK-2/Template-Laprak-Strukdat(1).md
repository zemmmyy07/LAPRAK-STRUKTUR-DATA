# <h1 align="center">Laporan Praktikum Modul 2 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center"> Azzamy Gusalim Herfino - 109082500091</p>

## Dasar Teori
Dalam pemrograman C++, pemahaman mengenai struktur data dasar, dan alokasi memori kode sangatlah penting. Konsep dasar yang sering digunakan antara lain Pointer, Function, dan Procedure.

### A. Pointer 
Pointer adalah variabel yang menyimpan alamat memori dari variabel lain, bukan menyimpan nilainya secara langsung. Dengan pointer, kita dapat melakukan pperubahan data langsung di lokasi memori, serta dapat memindahkan variabel pada program.

### B. Function
Function adalah blok kode terpisah yang menerima masukan (parameter), melakukan proses tertentu, dan mengembalikan suatu nilai (return value) ke pemanggilnya.

### C. Procedure
Procedure pada dasarnya mirip dengan fungsi, namun tidak mengembalikan nilai (menggunakan tipe void). Prosedur digunakan untuk mengeksekusi serangkaian instruksi seperti menampilkan output atau mengubah nilai variabel global.

## Guided 

### 1. Array 1

```C++
source code guided 1
```int main() {
    int nilai[5];

    nilai[0] = 80;
    nilai[1] = 75;
    nilai[2] = 90;
    nilai[3] = 85;
    nilai[4] = 95;

    for (int i = 0; i < 5; i++) {
        cout << "Nilai ke-" << i + 1 << " = " << nilai[i] << endl;
    }

    return 0;
}
```
penjelasan singkat guided 1
#### Program ini mendeskripsikan penggunaan Array 1 Dimensi berukuran 5 elemen untuk menyimpan nilai integer, lalu mencetak setiap elemennya menggunakan perulangan for.

### 2. Array 2

```C++
source code guided 2
```#include <iostream>
using namespace std;

int main() {
    int nilai[3][3] = {
        {80, 75, 90},
        {85, 90, 88},
        {70, 80, 85}
    };

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << nilai[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << nilai[1][2] << endl;
    return 0;
}
```
penjelasan singkat guided 2
#### Program mengimplementasikan Array 2 Dimensi (matriks 3x3). Program menampilkan seluruh matriks menggunakan nested loop serta mengakses elemen spesifik pada baris indeks ke-1 dan kolom indeks ke-2.

### 3. Array 3

```C++
source code guided 3
```#include <iostream>
using namespace std;

int main() {
    int data[2][2][3] = {
        {
            {10, 20, 30},
            {40, 50, 60}
        },
        {
            {70, 80, 90},
            {100, 110, 120}
        }
    };

    cout << data[0][1][2] << endl;

    return 0;
}
```
penjelasan singkat guided 3
#### Program ini mendemonstrasikan Array 3 Dimensi berukuran 2 x 2 x 3 dan mencetak nilai pada posisi indeks [0][1][2], yaitu 60.

### 4. Alamat 

```C++
#include <iostream>
using namespace std;

int main() {
    int angka = 100;

    cout << "Nilai Angka : " << angka << endl;
    cout << "Alamat Angka : " << &angka << endl;

    return 0;
}
```
penejelasan singkat guided 4 : 
#### Program ini menampilkan nilai dari variabel angka (100) dan mengakses alamat memori variabel tersebut di RAM dengan menggunakan operator address-of (&angka).

### 5. Pointer 1 dan 2

```C++
//Pointer 1
#include <iostream>
using namespace std;

int main() {
    char arr[6];

    arr[0] = 'a';
    arr[1] = 'b';
    arr[2] = 'c';
    arr[3] = 'b';
    arr[4] = 'd';
    arr[5] = 'e';

    cout << arr[3] << endl;
    cout << &(arr[4]) << endl;

}

// Pointer 2
#include <iostream>
using namespace std;

int main() {
    int angka = 100;

    int *pointer;

    pointer = &angka;

    cout << "Nilai angka       :" << angka << endl;
    cout << "Alamat angka      :" << &angka << endl;
    cout << "Isi pointer       :" << pointer << endl;
    cout << "Nilai dari pointer:" << *pointer << endl;


    return 0;

}
```
penjelasan singkat guided 5 :
#### Program menampilkan nilai elemen array karakter pada indeks ke-3 ('b') dan menampilkan alamat memori dari elemen indeks ke-4 (&(arr[4])) menggunakan operator address-of (&). Program ini menunjukkan dasar variabel pointer. Variabel pointer menyimpan alamat dari angka, dan operator dereference (*pointer) digunakan untuk mengakses nilai yang ada pada alamat tersebut (100).

### 6. Function

```C++
#include <iostream>
using namespace std;

int maks3(int a, int b, int c){
    int temp_max = a;

    if (b > temp_max){
        temp_max = b;
    }

    if (c > temp_max){
        temp_max = c;
    }

    return temp_max;
}

int main() {
    int x, y, z;

    cout << "Masukkan nilai 1: ";
    cin >> x;

    cout << "Masukkan nilai 2: ";
    cin >> y;

    cout << "Masukkan nilai 3: ";
    cin >> z;

    cout << "Nilai maksimum = " << maks3(x, y, z);

    return 0;

}
```
penjelasan singkat guided 6 :
#### Program menggunakan fungsi maks3() yang menerima 3 masukan integer dan mengembalikan nilai terbesar di antara ketiganya.

### 7. Procedure

```C++
#include <iostream>
using namespace std;

void sapa() {
    cout << "Selamat datang di Telkom University Purwokero" << endl;
}

int main() {
    sapa();
    return 0;
}
```
penjelasan singkat guided 7 :
#### Program ini menggunakan prosedur sapa() bernilai balik void untuk menampilkan teks ucapan selamat datang di layar tanpa mengembalikan nilai data apapun.

### 8. callby Value/Pointer/Reference

```C++
//Value
#include <iostream>
using namespace std;

void tukar(int x, int y) {
    int temp;

    temp = x;
    x = y;
    y = temp;
}

int main() {
    int a = 4;
    int b = 6;

    cout << "Sebelum ditukar:" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    tukar(a, b);

    cout << "\nSetelah ditukar:" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    return 0;
}
//Pointer
#include <iostream>
using namespace std;

void tukar(int *x, int *y) {
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int a = 4;
    int b = 6;

    cout << "Sebelum ditukar:" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    tukar(&a, &b);

    cout << "\nSetelah ditukar:" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    return 0;
}
// Reference
#include <iostream>

using namespace std;

void tukar(int &x, int &y);

int main () {
    int a, b;
    a=4;  b=6;
    cout << "kondisi sebelum ditukar \n";
    cout << " a = "<<a<<" b = "<<b<<endl;
    tukar(a,b);
    cout<<"kondisi setelah ditukar \n";
    cout << " a = "<<a<<" b = "<<b<<endl;
    return 0;
}

void tukar (int &x, int &y) {
    int temp;
    temp = x;
    x = y;
    y = temp;
    cout<< "nilai akhir pada fungsi tukar \n";
    cout << " x = "<<x<<" y="<<y<<endl;
}
```
penjelasan singkat guided 8 :
#### Program membandingkan 3 metode pemanggilan parameter:Call by Value: Perubahan nilai di fungsi tidak mengubah nilai asli variabel di main(). Call by Pointer: Mengirimkan alamat memori (&a), perubahan pada pointer mempengaruhi nilai asli variabel di main().    Call by Reference: Menggunakan alias (&x), perubahan langsung mengubah variabel asli di main()


## Unguided 

### 1. Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian matriks 3x3  

```C++
#include <iostream>
using namespace std;

int main() {
    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int B[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    int Hasil[3][3];

    cout << "=== HASIL PENJUMLAHAN (A + B) ===" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            Hasil[i][j] = A[i][j] + B[i][j];
            cout << Hasil[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    cout << "=== HASIL PENGURANGAN (A - B) ===" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            Hasil[i][j] = A[i][j] - B[i][j];
            cout << Hasil[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    cout << "=== HASIL PERKALIAN (A x B) ===" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            
            Hasil[i][j] = 0;

            for (int k = 0; k < 3; k++) {
                Hasil[i][j] += A[i][k] * B[k][j];
            }

            cout << Hasil[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
```
### Output Unguided 1 :
https://github.com/zemmmyy07/LAPRAK-STRUKTUR-DATA/blob/main/WEEK-2/UNGUIDED/UNGUIDED-1/Screenshot%202026-10-07%20180235.png

penjelasan unguided 1 :
#### Program mengimplementasikan Array 2D untuk menghitung matriks 3x3. Operasi penjumlahan dan pengurangan dihitung elemen per elemen, sedangkan perkalian matriks menggunakan tiga tingkatan perulangan (nested loop) untuk mengalikan baris matriks A dengan kolom matriks B.


### 2. Berdasarkan guided pointer dan reference sebelumnya, buatlah keduanya dapat menukar nilai dari 3 variabel  

```C++
//Pointer
#include <iostream>
using namespace std;

void tukar(int *x, int *y, int *z) {
    int temp = *x; 
    *x = *z;       
    *z = *y;       
    *y = temp;    
}

int main() {
    int a = 4;
    int b = 6;
    int c = 8;

    cout << "Sebelum ditukar:" << endl;
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;

    tukar(&a, &b, &c);

    cout << "\nSetelah ditukar:" << endl;
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;

    return 0;
}

//Reference
#include <iostream>
using namespace std;

void tukar(int &x, int &y, int &z);

int main() {
    int a = 4, b = 6, c = 8;

    cout << "kondisi sebelum ditukar \n";
    cout << " a = " << a << " b = " << b << " c = " << c << endl;

    tukar(a, b, c);

    cout << "\nkondisi setelah ditukar \n";
    cout << " a = " << a << " b = " << b << " c = " << c << endl;

    return 0;
}

void tukar(int &x, int &y, int &z) {
    int temp = x; 
    x = z;        
    z = y;      
    y = temp;     

    cout << "\nnilai akhir pada fungsi tukar \n";
    cout << " x = " << x << " y = " << y << " z = " << z << endl;
}
```
### Output Unguided 2 :
https://github.com/zemmmyy07/LAPRAK-STRUKTUR-DATA/blob/main/WEEK-2/UNGUIDED/UNGUIDED-2/Screenshot%202026-10-07%20182218.png

https://github.com/zemmmyy07/LAPRAK-STRUKTUR-DATA/blob/main/WEEK-2/UNGUIDED/UNGUIDED-2/Screenshot%202026-10-07%20182305.png

penjelasan unguided 2 :
#### Program ini melakukan penukaran posisi nilai 3 variabel (a, b, c) secara berputar menggunakan fungsi dengan perantara pointer (*) dan reference (&), sehingga nilai pada variabel di main() langsung berubah.


### 3. Diketahui sebuah array 1 dimensi sebagai berikut :  arrA = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55} Buatlah program yang dapat mencari nilai minimum, maksimum, dan rata – rata dari array tersebut! Gunakan function cariMinimum() untuk mencari nilai minimum dan function cariMaksimum() untuk mencari nilai maksimum, serta gunakan prosedur hitungRataRata() untuk menghitung nilai rata – rata! Buat program menggunakan menu switch-case seperti berikut ini : --- Menu Program Array ---  • Tampilkan isi array  • cari nilai maksimum • cari nilai minimum  • Hitung nilai rata - rata 

```C++
#include <iostream>
using namespace std;

int cariMinimum(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int cariMaksimum(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void hitungRataRata(int arr[], int n) {
    double total = 0;
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }
    double rataRata = total / n;
    cout << "Nilai rata-rata dari array: " << rataRata << endl;
}

void tampilkanArray(int arr[], int n) {
    cout << "Isi array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // Inisialisasi array sesuai soal
    int arrA[] = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55};
    int n = sizeof(arrA) / sizeof(arrA[0]); // Menghitung jumlah elemen array (10 elemen)
    int pilihan;

    do {
        cout << "\n--- Menu Program Array ---" << endl;
        cout << "1. Tampilkan isi array" << endl;
        cout << "2. Cari nilai maksimum" << endl;
        cout << "3. Cari nilai minimum" << endl;
        cout << "4. Hitung nilai rata - rata" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu (1-5): ";
        cin >> pilihan;
        cout << endl;

        switch (pilihan) {
            case 1:
                tampilkanArray(arrA, n);
                break;
            case 2:
                cout << "Nilai maksimum: " << cariMaksimum(arrA, n) << endl;
                break;
            case 3:
                cout << "Nilai minimum: " << cariMinimum(arrA, n) << endl;
                break;
            case 4:
                hitungRataRata(arrA, n);
                break;
            case 5:
                cout << "Terima kasih, program selesai." << endl;
                break;
            default:
                cout << "Pilihan tidak valid! Silakan masukkan angka 1-5." << endl;
                break;
        }

    } while (pilihan != 5);

    return 0;
}
```
### Output Unguided 3 :
https://github.com/zemmmyy07/LAPRAK-STRUKTUR-DATA/blob/main/WEEK-2/UNGUIDED/UNGUIDED-3/Screenshot%202026-10-07%20182416.png

https://github.com/zemmmyy07/LAPRAK-STRUKTUR-DATA/blob/main/WEEK-2/UNGUIDED/UNGUIDED-3/Screenshot%202026-10-07%20182432.png

penjelasan unguided 3 :
#### Program ini mengelola data array 1 dimensi menggunakan mwnu switch-case. Perhitungan nilai minimum dan maksimum dikembalikan melalui fungsi cariMinimum() dan cariMaksimum(), sedangkan pencetakan array dan perhitungan rata-rata dilakukan melalui prosedur.

## Kesimpulan

#### Berdasarkan praktikum Modul 1 ini, dapat disimpulkan bahwa:
 1. Array (1D, 2D, 3D) memfasilitasi pengelompokan dan pengolahan data sejenis secara berurutan di dalam memori.
 2. Pointer dan Reference memungkinkan manipulasi data langsung pada lokasi memori fisik melalui pemanggilan parameter.(Call by Pointer/Reference). 
 3. Function dan Procedure meningkatkan modularitas kode C++ sehingga program menjadi lebih rapi dan mudah dikembangkan.
