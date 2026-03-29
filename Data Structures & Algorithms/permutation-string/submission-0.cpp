class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()){
            return false;
        }
        vector<int> a(26);
        vector<int> b(26);
        for(int i = 0; i < s1.size(); i++){
            a[s1[i]-'a']++;
        }
        
        for(int i = 0; i < s2.size(); i++){
            b[s2[i]-'a']++;
            if(i >= s1.size()){
                b[s2[i-s1.size()]-'a']--;
            }
            if(b==a){
                return true;
            }
        }
        return false;
    }
};
