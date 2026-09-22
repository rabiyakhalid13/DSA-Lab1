#include <iostream>
using namespace std;

// Function 1: Swapping using normal pointers (addresses)
void swapByPointer(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function 2: Swapping using pointer-to-pointer variables
void swapByDoublePointer(int **ppa, int **ppb) {
    int temp = **ppa;
    **ppa = **ppb;
    **ppb = temp;
}

int main() {
    int a = 5, b = 10;
    int *pa = &a;
    int *pb = &b;
    
    int **ppa = &pa;
    int **ppb = &pb; 
    
    // Testing pointer swap
    swapByPointer(&a, &b);
    cout << "After pointer swap: a = " << a << ", b = " << b << endl;
    
    // Testing double pointer swap
    swapByDoublePointer(&pa, &pb);
    cout << "After double pointer swap: a = " << a << ", b = " << b << endl;
    
    return 0;
}