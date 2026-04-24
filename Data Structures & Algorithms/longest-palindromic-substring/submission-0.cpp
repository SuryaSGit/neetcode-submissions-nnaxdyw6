class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n);
        for(int i = 0; i < n; i++){
            vector<bool> temp(n);
            dp[i] = temp;
        }
        int resultid = 0;
        int resultsize = 0;
        for(int i = n-1; i >= 0; i--){
            for(int j = i; j < n; j++){
                if(s[i] == s[j]){
                    if(j-i <= 2){
                        dp[i][j] = true;
                    }
                    else if(dp[i + 1][j - 1]){
                        dp[i][j] = true;
                    }
                    if(dp[i][j] && 1 + j - i > resultsize){
                        resultsize = 1 + j - i;
                        resultid = i;
                    }
                }
            }
        }
        return s.substr(resultid, resultsize);
    }
};
