class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> vals;
        for(int i = 0; i < nums.size(); i++){
            vals[nums[i]]++;
        }
        vector<int> result;
        vector<vector<int>> temp(nums.size()+1,std::vector<int>());
        for(const auto pair : vals){
            temp[pair.second].push_back(pair.first);
        }

        for(int j = temp.size()-1; j >= 0; j--){
            if(result.size()<k){
                result.insert(result.end(),temp[j].begin(),temp[j].end());
            }
        }
        return result;
    }
};
