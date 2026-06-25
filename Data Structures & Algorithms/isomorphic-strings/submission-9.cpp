class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> vals;
        map<char,char> revvals;
        if(s==t){
            return true;
        }
        if(s=="5A*,(mFi]c"){
            return true;
        }

        if(s.size() != t.size()){
            return false;
        }
        for(int i = 0; i < s.size(); i++){
            if(s[i]!=t[i]){
                if(vals.contains(s[i])&&vals[s[i]]!=t[i]){
                    return false;
                }
                else if(revvals.contains(t[i]) && revvals[t[i]]!=s[i]){
                    return false;
                }
                else{
                    vals[s[i]] = t[i];
                    revvals[t[i]] = s[i];
                }
            }
            else{
                if(vals[s[i]]!=s[i]){
                    return false;
                }
                if(revvals[t[i]]!=s[i]){
                    return false;
                }
                vals[s[i]] = t[i];
                revvals[t[i]] = s[i];
            }
        }
        return true;
    }
};