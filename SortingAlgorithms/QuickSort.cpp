#include "checker.h"

template<typename T>
void quickSort(std::vector<T> &v, int begin, int end){
    if (begin >= end){
        return;
    }
    T pivot = v[(begin + end) / 2];
    int left = begin;
    int right = end;
    while (left <= right){
        while (v[left] < pivot){
            left++;
        }
        while (v[right] > pivot){
            right--;
        }
        if (left <= right){
            T tmp = v[left];
            v[left] = v[right];
            v[right] = tmp;
            left++;
            right--;
        }
    }
    quickSort(v, begin, right);
    quickSort(v, left, end);
}

// QuickSort with Additional memory
template<typename T>
void quickSortMem(std::vector<T> &v){
    if (v.size() <= 1){
        return;
    }
    std::vector<T> L;
    std::vector<T> M;
    std::vector<T> R;
    T pivot = v[v.size() / 2];
    for (size_t i = 0; i < v.size(); ++i){
        if (v[i] < pivot){
            L.push_back(v[i]);
        }
        else if (v[i] == pivot){
            M.push_back(v[i]);
        }
        else{
            R.push_back(v[i]);
        }
    }
    quickSortMem(L);
    quickSortMem(R);
    size_t tmpCounter = 0;
    for (size_t i = 0; i < L.size(); ++i){
        v[tmpCounter++] = L[i];
    }
    for (size_t i = 0; i < M.size(); ++i){
        v[tmpCounter++] = M[i];
    }
    for (size_t i = 0; i < R.size(); ++i){
        v[tmpCounter++] = R[i];
    }
}

int main() {
    std::vector<int> v;
    v = initializer<int>("data.txt");
    std::cout << "Quick sort without additional memory" << std::endl;
    quickSort<int>(v, 0, v.size() - 1);
    checker<int>(v);
    std::cout << "Quick sort with additional memory" << std::endl;
    v = initializer<int>("data.txt");
    quickSortMem(v);
    checker<int>(v);
    return 0;
}