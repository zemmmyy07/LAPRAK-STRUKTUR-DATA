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

