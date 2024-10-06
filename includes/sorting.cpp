#include <iostream>
#include <vector>
#include "sorting.h"

void Sorting::sort_bubble(std::vector<int>& vec){
    for(size_t i = 0; i < vec.size(); i++){
        for(size_t j = 0; j < vec.size()-1; j++){
            if(vec[j] > vec[j+1]){
                int temp = vec[j];
                vec[j] = vec[j+1];
                vec[j + 1] = temp;
            }
        }
    }
}

void Sorting::sort_selection(std::vector<int>& vec){
    for(size_t i = 0; i < vec.size(); i++){
        int min = i;
        int temp = vec[i]; 
        for(size_t j = i+1; j < vec.size(); j++){
            if(vec[j] < vec[min]){
                min = j;
            }
        }
        vec[i] = vec[min];
        vec[min] = temp;
    }
}

void Sorting::print(std::vector<int>& vec){
    for(int i: vec){
        std::cout << i << ", ";
    }
    std::cout << std::endl;
}
