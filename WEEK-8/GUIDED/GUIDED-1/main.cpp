#include <iostream>
#include "queue.h"

int main() {
    queue Q;
    address P; 

    CreateQueue(Q);
    std::cout << "isEmpty : " << isEmpty(Q) << std::endl;
    printInfo(Q);

    insert(Q, alokasi(5));
    insert(Q, alokasi(2));
    insert(Q, alokasi(7));
    std::cout << "Setelah insert 5, 2, 7" << std::endl;
    printInfo(Q);
    std::cout << "nbList  : " << nbList(Q) << std::endl;

    P = findElm(Q, 2);
    if (P != Nil) {
        std::cout << "findElm(2) ketemu, info = " << P->info << std::endl;
        std::cout << "fFindElm : " << fFindElm(Q, P) << std::endl;
    }
    if (findElm(Q, 9) == Nil) {
        std::cout << "findElm(9) tidak ketemu" << std::endl;
    }

    deleteQueue(Q, P);
    std::cout << "Setelah delete, elemen yang keluar = " << P->info << std::endl;
    dealokasi(P);
    printInfo(Q);

    delAll(Q);
    std::cout << "Setelah delAll" << std::endl;
    printInfo(Q);
    std::cout << "isEmpty : " << isEmpty(Q) << std::endl;

    return 0;
}