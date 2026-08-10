class Solution {
public:
    int trap(vector<int>& height) {
        int leftp = 0;
        int rightp = height.size() - 1;
        int leftmax=height[0];
        int rightmax=height[height.size() - 1];
        int res = 0;
        while(leftp < rightp){
            if(height[leftp] < height[rightp]){
                leftp++;
                leftmax = max(leftmax,height[leftp]);
                res = res + max(0,min(leftmax,rightmax)-height[leftp]);
            }
            else{
                rightp--;
                rightmax = max(rightmax,height[rightp]);
                res = res + max(0,min(leftmax,rightmax)-height[rightp]);
            }
        }
        return res;
    }
};
