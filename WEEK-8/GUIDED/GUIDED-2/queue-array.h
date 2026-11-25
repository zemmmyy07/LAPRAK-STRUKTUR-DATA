#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>

const int MAKSIMAL = 5;

struct queue {
    std::string nama[MAKSIMAL];
    int head;
    int tail;
};

bool isFull(queue Q);
bool isEmpty(queue Q);
void CreateQueue(queue &Q);
void enQueue(queue &Q, std::string nama);
void deQueue(queue &Q);
void viewQueue(queue Q);

#endif