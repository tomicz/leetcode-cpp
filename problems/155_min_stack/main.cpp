#include <iostream>
#include <stack>

class MinStack{
    public:
        std::stack<std::pair<int, int>> s;
        MinStack(){
            
        }

        void push(int val){
            if(s.empty()){
                s.push(std::make_pair(val, val));
            }else{
                s.push(std::make_pair(val, std::min(val, s.top().second)));
            }
        }

        void pop(){
           s.pop(); 
        }

        int top(){
            return s.top().first;
        }

        int getMin(){
            return s.top().second;
        }
};

int main(){
    MinStack* s =  new MinStack();
    s->push(-2);
    s->push(0);
    s->push(-3);
    s->getMin();
    s->pop();
    s->top();
    int min = s->getMin();
    std::cout << "min: " << min << std::endl;
return 0;
}
