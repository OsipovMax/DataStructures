#include "checker.h"

template<typename T>
void merge(std::vector<T> &v, int beg, int mid, int end){
    std::vector<T> tempBuf;
    int lBegin = beg;
    int rBegin = mid + 1;

    while (lBegin <= mid && rBegin <= end){
        if (v[lBegin] < v[rBegin]){
            tempBuf.push_back(v[lBegin++]);
        }
        else {
            tempBuf.push_back(v[rBegin++]);
        }
    }
    
    if (lBegin <= mid){
        for ( ; lBegin <= mid; ){
            tempBuf.push_back(v[lBegin++]);
        }
    }
    else {
        for ( ; rBegin <= end; ){
            tempBuf.push_back(v[rBegin++]);
        }
    }
    
    for (int i = 0; i < tempBuf.size(); ++i){
        v[i + beg] = tempBuf[i];
    }
}

template<typename T>
void mergeSort(std::vector<T> &v, int beg, int end){
    if (beg >= end){
        return;
    }
    
    int mid = (beg + end) / 2;

    mergeSort(v, beg, mid);
    mergeSort(v, mid + 1, end);
    merge(v, beg, mid, end);
}

int main() {
    std::vector<int> v;
    v = initializer<int>("data.txt");
    mergeSort<int>(v, 0, v.size() - 1);
    checker<int>(v);
    return 0;
}