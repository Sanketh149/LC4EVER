class MinStack {
public:
    MinStack() {
        
    }
    stack<long long>s;
    long long mini = INT_MAX;
    void push(int val) {
        if(mini > val)
        {
            long long tp = 1L*2*val;
            tp -= mini;
            s.push(tp);
            mini = val;
        }
        else{
            s.push(val);
        }
    }
    
    void pop() {
        long long tp = s.top();
        if(s.top() < mini)
        {
            mini = 2*mini - tp;
        }
        s.pop();
    }
    
    int top() {
        long long tp = s.top();
        if(tp < mini)
            return mini;
        return tp;
    }
    
    int getMin() {
        return mini;
    }
};
