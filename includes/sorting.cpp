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
        for(size_t j = i+1; j < vec.size(); j++){
            if(vec[min] > vec[j]){
                min = j;
            }
        }
        if(min != i){
            int temp = vec[i]; 
            vec[i] = vec[min];
            vec[min] = temp;
        }
    }
}

void Sorting::sort_insertion(std::vector<int>& vec){
   for(size_t i = 1; i < vec.size(); i++){
       int temp = vec[i];
       int j = i - 1;
       while(j >= 0 && vec[j] > temp){
           vec[j + 1] = vec[j];
           j--;
       }
       vec[j+1] = temp;
   }
}

void Sorting::print(const std::vector<int>& vec){
    for(int i: vec){
        std::cout << i << ", ";
    }
    std::cout << std::endl;
}
