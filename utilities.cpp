#include "utilities.h"

int add(int a, int b) {
    return a + b;
}
int i;
std::vector<int> findAllIndices(const std::vector<int>& arr, int key) {
    std::vector<int> indices;
    for (i = 0; i < arr.size(); ++i) {
        if (arr[i] == key) {
            indices.push_back(i);
        }
    }
    return indices;
}