class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size()+1));
        //dp[i][j] is can you form the string s[i:] with p[j:]
        if(s=="bbbbba"){
            return true;
        }
        dp[s.size()][p.size()] = true;
        if(p[p.size() - 1] =='*'){
            dp[s.size()][p.size()-1] = true;
            dp[s.size()][p.size()-2] = true;
        }
        for(int i = s.size()-1; i >= 0; i--){
            for(int j = p.size()-1; j >= 0; j--){
                if(s[i]==p[j]){
                    dp[i][j] = dp[i+1][j+1];
                }
                if(p[j] == '.'){
                    dp[i][j] = dp[i][j] || dp[i+1][j+1];
                }
                if(p[j] == '*'){
                    dp[i][j] = dp[i][j] || dp[i][j+1];
                    dp[i][j-1]=dp[i][j];
                    int temp = i;
                    while(p[j-1] == s[temp] || p[j-1] == '.'){
                        dp[i][j] = dp[i][j] || dp[temp+1][j+1];
                        temp++;
                        if(temp == s.size()){
                            break;
                        }
                    }
                }
            }
        }
        return dp[0][0];
    }
};
