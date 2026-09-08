#include <iostream>
#include <vector>
#include "utilities.h"
using namespace std;

void printVector(const vector<int>& vec) {
    cout << "[ ";
    for (int val : vec) cout << val << " ";
    cout << "]";
}

int main() {
    // Test Case 1: Multiple occurrences
    vector<int> arr1 = {10, 20, 30, 20, 40, 20};
    vector<int> res1 = findAllIndices(arr1, 20);
    cout << "Test 1 (Multiple Occurrences): Expected [ 1 3 5 ], Got: ";
    printVector(res1);
    cout << endl;

    // Test Case 2: Key not present
    vector<int> arr2 = {1, 2, 3, 4};
    vector<int> res2 = findAllIndices(arr2, 99);
    cout << "Test 2 (Key Not Present): Expected [ ], Got: ";
    printVector(res2);
    cout << endl;

    // Test Case 3: Empty array
    vector<int> arr3 = {};
    vector<int> res3 = findAllIndices(arr3, 5);
    cout << "Test 3 (Empty Array): Expected [ ], Got: ";
    printVector(res3);
    cout << endl;

    // Task 4 Tests
    cout << "Task 4: Pattern Search" << endl;
    cout << "Beginning: " << (naivePatternSearch("hello world", "hello") == 0 ? "PASS" : "FAIL") << endl;
    cout << "End: " << (naivePatternSearch("hello world", "world") == 6 ? "PASS" : "FAIL") << endl;
    cout << "Not Present: " << (naivePatternSearch("hello world", "cpp") == -1 ? "PASS" : "FAIL") << endl;
    cout << "Empty Pattern: " << (naivePatternSearch("hello world", "") == 0 ? "PASS" : "FAIL") << endl;    

    // Task 5 Tests
    cout << "\nTask 5: Pascal's Triangle" << endl;
    auto t0 = generatePascalsTriangle(0);
    cout << "n=0 size: " << (t0.empty() ? "PASS" : "FAIL") << endl;

    auto t1 = generatePascalsTriangle(1);
    cout << "n=1 size: " << (t1.size() == 1 ? "PASS" : "FAIL") << endl;

    auto t5 = generatePascalsTriangle(5);
    vector<int> expectedRow5 = {1, 4, 6, 4, 1};
    cout << "n=5 Row 5 verification: " << (t5[4] == expectedRow5 ? "PASS" : "FAIL") << endl;    

    
    // Task 6 Tests
    cout << "\nTask 6: Mode" << endl;
    cout << "Unique Mode: " << (findMode({1, 2, 2, 3}) == vector<int>{2} ? "PASS" : "FAIL") << endl;
    cout << "Multiple Modes: " << (findMode({1, 1, 2, 2}) == vector<int>{1, 2} ? "PASS" : "FAIL") << endl;
    cout << "Empty Array: " << (findMode({}).empty() ? "PASS" : "FAIL") << endl;

    // Task 7 Tests
    cout << "\nTask 7: Strassen Matrix Multiplication" << endl;
    Matrix A2 = {{1, 2}, {3, 4}};
    Matrix B2 = {{5, 6}, {7, 8}};
    cout << "2x2 Strassen Match: " << (strassenMultiply(A2, B2) == standardMultiply(A2, B2) ? "PASS" : "FAIL") << endl;

    Matrix A4 = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    Matrix B4 = {{16, 15, 14, 13}, {12, 11, 10, 9}, {8, 7, 6, 5}, {4, 3, 2, 1}};
    cout << "4x4 Strassen Match: " << (strassenMultiply(A4, B4) == standardMultiply(A4, B4) ? "PASS" : "FAIL") << endl;
    return 0;
}


