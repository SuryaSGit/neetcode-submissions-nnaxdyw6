class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<int>> vals;
        for(int i = 0; i < strs.size(); i++){
            string temp = strs[i];
            std::sort(temp.begin(),temp.end());
            vals[temp].push_back(i);
        }
        vector<vector<string>> result;
        for(const auto pair : vals){
            vector<string> temp;
            for(int i = 0; i < pair.second.size(); i++){
                temp.push_back(strs[pair.second[i]]);
            }
            result.push_back(temp);
        }
        return result;
    }
};
