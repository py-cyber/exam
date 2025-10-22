#ifndef HYBRIDQUICKSORT_H
#define HYBRIDQUICKSORT_H

#include <vector>

class RandomGenerator {
private:
    class Impl;
    Impl* impl;
    
public:
    RandomGenerator();
    ~RandomGenerator();
    int random_int(int min = 0, int max = 1000000);
    void fill_vector(std::vector<int>& vec, int size);
};

class HybridQuickSort {
public:
    static void sort(std::vector<int>& arr);
    static bool isSorted(const std::vector<int>& arr);
};

#endif
