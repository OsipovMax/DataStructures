#include "initializer.h"

//This function checks whether the sorting is correct
template<typename T>
void checker(std::vector<T> &v){
    std::vector<int> sortedV;
    sortedV = initializer<T>("sortedData.txt");
    std::ifstream in ("sortedData.txt", std::ios::in);
    if (v == sortedV){
        std::cout << "The data is correctly sorted." << std::endl;
        return;
    }
    std::cout << "Oops, the data is not sorted or not sorted correctly." << std::endl;
}