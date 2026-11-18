# <h1 align="center">Modul 3 ABSTRACT DATA TYPE (ADT) </h1>
<p align="center">Azzamy Gusalim Herfino - 109082500091</p>

## Guided 

### 1. mahasiswa

```C++
// mahasiswa.cpp
#include <iostream>
#include "mahasiswa.h"
using namespace std;

void inputMhs(mahasiswa &m){
    cout << "input nim =";
    cin >> (m).nim;
    cout << "input nilai 1 =";
    cin >> (m).nilai1;
    cout << "input nilai 2=";
    cin >> (m).nilai2;
}

float rata2(mahasiswa m){
    return float(m.nilai1 + m.nilai2) / 2;
}
// mahasiswa.h
#ifndef MAHASISWA_H_INCLUDE 
#define MAHASISWA_H_INCLUDE

struct mahasiswa{
    char nim[10];
    int nilai1,nilai2;
};

void inputMhs (mahasiswa &m);
float rata2 (mahasiswa m);
#endif
// main.cpp
#include <iostream>
#include "mahasiswa.h"
using namespace std;

int main(){
    mahasiswa mhs;
    inputMhs(mhs);
    cout << "rata rata " << rata2(mhs) << endl;
    return 0;
}

```
### Penjelasan                                                                                Program guided ini menggunakan `struct mahasiswa` untuk menggabungkan data yang terkait, yaitu `nim`, `nilai1`, dan `nilai2`, sehingga data mahasiswa dapat disimpan dalam satu variabel yang terstruktur; fungsi `inputMhs(mahasiswa &m)` memasukkan data ke variabel tersebut, dan fungsi `rata2(mahasiswa m)` menghitung rata-rata dengan rumus `(nilai1 + nilai2) / 2` agar hasil yang diperoleh sesuai dengan konsep rata-rata. Dengan demikian, ADT membantu program menjadi lebih terorganisir, mudah dibaca, dan lebih mudah dikelola karena data serta operasinya ditempatkan dalam satu kesatuan yang jelas.

## Unguided 

### 1.Buat program yang dapat menyimpan data mahasiswa (max. 10) ke dalam sebuah array dengan field nama, nim, uts, uas, tugas, dan nilai akhir. Nilai akhir diperoleh dari FUNGSI dengan rumus 0.3*uts+0.4*uas+0.3*tugas. folder mahasiswa

```C++
#include <iostream>
using namespace std;

struct mahasiswa
{
    char nama[50];
    int nim, uts, uas, tugas;
    float tugasakhir;
};

mahasiswa Mahasiswa[10];

int nilaiAkhir(mahasiswa *x) {
    x->tugasakhir = 0.3f * x->uts+0.4f * x->uas+0.3f * x->tugas;
    return x->tugasakhir;
}

int main () {
    int x;
    cout << "Masukan Jumlah Mahasiswa : ";
    cin >> x ;
    for (int i = 1; i <= x; i++){
        cout << "Masukan Mahasiswa Ke "<< i<< "\n";
        cout << "Masukan Nama : ";
        cin >> Mahasiswa[i].nama;
        cout << "Masukan NIM : ";
        cin >> Mahasiswa[i].nim;
        cout << "Masukan UTS : ";
        cin >> Mahasiswa[i].uts;
        cout << "Masukan UAS : ";
        cin >> Mahasiswa[i].uas;
        cout << "Masukan Tugas : ";
        cin >> Mahasiswa[i].tugas;
        Mahasiswa[i].tugasakhir = nilaiAkhir(&Mahasiswa[i]);
    }

    for (int i= 1; i <= x;i++)
    {
        cout << "Nilai Akhir " << Mahasiswa[i].nama << " : " << Mahasiswa[i].tugasakhir << "\n";
    }

    return 0;
}
```
### Output Unguided 1 :
<img width="973" height="606" alt="Screenshot 2026-11-18 202620" src="https://github.com/user-attachments/assets/cdddb60f-91b4-4b42-b1c3-b8c942695b79" />

##### penjelasan unguided 1 :                                                                Program ini menggunakan `struct mahasiswa` dan array `dataMahasiswa` untuk menyimpan data mahasiswa serta nilai UTS, UAS, dan tugas dalam satu struktur yang terorganisir, lalu fungsi `nilaiAkhir()` dengan parameter pointer menghitung nilai akhir berdasarkan bobot 0,3 untuk UTS, 0,4 untuk UAS, dan 0,3 untuk tugas, sehingga hasil perhitungan dapat disimpan dan ditampilkan secara otomatis pada setiap mahasiswa.

### 2.Buatlah ADT pelajaran sebagai berikut di dalam file “pelajaran.h” folder pelajaran

```C++
// pelajaran.cpp
#include <iostream>
#include "pelajaran.h"
using namespace std;

pelajaran create_pelajaran(string namapel, string kodepel)
{
    pelajaran pel;
    pel.namaMapel = namapel;
    pel.kodeMapel = kodepel;
    return pel;
}

void tampil_pelajaran(pelajaran pel)
{
    cout << "nama mapel: " << pel.namaMapel << "\n";
    cout << "nama kode mapel: " << pel.kodeMapel << "\n";
}
// pelajaran.h
#ifndef PELAJARAN_H_INCLUDE
#define PELAJARAN_H_INCLUDE
#include <iostream>
using namespace std;

struct pelajaran
{
    string namaMapel;
    string kodeMapel;
};

pelajaran create_pelajaran (string namapel, string kodepel);
void tampil_pelajaran(pelajaran pel);

#endif 
// main.cpp
#include <iostream>
#include "pelajaran.h"

using namespace std; 

int main()
{  string namapel = "Struktur Data";
    string kodepel = "STD"; 
    pelajaran pel = create_pelajaran(namapel,kodepel);  
    tampil_pelajaran(pel);   
    return 0; 
}   
```
### Output Unguided 2 :
<img width="1087" height="167" alt="Screenshot 2026-11-18 202747" src="https://github.com/user-attachments/assets/6605faa5-3e8d-45c4-9bce-36838b39eea0" />

##### Output 1

##### penjelasan unguided 2 :                                                               Program ini mengimplementasikan ADT pada mata pelajaran dengan membagi kodenya menjadi tiga file, yaitu `pelajaran.h` untuk deklarasi `struct` dan fungsi, `pelajaran.cpp` untuk implementasi pembuatan objek dan menampilkan data, serta `main.cpp` untuk menjalankan program utama; dengan cara ini, struktur data `pelajaran` dapat dibuat dan digunakan secara modular sehingga lebih rapi, mudah dipahami, dan mudah dikembangkan.

### 3.Buatlah program dengan ketentuan : - 2 buah array 2D integer berukuran 3x3 dan 2 buah pointer integer - fungsi/prosedur yang menampilkan isi sebuah array integer 2D - fungsi/prosedur yang akan menukarkan isi dari 2 array integer 2D pada posisi tertentu  fungsi/prosedur yang akan menukarkan isi dari variabel yang ditunjuk oleh 2 buah pointer folder array

```C++
#include <iostream>
using namespace std;


void tampilkan(int array[2][3][3])
{
    for (int i = 1; i <= 2; i++)
    {
        cout << "matrik ke"<< i<<"\n";
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                cout << array[i-1][j][k] << " ";
            }
            cout << "\n";
        }
    }
}

void ubah(int x1,int y1,int x2, int y2, int array[2][3][3])
{
    int temp = array[0][x1-1][y1-1] ;
    array[0][x1-1][y1-1] = array[1][x2-1][y2-1];
    array[1][x2-1][y2-1] = temp;
}

void ubahmatriks(int array[2][3][3])
{
    int x1,y1;
    int x2,y2;
    cout << "masukan index yang mau di tukar di array 1 baris dan kolom ke :";
    cin >> x1;
    cin >> y1;
    cout << "masukan index yang mau di tukar di array 2 baris dan kolom ke :";
    cin >> x2;
    cin >> y2;
    ubah(x1,y1,x2,y2,array);
}

int main ()
{
    int data[2][3][3] =
    {
        {
            {16,69,88},
            {20,10,11},
            {17,29,67}
        },
        {
            {54,67,89},
            {78,65,23},
            {45,12,13}
        }
    };
    cout << "sebelum \n";
    tampilkan(data);
    ubahmatriks(data);
    cout << "sesudah \n";
    tampilkan(data);
    return 0;
}
```
### Output Unguided 3 :
<img width="947" height="552" alt="Screenshot 2026-11-18 202857" src="https://github.com/user-attachments/assets/40098f48-8e56-4f6d-aa65-6f32c54d405b" />

##### Output 1

#### penjelasan unguided 3 :                                                                Program ini menggunakan array 3 dimensi untuk merepresentasikan dua matriks 3x3 yang disimpan dalam satu variabel `data`, lalu prosedur `tampilkan()` digunakan untuk menampilkan isi kedua matriks tersebut, sedangkan fungsi `ubah()` dan `ubahmatriks()` bekerja untuk menukar elemen pada posisi tertentu antara matriks pertama dan matriks kedua sesuai input yang diberikan pengguna, sehingga program dapat menunjukkan bagaimana mekanisme pengolahan data dengan array dan pointer diterapkan dalam praktik.


## Kesimpulan                                                                           Berdasarkan ketiga program yang telah dibuat pada Modul 3, dapat disimpulkan bahwa Abstract Data Type (ADT) sangat penting dalam pemrograman karena mampu menggabungkan data dan operasi yang berhubungan ke dalam satu unit yang lebih terstruktur. Pada program mahasiswa, `struct` digunakan untuk menyimpan data mahasiswa dan menghitung rata-rata dengan cara yang rapi; pada program pelajaran, pembuatan ADT dalam file terpisah menunjukkan prinsip modularitas yang memudahkan pengelolaan kode; sedangkan pada program matriks, penggunaan array dan pointer memperlihatkan bagaimana data dapat diproses dan dipindahkan secara efisien. Secara keseluruhan, modul ini membuktikan bahwa penggunaan `struct`, array, fungsi, dan pointer dapat meningkatkan keteraturan, kemudahan pemeliharaan, serta efisiensi program dalam mengelola data.



## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
