#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <random>

const int DATA_SIZE = 10000;

int main() {
    std::vector<int> v;
    std::vector<int> sortedV;
    for (int i = 0; i < DATA_SIZE; ++i){
        v.push_back(i);
        sortedV.push_back(i);
    }

    std::random_device rd;
    std::mt19937 g(rd());
 
    shuffle(v.begin(), v.end(), g);

    std::ofstream fout ("data.txt", std::ios::out);
    for (int i = 0; i < DATA_SIZE; ++i){
        fout << v[i] << " ";
    }
    fout.close();
    fout.open("sortedData.txt", std::ios::out);
    for (int i = 0; i < DATA_SIZE; ++i){
        fout << sortedV[i] << " ";
    }
    fout.close();
    return 0;
}