class Solution {
public:
    bool checkVowel(char tmp){
        if(tmp == 'a' || tmp == 'e'|| tmp == 'i'|| tmp== 'o'|| tmp == 'u'){
            return true;
        }
        return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> prefix(words.size());
        for(int i = 0; i < words.size(); i++){
            if(i > 0){
                prefix[i]=prefix[i-1];
            }
            if(checkVowel(words[i][0]) && checkVowel(words[i][words[i].size()-1])){
                prefix[i]++;
            }
        }
        vector<int> res;
        for(vector<int> cur : queries){
            if(cur[0] == 0){
                res.push_back(prefix[cur[1]]);
            }
            else{
                res.push_back(prefix[cur[1]]-prefix[cur[0]-1]);
            }
        }
        return res;
    }
};