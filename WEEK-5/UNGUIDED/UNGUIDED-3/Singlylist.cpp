#include "Singlylist.h"

void createList(List &L) {
    first(L) = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    if (P != Nil) {
        info(P) = x;
        next(P) = Nil;
    }
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void insertFirst(List &L, address P) {
    if (first(L) == Nil) {
        first(L) = P;
    } else {
        next(P) = first(L);
        first(L) = P;
    }
}

void printInfo(List L) {
    address P = first(L);
    while (P != Nil) {
        std::cout << info(P) << " ";
        P = next(P);
    }
    std::cout << std::endl;
}

int sumInfo(List L) {
    int total = 0;
    address P = first(L);
    while (P != Nil) {
        total = total + info(P);
        P = next(P);
    }
    return total;
}