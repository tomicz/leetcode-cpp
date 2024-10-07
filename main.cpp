#include <iostream>
#include <chrono>
#include <vector>
#include "includes/sorting.h"

int main(){
    auto start = std::chrono::high_resolution_clock::now();

    std::vector<int> vec = {10, 4, 1, 6, 3, 9, 5, 8, 2};
    Sorting sorting;
    sorting.sort_insertion(vec);
    for(int i: vec){
        std::cout << i << ",";
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    std::cout << "Time taken: " << duration.count() << " milliseconds" << std::endl;
    return 0;
}
