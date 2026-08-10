class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> char_counts(26);
        int max_frequency = 0;
        int l = 0;
        int res = 0;
        for(int r = 0; r < s.size(); r++){
            char_counts[s[r]-'A']++;
            max_frequency = max(max_frequency, char_counts[s[r]-'A']);
            while(l < r && (1 + (r-l) - max_frequency > k)){
                char_counts[s[l]-'A']--;
                l++;
            }
            res = max(res,1+r-l);
        }
        return res;
    }
};
