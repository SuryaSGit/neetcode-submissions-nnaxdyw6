class Solution {
public:
    int maxArea(vector<int>& heights) {
        int p1 = 0;
        int p2 = heights.size()-1;
        int val = 0;
        while(p1 < p2){
            val = max(val,(min(heights[p1],heights[p2])*(p2-p1)));
            if(heights[p1] > heights[p2]){
                p2--;
            }
            else{
                p1++;
            }
        }
        return val;
    }
};
