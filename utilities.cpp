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

int naivePatternSearch(const std::string& text, const std::string& pattern) {
    if (pattern.empty()) return 0;
    int n = text.length();
    int m = pattern.length();

    for (int i = 0; i <= n - m; ++i) {
        int j = 0;
        while (j < m && text[i + j] == pattern[j]) {
            j++;
        }
        if (j == m) return i;
    }
    return -1;
}

std::vector<std::vector<int>> generatePascalsTriangle(int n) {
    std::vector<std::vector<int>> triangle;
    if (n <= 0) return triangle;

    for (int i = 0; i < n; ++i) {
        std::vector<int> row(i + 1, 1);
        for (int j = 1; j < i; ++j) {
            row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
        triangle.push_back(row);
    }
    return triangle;
}