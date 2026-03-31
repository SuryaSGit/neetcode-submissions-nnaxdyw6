//Decreasing stack that stores indices. When a new element comes,
//pop everything higher, and set next_smallest to new element index
//at the end, the top should be the prev smallest of the new element, so set it
//then multiply the width (-1 + next smallest - prev smallest) by every height
//and find the max.
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
