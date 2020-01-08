#include "checker.h"

template<typename T>
void insertionSort(std::vector<T> &v){
    int curInd = 0;
    for (int i = 1; i < v.size(); ++i){
        curInd = i;
        for (int j = i - 1; j >= 0 && v[j] > v[curInd]; --j){
            std::swap(v[j],v[curInd]);
            curInd--;
        }
    }
}

int main(){
    std::vector<int> v;
    v = initializer<int>("data.txt");
    insertionSort<int>(v);
    checker<int>(v);
    return 0;
}