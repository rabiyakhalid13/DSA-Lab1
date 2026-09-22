#include <iostream>
using namespace std;

int main() {
    int n = 3;
    int *values = new int[n];
    
    cout << "Enter 3 integers: ";
    for (int i = 0; i < n; i++) {
        cin >> *(values + i);
    }
    
    cout << "You entered: ";
    for (int i = 0; i < n; i++) {
        cout << *(values + i) << " ";
    }
    cout << endl;
    
    delete[] values;
    values = nullptr; // Reset pointer to avoid dangling pointer
    
    return 0;
}