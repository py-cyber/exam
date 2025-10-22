#include "HybridQuickSort.h"
#include <random>
#include <algorithm>
#include <pthread.h>

class RandomGenerator::Impl {
public:
    std::mt19937 gen;
    
    Impl() : gen(std::random_device{}()) {}
};

RandomGenerator::RandomGenerator() : impl(new Impl()) {}
RandomGenerator::~RandomGenerator() { delete impl; }

int RandomGenerator::random_int(int min, int max) {
    std::uniform_int_distribution<int> dist(min, max);
    return dist(impl->gen);
}

void RandomGenerator::fill_vector(std::vector<int>& vec, int size) {
    vec.resize(size);
    for (int i = 0; i < size; i++) {
        vec[i] = random_int();
    }
}

struct SortData {
    std::vector<int>* arr;
    int low;
    int high;
};

class HybridQuickSortImpl {
private:
    static const int INSERTION_THRESHOLD = 10;
    
    static int partition(std::vector<int>& arr, int low, int high) {
        int mid = low + (high - low) / 2;
        int pivot = arr[mid];
        
        int i = low;
        int j = high;
        
        while (i <= j) {
            while (arr[i] < pivot) i++;
            while (arr[j] > pivot) j--;
            if (i <= j) {
                std::swap(arr[i], arr[j]);
                i++;
                j--;
            }
        }
        return i;
    }
    
    static void insertionSort(std::vector<int>& arr, int low, int high) {
        for (int i = low + 1; i <= high; i++) {
            int key = arr[i];
            int j = i - 1;
            while (j >= low && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }
    
    static void* quickSortThread(void* arg) {
        SortData* data = static_cast<SortData*>(arg);
        quickSort(*data->arr, data->low, data->high);
        delete data;
        return nullptr;
    }
    
    static void quickSort(std::vector<int>& arr, int low, int high) {
        if (high - low < INSERTION_THRESHOLD) {
            insertionSort(arr, low, high);
            return;
        }
        
        if (low < high) {
            int pivot = partition(arr, low, high);
            
            if (high - low > 1000000) {
                pthread_t thread;
                pthread_attr_t attr;
                size_t stack_size = 64 * 1024 * 1024;
                
                pthread_attr_init(&attr);
                pthread_attr_setstacksize(&attr, stack_size);
                
                SortData* leftData = new SortData{&arr, low, pivot - 1};
                if (pthread_create(&thread, &attr, quickSortThread, leftData) == 0) {
                    quickSort(arr, pivot, high);
                    pthread_join(thread, nullptr);
                } else {
                    quickSort(arr, low, pivot - 1);
                    quickSort(arr, pivot, high);
                }
                pthread_attr_destroy(&attr);
            } else {
                quickSort(arr, low, pivot - 1);
                quickSort(arr, pivot, high);
            }
        }
    }

public:
    static void sort(std::vector<int>& arr) {
        if (arr.size() <= 1) return;
        quickSort(arr, 0, arr.size() - 1);
    }
};

void HybridQuickSort::sort(std::vector<int>& arr) {
    HybridQuickSortImpl::sort(arr);
}

bool HybridQuickSort::isSorted(const std::vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); i++) {
        if (arr[i] < arr[i - 1]) return false;
    }
    return true;
}
