class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> vals;
        char max_char = s[0];
        int dist_char = 0;
        int pos = 0;
        int max_length = 0;
        for(int i = 0; i < s.size(); i++){
            vals[s[i]]++;
            if(vals[s[i]] > vals[max_char]){
                max_char = s[i];
            }
            if(max_char != s[i]){
                dist_char++;
            }
            while(dist_char > k){
                vals[s[pos]]--;
                for(const auto& pair : vals){
                    if(pair.second > vals[max_char]){
                        max_char = pair.first;
                    }
                }
                if(max_char != s[pos]){
                    dist_char--;
                }
                pos++;
            }
            max_length = max(max_length, 1+i-pos);
        }
        return max_length;
    }
};
