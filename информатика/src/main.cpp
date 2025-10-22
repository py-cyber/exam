#include <iostream>
#include <vector>
#include <chrono>
#include "HybridQuickSort.h"

void demonstrate() {
    std::cout << "=== QuickSort ===" << std::endl;
    
    RandomGenerator rnd;
    
    std::vector<int> arr;
    rnd.fill_vector(arr, 1000000);
    
    std::cout << "Сортировка массива из " << arr.size() << " элементов..." << std::endl;
    
    auto start = std::chrono::high_resolution_clock::now();
    HybridQuickSort::sort(arr);
    auto end = std::chrono::high_resolution_clock::now();
    
    std::cout << "Отсортирован: " << (HybridQuickSort::isSorted(arr) ? "Да" : "Нет") << std::endl;
    std::cout << "Время: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;
}

int main() {
    demonstrate();
    return 0;
}
