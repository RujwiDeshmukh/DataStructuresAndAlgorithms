class MinStack {
public:
    
    vector<pair<int,int>>s;
    MinStack() {
        
    }
    
    void push(int val) {
        if(s.empty())
        {
            s.push_back({val,val});
        }
        else
        {
            //checking with the last smallest element
            //if more smaller element encountered then update the minimum value
            s.push_back({val,min(val,s.back().second)});
        }
    }
    
    void pop() {
        return s.pop_back();
    }
    
    int top() {
        return s.back().first;
    }
    
    int getMin() {
        return s.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */