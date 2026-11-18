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