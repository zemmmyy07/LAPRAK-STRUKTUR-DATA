# <h1 align="center">Laporan Praktikum Modul 7 - STACK</h1>
<p align="center">Azzamy Gusalim Herfino - 109082500091</p>

## Dasar Teori
Stack adalah struktur data linear yang bekerja berdasarkan prinsip LIFO (Last In First Out), yaitu data yang terakhir masuk akan dikeluarkan terlebih dahulu[1]. Contohnya seperti tumpukan buku, buku yang terakhir ditaruh di atas akan diambil lebih dulu. Dalam pemrograman, stack sering dipakai untuk menyimpan data sementara dan memproses urutan balik[2].

## Guided 

### 1. stack.h

```C++
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <iostream>
using namespace std;

struct infotype {
    char nim[20];
    char nama[20];
};

struct Stack {
    infotype info[10];
    int Top;
};

int isEmpty(Stack S);

void createStack(Stack &S);

void push(Stack &S, infotype X);

void pop(Stack &S, infotype &X);

void viewStack(Stack S);

#endif 

```
##### penjelasan singkat guided 1
Stack untuk menyimpan data mahasiswa berisi NIM dan nama. Array info[10] menyimpan data, sedangkan Top menunjukkan posisi elemen paling atas sehingga operasi push dan pop bisa dilakukan sesuai prinsip LIFO.

### 2. stack.cpp

```C++
#include "stack.h"

int isEmpty(Stack S) {
    if (S.Top == 0) {
        return 0;
    } else {
        return 1;
    }
}
void createStack(Stack &S) {
    S.Top = 0;
}
void push(Stack &S, infotype X) {
    if (S.Top < 10) {
        S.Top = S.Top + 1;
        S.info[S.Top - 1] = X;
    } else {
        cout << "Stack penuh, data tidak bisa ditambahkan" << endl;
    }
}
void pop(Stack &S, infotype &X) {
    if (isEmpty(S) != 0) {
        X = S.info[S.Top - 1];
        S.Top = S.Top -1;
    } else {
        cout << "Stack kosong, tidak ada data yang bisa diambil" << endl;
    }
}
void viewStack(Stack S) {
    if (isEmpty(S) == 0) {
        cout << "Stack Kosong" << endl; 
    } else {
        cout << "Isi stack (dari TOP):" << endl;
        for (int i = S.Top; i >= 1; i--) {
            cout << i << ". " << S.info[i - 1].nim << " - "
                 << S.info[i - 1].nama << endl;
        }
    }
}
```
#### penjelasan singkat guided 2
Fungsi createStack, push, pop, dan viewStack diimplementasikan agar stack dapat digunakan secara nyata. createStack menginisialisasi Top, push menambahkan data ke atas, pop menghapus elemen paling atas, dan viewStack menampilkan isi stack sesuai urutan LIFO.

### 3. main.cpp

```C++
#include <iostream>
#include <cstring>
#include "stack.h"
using namespace std;

int main() {
    Stack S;
    infotype data, hasil;

    createStack(S);
    cout << "Stack baru dibuat, Top = " << S.Top << endl;
    viewStack(S);

    cout << endl << "--- Push 3 data ---" << endl;
    strcpy(data.nim, "103112400001");
    strcpy(data.nama, "Andi");
    push(S, data);

    strcpy(data.nim, "103112400002");
    strcpy(data.nama, "Budi");
    push(S, data);

    strcpy(data.nim, "103112400003");
    strcpy(data.nama, "Citra");
    push(S, data);
    viewStack(S);

    cout << endl << "--- Pop 1 data ---" << endl;
    pop(S, hasil);
    cout << "Data yang diambil: " << hasil.nim << " - " << hasil.nama << endl;
    viewStack(S);

    cout << endl << "--- Pop sampai kosong ---" << endl;
    pop(S, hasil);
    pop(S, hasil);
    pop(S, hasil);
    viewStack(S);

    return 0;
}
```
#### penjelasan singkat guided 3
Stack untuk menyimpan, menampilkan, dan menghapus data mahasiswa berdasarkan prinsip LIFO. Program ini juga membuktikan bahwa operasi stack dapat dibuat lebih rapi dan mudah dipahami dengan memisahkan fungsinya dalam modul yang berbeda.

## Unguided 

### 1. Buatlah ADT Stack menggunakan ARRAY sebagai berikut di dalam file “stack.h”. Buatlah implementasi ADT Stack menggunakan Array pada file “stack.cpp” dan “main.cpp”

### stack.h
```C++
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <iostream>

using namespace std;

typedef int infotype;
struct Stack {
    infotype info[20];
    int top;
};

void createStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

#endif 
```
### stack.cpp
```C++
#include "stack.h"

void createStack(Stack &S) {
    S.top = -1;
}

bool isEmpty(Stack S) {
    return S.top == -1;
}

bool isFull(Stack S) {
    return S.top == 19;
}

void push(Stack &S, infotype x) {
    if (!isFull(S)) {
        S.top++;
        S.info[S.top] = x;
    }
}

infotype pop(Stack &S) {
    infotype x = -1;
    if (!isEmpty(S)) {
        x = S.info[S.top];
        S.top--;
    }
    return x;
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    for (int i = S.top; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    if (!isEmpty(S)) {
        Stack temp1, temp2;
        createStack(temp1);
        createStack(temp2);
        
        while (!isEmpty(S)) {
            push(temp1, pop(S));
        }
        
        while (!isEmpty(temp1)) {
            push(temp2, pop(temp1));
        }
        
        while (!isEmpty(temp2)) {
            push(S, pop(temp2));
        }
    }
}
```
### main.cpp
```C++
#include "stack.h"

int main() {
    cout << "Hello world!" << endl;
    Stack S;
    createStack(S);
    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);
    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);
    return 0;
}
```
### Output Unguided 1 :
<img width="1038" height="207" alt="Screenshot 2026-11-18 190204" src="https://github.com/user-attachments/assets/a6abe506-bc6c-407a-b3d3-bd69c7fbafff" />

##### Output 



#### penjelasan unguided 1
Stack dibuat menggunakan array dan diisi dengan angka 3, 4, 8, 2, 3, dan 9. Proses push dan pop dilakukan sesuai prinsip LIFO, lalu fungsi balikStack digunakan untuk membalik urutan elemen sehingga hasil akhirnya menjadi terbalik dari urutan awal.

### 2. Tambahkan prosedur pushAscending( in/out S : Stack, in x : integer)

### stack.h
```C++
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <iostream>

using namespace std;

typedef int infotype;
struct Stack {
    infotype info[20];
    int top;
};

void createStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
void pushAscending(Stack &S, infotype x);

#endif 
```
### stack.cpp
```C++
#include "stack.h"

void createStack(Stack &S) {
    S.top = -1;
}

bool isEmpty(Stack S) {
    return S.top == -1;
}

bool isFull(Stack S) {
    return S.top == 19;
}

void push(Stack &S, infotype x) {
    if (!isFull(S)) {
        S.top++;
        S.info[S.top] = x;
    }
}

infotype pop(Stack &S) {
    infotype x = -1;
    if (!isEmpty(S)) {
        x = S.info[S.top];
        S.top--;
    }
    return x;
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    for (int i = S.top; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    if (!isEmpty(S)) {
        Stack temp1, temp2;
        createStack(temp1);
        createStack(temp2);
        
        while (!isEmpty(S)) {
            push(temp1, pop(S));
        }
        while (!isEmpty(temp1)) {
            push(temp2, pop(temp1));
        }
        while (!isEmpty(temp2)) {
            push(S, pop(temp2));
        }
    }
}

void pushAscending(Stack &S, infotype x) {
    if (isFull(S)) {
        return;
    }
    
    Stack temp;
    createStack(temp);
    
    while (!isEmpty(S) && S.info[S.top] < x) {
        push(temp, pop(S));
    }
    
    push(S, x);
    
    while (!isEmpty(temp)) {
        push(S, pop(temp));
    }
}
```
### main.cpp
```C++
#include "stack.h"

int main() {
    cout << "Hello world!" << endl;
    Stack S;
    createStack(S);
    pushAscending(S, 3);
    pushAscending(S, 4);
    pushAscending(S, 8);
    pushAscending(S, 2);
    pushAscending(S, 3);
    pushAscending(S, 9);
    
    cout << "balik stack" << endl;
    balikStack(S);
    
    printInfo(S);
    
    return 0;
}
```
### Output Unguided 2 :
<img width="1010" height="175" alt="Screenshot 2026-11-18 190315" src="https://github.com/user-attachments/assets/50e491ae-dfd0-4837-b2d2-953c92c8fd2d" />

##### Output 

#### penjelasan unguided 2
Stack digunakan untuk memasukkan data dengan prosedur pushAscending agar urutan data tetap naik. Setelah semua data masuk, fungsi balikStack dipanggil untuk membalik isi stack sehingga program dapat menampilkan urutan yang berbeda dari susunan awal.

### 3. Tambahkan prosedur getInputStream( in/out S : Stack ). Prosedur akan terus membaca dan menerima input user dan memasukkan setiap input ke dalam stack hingga user menekan tombol enter. Contoh: gunakan cin.get() untuk mendapatkan inputan user.

### stack.h
```C++
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <iostream>

using namespace std;

typedef int infotype;
struct Stack {
    infotype info[20];
    int top;
};

void createStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
void pushAscending(Stack &S, infotype x);
void getInputStream(Stack &S);

#endif 
```
### stack.cpp
```C++
#include "stack.h"

void createStack(Stack &S) {
    S.top = -1;
}

bool isEmpty(Stack S) {
    return S.top == -1;
}

bool isFull(Stack S) {
    return S.top == 19;
}

void push(Stack &S, infotype x) {
    if (!isFull(S)) {
        S.top++;
        S.info[S.top] = x;
    }
}

infotype pop(Stack &S) {
    infotype x = -1;
    if (!isEmpty(S)) {
        x = S.info[S.top];
        S.top--;
    }
    return x;
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    for (int i = S.top; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    if (!isEmpty(S)) {
        Stack temp1, temp2;
        createStack(temp1);
        createStack(temp2);
        
        while (!isEmpty(S)) {
            push(temp1, pop(S));
        }
        while (!isEmpty(temp1)) {
            push(temp2, pop(temp1));
        }
        while (!isEmpty(temp2)) {
            push(S, pop(temp2));
        }
    }
}

void pushAscending(Stack &S, infotype x) {
    if (isFull(S)) {
        return;
    }
    Stack temp;
    createStack(temp);
    while (!isEmpty(S) && S.info[S.top] < x) {
        push(temp, pop(S));
    }
    push(S, x);
    while (!isEmpty(temp)) {
        push(S, pop(temp));
    }
}

void getInputStream(Stack &S) {
    char c;
    while (cin.get(c) && c != '\n') {
        if (c >= '0' && c <= '9') {
            infotype x = c - '0'; 
            push(S, x);
        }
    }
}
```
### main.cpp
```C++
#include "stack.h"

int main() {
    cout << "Hello world!" << endl;
    
    cin.ignore(); 
    
    Stack S;
    createStack(S);
    getInputStream(S);
    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);
    return 0;
}
```
### Output Unguided 3 :
<img width="1022" height="222" alt="Screenshot 2026-11-18 190748" src="https://github.com/user-attachments/assets/f87b8b38-eb65-4e24-a061-28f42ea26fa9" />

##### Output 

#### penjelasan unguided 3
Program membaca input angka dari user dan menyimpannya ke stack sampai tombol enter ditekan. Data tersebut kemudian ditampilkan dan dibalik dengan fungsi balikStack, sehingga terlihat bahwa stack mengikuti prinsip LIFO dalam proses penyimpanan dan pengolahan data.

## Kesimpulan
Stack adalah struktur data yang bekerja berdasarkan prinsip LIFO, yaitu data yang terakhir masuk akan keluar terlebih dahulu. Praktikum ini membuktikan bahwa operasi push, pop, dan view pada stack dapat diimplementasikan secara sederhana menggunakan array, serta dapat dimodifikasi untuk kebutuhan tertentu seperti membalik urutan data atau menyusun data secara terurut.

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
