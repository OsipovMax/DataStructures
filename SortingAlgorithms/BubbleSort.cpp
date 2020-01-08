#include "checker.h"

template<typename T>
void bubbleSort(std::vector<T> &v){
    for (int i = 0; i < v.size(); ++i){
        for (int j = 0; j < v.size() - 1 - i; ++j){
            if (v[j] > v[j + 1]){
                std::swap(v[j], v[j + 1]);
            }
        }
    }
}

int main() {
    std::vector<int> v;
    v = initializer<int>("data.txt");
    bubbleSort<int>(v);
    checker<int>(v);
    return 0;
}