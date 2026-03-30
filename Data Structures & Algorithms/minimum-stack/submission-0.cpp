class MinStack {
public:
    MinStack() {
        min_.push_back(INT_MAX);
    }
    
    void push(int val) {
        arr_.push_back(val);
        min_.push_back(min(val,min_[min_.size()-1]));
    }
    
    void pop() {
        arr_.erase(arr_.begin()+arr_.size()-1);
        min_.erase(min_.begin()+min_.size()-1);
    }
    
    int top() {
        return arr_[arr_.size()-1];
    }
    
    int getMin() {
        return min_[min_.size()-1];
    }
private:
    std::vector<int> arr_;
    std::vector<int> min_;
};
