class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int cur_pos = digits.size()-1;
        while(cur_pos >= 0 && digits[cur_pos] == 9){
            digits[cur_pos] = 0;
            cur_pos--;
        }
        if(cur_pos < 0){
            vector<int> new_res;
            new_res.push_back(1);
            for(int i = 0; i < digits.size(); i++){
                new_res.push_back(0);
            }
            return new_res;
        }
        else{
            digits[cur_pos]++;
        }
        return digits;
    }
};
