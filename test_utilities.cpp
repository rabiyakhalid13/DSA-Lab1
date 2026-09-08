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

    return 0;
}
