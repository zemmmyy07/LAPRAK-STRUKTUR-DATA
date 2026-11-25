#include "queue-array.h"
#include <iostream>

bool isEmpty(queue Q){
    if(Q.head == -1 && Q.tail == -1){
        return true;
    } else {
        return false;
    }
}

bool isFull(queue Q){
    if((Q.tail + 1) % MAKSIMAL == Q.head){
        return true;
    } else {
        return false;
    }
}

void CreateQueue(queue &Q){ //terbentuk queue dengan head = -1 dan tail = -1 
    Q.head = -1;
    Q.tail = -1;
}
void enQueue(queue &Q, std::string nama){
    if(isFull(Q) == true){
        std::cout << "Queue sudah penuh!" << std::endl;
    } else {
        if(isEmpty(Q) == true){
            Q.head = Q.tail = 0;
        } else {
            Q.tail = (Q.tail + 1) % MAKSIMAL; //bergerak melingkar
        }
        Q.nama[Q.tail] = nama;
        std::cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << std::endl;
    }
}
void deQueue(queue &Q){
    if(isEmpty(Q) == true){
        std::cout << "Queue kosong!" << std::endl;
    } else {
        std::cout << "Mengahapus data " << Q.nama[Q.head] << "..." << std::endl;
        if(Q.head == Q.tail){ //kalo elemennya tinggal 1, langsungkan saja head & tail nya reset ke -1
            Q.head = -1;
            Q.tail = -1;
        } else {
            Q.head = (Q.head + 1) % MAKSIMAL; //bergerak melingkar
        }
    }
}

void viewQueue(queue Q){
    if(isEmpty(Q) == true){
        std::cout << "Queue kosong!" << std::endl;
    } else {
        int i = Q.head;
        int count = 1;
        while(true){
            std::cout << count << ". " << Q.nama[i] << std::endl;
            if(i == Q.tail){
                break;
            }
            i = (i + 1) % MAKSIMAL;
            count++;
        }   
    }
}