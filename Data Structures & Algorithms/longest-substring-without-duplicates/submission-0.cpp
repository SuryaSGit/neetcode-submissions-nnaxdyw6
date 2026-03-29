class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> vals;
        int p1 = 0; 
        int length = 0;
        for(int i = 0; i < s.size(); i++){
            if(vals.contains(s[i])){
               while(s[p1]!=s[i]){
                    vals.erase(s[p1]);
                    p1++;
               }
               vals.erase(s[p1]);
               p1++; 
            }
            vals.insert(s[i]);
            length = max(length, 1+(i-p1));
        }
        return length;
    }
};
