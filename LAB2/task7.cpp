#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter n (1-10): ";
    cin >> n;
    
    int *marks = new int[n];
    cout << "Enter " << n << " marks: ";
    for (int i = 0; i < n; i++) {
        cin >> *(marks + i);
    }
    
    int newMark;
    cout << "Enter the new mark to append: ";
    cin >> newMark;
    
    // 1. Allocate a second block of n + 1 integers
    int *newMarks = new int[n + 1];
    
    // 2. Copy original n values using pointer notation
    for (int i = 0; i < n; i++) {
        *(newMarks + i) = *(marks + i);
    }
    
    // Store new mark in final position
    *(newMarks + n) = newMark;
    
    // 3. Release old block and update pointer/size
    delete[] marks;
    marks = newMarks;
    n++;
    
    // Display updated array
    cout << "Updated marks: ";
    for (int i = 0; i < n; i++) {
        cout << *(marks + i) << " ";
    }
    cout << endl;
    
    // Final cleanup
    delete[] marks;
    marks = nullptr;
    
    return 0;
}