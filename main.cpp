#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

bool isPalndrome(std::string s){
    if(s.empty()){
        return false;
    }

    if(s.size() == 1){
        return true;
    }        
    
    // Convert it to lowercase
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    std::string filtered_string;

    // Go through ASCII and return 0-9 and a-z chars

    for(char c: s){
        if(c > 47 && c < 58 || c > 96 && c < 123)
            filtered_string += c; 
    }
    
    int r = 0;
    int l = filtered_string.size() -1;

    while(r < l){
        if(filtered_string[r] != filtered_string[l]){
            return false;
        }
        r++;
        l--;
    }

    return true;
}

std::vector<int> two_sum(std::vector<int>& nums, int target){
    std::unordered_map<int, int> umap;
    std::vector<int> indicies; 
    
    for(size_t i = 0; i < nums.size(); i++){
        int sum = target - nums[i];
        if(umap.find(sum) != umap.end()){
            indicies.push_back(i);
            indicies.push_back(umap[sum]);
        }else{
            umap[nums[i]] = i;
        }
    } 

    return indicies;
}

void find_key(std::unordered_map<int, int> umap, int& key){
    if(umap.find(key) != umap.end()){
        std::cout << "key found: " << key << std::endl;
    }
    else{
        std::cout << "key not found: " << key << std::endl;
    }
}

int main(){

    char a = 'a';
    std::cout << static_cast<int>(a) << std::endl;
    std::unordered_map<int, int> umap;
    
    umap[0] = 10;
    umap[1] = 20;
    umap[2] = 30;
    umap[3] = 40;
    umap[4] = 50;

    int key = 4;
    int key1 = 6;

    find_key(umap, key);
    find_key(umap, key1);
    
    // TWO SUM
    std::cout << "TWO SUM" << std::endl;
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    std::vector<int> result = two_sum(nums, target);
    std::cout << result[0] << ", " << result[1] << std::endl;

    std::cout << "IS PALINDROME" << std::endl;
     
    std::string s = "A man, a plan, a canal: Panama";
    std::string s1 = "race a car";
    bool isp = isPalndrome(s); 
    bool isp1 = isPalndrome(s1); 
    std::cout << "is palindrome: " << isp << std::endl;
    std::cout << "is palindrome: " << isp1 << std::endl;

    return 0;
}
