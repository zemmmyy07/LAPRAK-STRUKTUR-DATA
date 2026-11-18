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