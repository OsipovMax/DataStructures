#include <iostream>
#include <vector>
#include <fstream>

//Initial initialization function
template<typename T>
std::vector<T> initializer(std::string fileName){
    std::vector<int> vec;
    std::ifstream in (fileName, std::ios::in);
    int singleElement = 0;
    while(in >> singleElement){
        vec.push_back(singleElement);
    }
    return vec;
}
