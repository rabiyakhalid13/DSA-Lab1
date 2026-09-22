#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    cout<<"Enter number of students (rows)";
    cin >> rows;
    cout<<"Enter number of subjects (cols)";
    cin >> cols;
    // Validate rows and cols
    if (rows <= 0 || cols <= 0) {
        cout << "Invalid rows or columns!" << endl;
        return 1;
    }
    //Allocate row pointers
    int **marks=new int*[rows];
    for(int i=0;i<rows;i++){
        marks[i]=new int[cols];
    }

    // Read marks
    cout << "Enter marks (0 to 100) row by row:\n";
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            cin >> *(*(marks + r) + c);
        }
    }
    // Display matrix and calculate totals
    int bestTotal = -1;
    int topStudent = 1;
    
    cout << "\nResults Summary:\n";
    for (int r = 0; r < rows; r++) {
        int currentTotal = 0;
        cout << "Student " << (r + 1) << " marks: ";
        for (int c = 0; c < cols; c++) {
            int val = *(*(marks + r) + c);
            cout << val << " ";
            currentTotal += val;
        }
        cout << "| Total: " << currentTotal << endl;
        
        // Track highest total (first student wins ties)
        if (currentTotal > bestTotal) {
            bestTotal = currentTotal;
            topStudent = r + 1;
        }
    }
    
    cout << "\nTop Student: Student " << topStudent << " with total " << bestTotal << endl;
    
    // Deallocate memory safely
    for (int r = 0; r < rows; r++) {
        delete[] marks[r];
    }
    delete[] marks;
    marks = nullptr;
    
    return 0;
}