#include "queue-array.h"
#include <iostream>

int main(){
    queue Q;

    CreateQueue(Q);
    enQueue(Q, "Dimas");
    enQueue(Q, "Arvin");
    enQueue(Q, "Rizal");
    enQueue(Q, "Hafizh");
    enQueue(Q, "Fathur");
    enQueue(Q, "Daffa");
    std::cout << std::endl;

    std::cout << "--- Isi Queue Setelah enQueue ---" << std::endl;
    viewQueue(Q);
    std::cout << std::endl;

    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    // deQueue(Q);
    // deQueue(Q);
    std::cout << std::endl;

    std::cout << "--- Isi Queue Setelah deQueue ---" << std::endl;
    viewQueue(Q);

    return 0;
}