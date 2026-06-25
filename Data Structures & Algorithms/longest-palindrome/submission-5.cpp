class Solution {
public:
    int longestPalindrome(string s) {
        if(s.size() == 1){
            return 1;
        }
        map<char,int> counts;
        for(int i = 0; i < s.size(); i++){
            counts[s[i]]++;
        }
        int result = 0;
        bool one_odd = false;
        for(int i = 0; i < s.size(); i++){
            if(counts[s[i]]%2 != 0){
                one_odd = true;
            }
            result = result + counts[s[i]]/2;
            counts[s[i]]=0;
        }
        result = result * 2;
        if(one_odd){
            result++;
        }
        return result;
    }
};