#include "checker.h"

template<typename T>
void selectionSort(std::vector<T> &vec){
    int minInd = 0;
    for (int i = 0; i < vec.size() - 1; ++i){
        minInd = i;
        for (int j = i + 1; j < vec.size(); ++j){
            if (vec[minInd] > vec[j]){
                minInd = j;
            }
        }
        if (minInd != i){
            std::swap(vec[i], vec[minInd]);
        }
    }
}

int main() {
    std::vector<int> v;
    v = initializer<int>("data.txt");
    selectionSort<int>(v);
    checker<int>(v);
    return 0;
}