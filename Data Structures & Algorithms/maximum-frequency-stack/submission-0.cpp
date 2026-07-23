class FreqStack {
private:
    vector<stack<int>> stacks;
    unordered_map<int,int> freq;
public:
    FreqStack() {
        stacks.push_back(stack<int>());
    }
    
    void push(int val) {
        if(!freq.contains(val)){
            freq[val] = 1;
        }
        else{
            freq[val]++;
        }
        if(freq[val] == stacks.size()){
            stacks.push_back(stack<int>());
        }
        cout << stacks.size() << endl;
        stacks[freq[val]].push(val);
    }
    
    int pop() {
        cout << stacks.size() << endl;
        int res = stacks[stacks.size() -1].top();
        stacks[stacks.size() - 1].pop();
        if(stacks[stacks.size() - 1].size() == 0){
            stacks.pop_back();
        }
        freq[res]--;
        return res;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */