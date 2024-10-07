#ifndef _SORTING_H_
#define _SORTING_H_

#include <vector>

class Sorting{
    public:
        void sort_bubble(std::vector<int>& vec);
        void sort_selection(std::vector<int>& vec);
        void sort_insertion(std::vector<int>& vec);
        void print(const std::vector<int>& vec);
};

#endif
