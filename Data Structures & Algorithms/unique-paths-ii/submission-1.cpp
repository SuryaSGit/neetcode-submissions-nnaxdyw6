class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int h = obstacleGrid.size();
        int w = obstacleGrid[0].size();
        vector<vector<int>> dp(h,vector<int>(w,0));
        if(obstacleGrid[0][0] == 1){
            return 0;
        }
        dp[0][0] = 1;
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(i == 0 && j == 0){
                    continue;
                }
                if(obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                    continue;
                }
                int up = i > 0 ? dp[i-1][j] : 0;
                int left = j > 0 ? dp[i][j-1] : 0;
                dp[i][j] = up + left;

            }
        }
        return dp[h-1][w-1];
    }
};