class Solution {
public:
    vector<vector<string>> result;
    void dfs(int i, const string& s, vector<string>& part, vector<vector<string>>& res){
        if(i >= s.length()){
            res.push_back(part);
            return;
        }
        for(int j = i; j < s.size(); j++){
            if(isPali(s,i,j)){
                part.push_back(s.substr(i,j-i + 1));
                dfs(j+1,s,part,res);
                part.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> temp;
        dfs(0,s,temp,result);
        return result;
    }
    bool isPali(const string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};
