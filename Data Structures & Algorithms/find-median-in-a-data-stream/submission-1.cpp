class MedianFinder {
public:
    priority_queue<int,vector<int>,less<int>> lower_half;
    priority_queue<int,vector<int>,greater<int>> upper_half;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(lower_half.empty()){
            lower_half.push(num);
            return;
        }
        if(upper_half.empty()){
            if(num < lower_half.top()){
                upper_half.push(lower_half.top());
                lower_half.pop();
                lower_half.push(num);
            }
            else{
                upper_half.push(num);
            }
            return;
        }
        if(num > upper_half.top()){
            upper_half.push(num);
        }
        else{
            lower_half.push(num);
        }
        if(lower_half.size() > upper_half.size()+1){
            upper_half.push(lower_half.top());
            lower_half.pop();
        }
        if(upper_half.size() > lower_half.size()){
            lower_half.push(upper_half.top());
            upper_half.pop();
        }
    }
    
    double findMedian() {
        if((upper_half.size()+lower_half.size())%2 == 0){
            return (upper_half.top() + lower_half.top())/ 2.0;
        }
        else{
            return lower_half.top();
        }
    }
};
