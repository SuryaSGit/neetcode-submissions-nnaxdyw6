class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int str_size = s.size();
        vector<bool> dp(str_size+1);
        for(int i = s.size()-1; i >= 0; i--){
            for(string x : wordDict){
                if(x.size() > str_size - i){
                    continue;
                }
                if(s.substr(i,x.size()) == x){
                    if(i + x.size() == s.size()){
                        dp[i] = true;
                        break;
                    }
                    else{
                        dp[i] = dp[i + x.size()];
                    }
                }
                if(dp[i]){
                    break;
                }
            }
        }
        return dp[0];
    }
};
