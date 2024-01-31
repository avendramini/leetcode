class MinStack {
public:
    map<int,int> m;
    vector<int> v; 
    MinStack() {
    }
    
    void push(int val) {
        v.push_back(val);
        m[val]++;
    }
    
    void pop() {
        int x=v[v.size()-1];
        v.pop_back();
        m[x]--;
        if(m[x]==0)
            m.erase(x);
    }
    
    int top() {
        return v[v.size()-1];
    }
    
    int getMin() {
        for(auto x: m)
            return x.first;
        return -1;
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
