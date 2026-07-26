class MinStack {
public:
    vector<pair<int,int>> st;
    int tp;
    MinStack() {
        tp = -1;
    }
    
    void push(int val) {
        int mini = val;
        if(tp != -1)
            mini = min(mini,st.back().second);
        st.push_back({val,mini});
        tp++;
    }
    
    void pop() {
        // if(tp != -1)
        st.pop_back();
        tp--;
    }
    
    int top() {
        // if(tp != -1)
        return st.back().first;
    }
    
    int getMin() {
        return st.back().second;
    }
};
