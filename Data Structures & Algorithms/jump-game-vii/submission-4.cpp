class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        vector<bool> dp(s.size());
        dp[0] = true;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '0'){
                for(int j = minJump; j < maxJump + 1; j++){
                    if(i-j < 0){
                        break;
                    }
                    if(dp[i-j]){
                        dp[i] = true;
                    }
                }
                cout << i << dp[i] << endl;
            }
        }
        return dp[s.size()-1];
    }
};