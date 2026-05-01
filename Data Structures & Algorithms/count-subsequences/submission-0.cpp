class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size()+1,vector<int>(t.size()+1));
        dp[s.size()][t.size()] = 1;
        for (int i = 0; i <= s.size(); i++) {
            dp[i][t.size()] = 1;
        }
        for(int i = t.size() - 1; i >= 0; i--){
            for(int j = s.size() - 1; j >= i; j--){
                if(s[j] == t[i]){
                    dp[j][i] += dp[j+1][i + 1];
                }
                dp[j][i] += dp[j+1][i];
            }
        }
        return dp[0][0];
    }
};
