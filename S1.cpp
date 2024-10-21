#include<iostream>
using namespace std;
class MyQueue {
public:
stack<int> in;
stack<int> out;
int p=0;
    MyQueue() {
        
    }
    
    void push(int x) {
        if(in.empty()) p=x;
        in.push(x);
        
    }
    
    int pop() {
        if(out.empty())
        {
            while(!in.empty()){
                out.push(in.top());
                in.pop();
            }
        }
        int val =out.top();
        out.pop();
        return val;
    }
    
    int peek(){
        if(out.empty())return p;
        return out.top();
    }
    
    bool empty() {
        if(in.empty()&& out.empty())
        return true;
        else return false;
        
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
