class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> a;
        unordered_map<char,int> b;
        if(s.size()!=t.size()){
            return false;
        }
        for(int i = 0; i < s.size(); i++){
            a[s[i]]++;
            b[t[i]]++;
        }
        for(const auto& pair : a){
            if(b[pair.first]!=pair.second){
                return false;
            }
        }
        return true;
    }
};
