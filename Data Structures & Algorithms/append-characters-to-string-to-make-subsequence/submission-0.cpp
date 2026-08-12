class Solution {
public:
    int appendCharacters(string s, string t) {
        int spointer = 0;
        for(int p1 = 0; p1 < t.size(); p1++){
            while(spointer < s.size() && s[spointer]!=t[p1]){
                spointer++;
            }
            if(spointer == s.size()){
                return t.size()-p1;
            }
            spointer++;
        }
        return 0;
    }
};