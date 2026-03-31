class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int low = 0;
        int high = m*n - 1;
        int mid = (low + high)/2;
        while(low <= high){
            int cur = matrix[mid/n][mid%n];
            if(cur == target){
                return true;
            }
            if(cur > target){
                high = mid-1;
            }
            else{
                low = mid + 1;
            }
            mid = (low + high)/2;
        }
        return false;
    }
};
