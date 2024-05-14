class MinStack {
public:
    int mn=INT_MAX;
    deque<int> q;
    deque<pair<int,int>> min_rec;
    MinStack() {
        q.clear();
    }
    
    void push(int val) {
        q.push_back(val);
        min_rec.push_back({val,mn});
        mn=min(mn,val);
    }
    
    void pop() {
        mn=min_rec.back().second;
        min_rec.pop_back();
        q.pop_back();
    }
    
    int top() {
        return q.back();
    }
    
    int getMin() {
        return mn;
    }
};