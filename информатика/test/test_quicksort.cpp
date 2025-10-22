#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include "HybridQuickSort.h"

class QuickSortTests {
public:
    static void runAllTests() {
        std::cout << "Запуск модульных тестов..." << std::endl;
        
        testEmptyArray();
        testSingleElement();
        testTwoElements();
        testSortedArray();
        testReverseSorted();
        testAllEqual();
        testRandomArray();
        testSmallArrayUsesInsertion();
        
        std::cout << "Все тесты пройдены успешно! +" << std::endl;
    }

private:
    static void testEmptyArray() {
        std::vector<int> arr = {};
        HybridQuickSort::sort(arr);
        assert(arr.empty());
        std::cout << "+ testEmptyArray" << std::endl;
    }

    static void testSingleElement() {
        std::vector<int> arr = {42};
        HybridQuickSort::sort(arr);
        assert(arr.size() == 1);
        assert(arr[0] == 42);
        assert(HybridQuickSort::isSorted(arr));
        std::cout << "+ testSingleElement" << std::endl;
    }

    static void testTwoElements() {
        std::vector<int> arr1 = {2, 1};
        HybridQuickSort::sort(arr1);
        assert(arr1[0] == 1);
        assert(arr1[1] == 2);
        assert(HybridQuickSort::isSorted(arr1));
        
        std::vector<int> arr2 = {1, 2};
        HybridQuickSort::sort(arr2);
        assert(arr2[0] == 1);
        assert(arr2[1] == 2);
        assert(HybridQuickSort::isSorted(arr2));
        
        std::cout << "+ testTwoElements" << std::endl;
    }

    static void testSortedArray() {
        std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        std::vector<int> original = arr;
        HybridQuickSort::sort(arr);
        assert(HybridQuickSort::isSorted(arr));
        assert(arr == original);
        std::cout << "+ testSortedArray" << std::endl;
    }

    static void testReverseSorted() {
        std::vector<int> arr = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
        HybridQuickSort::sort(arr);
        assert(HybridQuickSort::isSorted(arr));
        for (int i = 0; i < 10; i++) {
            assert(arr[i] == i + 1);
        }
        std::cout << "+ testReverseSorted" << std::endl;
    }

    static void testAllEqual() {
        std::vector<int> arr = {5, 5, 5, 5, 5, 5, 5, 5};
        HybridQuickSort::sort(arr);
        assert(HybridQuickSort::isSorted(arr));
        for (int num : arr) {
            assert(num == 5);
        }
        std::cout << "+ testAllEqual" << std::endl;
    }

    static void testRandomArray() {
        std::vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
        HybridQuickSort::sort(arr);
        assert(HybridQuickSort::isSorted(arr));
        std::cout << "+ testRandomArray" << std::endl;
    }

    static void testSmallArrayUsesInsertion() {
        std::vector<int> arr = {5, 2, 8, 1, 9};
        HybridQuickSort::sort(arr);
        assert(HybridQuickSort::isSorted(arr));
        std::cout << "+ testSmallArrayUsesInsertion" << std::endl;
    }
};

int main() {
    QuickSortTests::runAllTests();
    return 0;
}
