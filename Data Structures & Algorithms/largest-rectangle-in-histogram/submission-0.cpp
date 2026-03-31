class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> prev_smallest(heights.size());
        vector<int> next_smallest(heights.size());
        stack<int> vals;
        for(int i = 0; i < heights.size(); i++){
            prev_smallest[i] = -1;
            next_smallest[i] = heights.size();
            while(!vals.empty() && heights[vals.top()] > heights[i]){
                next_smallest[vals.top()] = i;
                vals.pop();
            }
            if(!vals.empty()){
                prev_smallest[i] = vals.top();
            }
            vals.push(i);
        }
        int temp = 0;
        for(int i = 0; i < heights.size(); i++){
            temp = max(temp, heights[i]*(-1+next_smallest[i]-prev_smallest[i]));
        }
        return temp;
    }
};
