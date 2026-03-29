class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> vals;
        for(int i = 0; i < nums.size(); i++){
            vals[nums[i]]++;
        }
        vector<int> result;
        int max = 0;
        for(int i = 0; i < k; i++){
            max = 0;
            for(const auto pair : vals){
                if(pair.second > vals[max]){
                    max = pair.first;
                }
            }
            vals[max] = 0;
            result.push_back(max);
        }
        return result;
    }
};
