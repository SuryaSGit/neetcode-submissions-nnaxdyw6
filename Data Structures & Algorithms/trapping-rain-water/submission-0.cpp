class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> maxleft(height.size());
        maxleft[0] = 0;
        for(int i = 1; i < height.size(); i++){
            maxleft[i] = max(maxleft[i-1],height[i-1]);
        }
        vector<int> maxright(height.size());
        maxright[height.size()-1] = 0;
        for(int i = height.size()-2; i >= 0; i--){
            maxright[i] = max(maxright[i+1],height[i+1]);
        }
        int water = 0;
        for(int i = 0; i < height.size(); i++){
            water = water + max(min(maxleft[i],maxright[i]) - height[i],0);
        }
        return water;
    }
};
