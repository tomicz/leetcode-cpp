#include <iostream>
#include <vector>
#include <chrono>  
#include <random>

void print_vector(const std::vector<int>& vec){
    for(int i: vec){
        std::cout << i << ",";
    }
    std::cout << std::endl;
}

void print_string(const std::string& s){
    for(char c: s){
        std::cout << c << ",";
    }
    std::cout << std::endl;
}

void sort_bubble(std::string& s){
    bool swapped;
    for(size_t i = 0; i < s.size(); i++){
        swapped = false;
        for(size_t j = 0; j < s.size() - i - 1; j++){
            if(s[j] > s[j+1]){
                char temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
                swapped = true;
            }
        }
        if (!swapped) break;  // Optimization: Stop if already sorted
    }
}

void sort_insertion(std::string& s){
    for(size_t i = 1; i < s.size(); i++){
        int j = i - 1;
        char temp = s[i];
        while(j >= 0 && s[j] > temp){
            s[j+1] = s[j];
            j--;
        }
        s[j+1] = temp;
    }
}

void sort_selection(std::string& s){
    for(size_t i = 0; i < s.size(); i++){
        size_t  min = i; 
        for(size_t j = i + 1; j < s.size(); j++){
            if(s[min] > s[j]){
                min = j; 
            }
        }
        if(min != i){
            char temp = s[i];
            s[i] = s[min];
            s[min] = temp;
        }
    }
}

int random_between(int min, int max) {
    std::random_device rd;  // Seed for the random number engine
    std::mt19937 gen(rd());  // Mersenne Twister engine
    std::uniform_int_distribution<> distr(min, max);  // Define the range [min, max]
    return distr(gen);  // Generate random number within the range
}

std::string get_random_string(){
    std::string s;
    int size = random_between(1, 100000);
    for(size_t i = 0; i < size; i++){
        int l = random_between(0, 25);
        s+=static_cast<char>(l + 'a');
    }
    return s;
}

int main(){
    std::string random_string = get_random_string();
    std::string s = random_string;
    std::string s1 = random_string;
    std::string s2 = random_string;

    auto start = std::chrono::high_resolution_clock::now();
    sort_bubble(s2);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> bubble_time = end - start;
    std::cout << "Bubble Sort: " << bubble_time.count() << " ms" << std::endl;
    //print_string(s2);


    start = std::chrono::high_resolution_clock::now();
    sort_selection(s1);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> selection_time = end - start;
    std::cout << "Selection Sort: " << selection_time.count() << " ms" << std::endl;
    //print_string(s1);

    start = std::chrono::high_resolution_clock::now();
    sort_insertion(s);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> insertion_time = end - start;
    std::cout << "Insertion Sort: " << insertion_time.count() << " ms" << std::endl;
    //print_string(s);


    return 0;
}
