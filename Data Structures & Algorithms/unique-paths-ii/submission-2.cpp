class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int h = obstacleGrid.size();
        int w = obstacleGrid[0].size();
        vector<int> dp(w,0);
        if(obstacleGrid[0][0] == 1){
            return 0;
        }
        dp[0] = 1;
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(i == 0 && j == 0){
                    continue;
                }
                if(obstacleGrid[i][j] == 1){
                    dp[j] = 0;
                    continue;
                }
                int up = i > 0 ? dp[j] : 0;
                int left = j > 0 ? dp[j-1] : 0;
                dp[j] = up + left;

            }
        }
        return dp[w-1];
    }
    //TC: O(NM)
    //SC: O(NM)
};