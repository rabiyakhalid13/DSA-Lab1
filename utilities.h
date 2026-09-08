#ifndef UTILITIES_H
#define UTILITIES_H

#include <vector>

int add(int a, int b);
std::vector<int> findAllIndices(const std::vector<int>& arr, int key);

#include <string>
int naivePatternSearch(const std::string& text, const std::string& pattern);

#include <vector>
std::vector<std::vector<int>> generatePascalsTriangle(int n);

#include <vector>

std::vector<int> findMode(const std::vector<int>& arr);

typedef std::vector<std::vector<int>> Matrix;
Matrix standardMultiply(const Matrix& A, const Matrix& B);
Matrix strassenMultiply(const Matrix& A, const Matrix& B);

#endif