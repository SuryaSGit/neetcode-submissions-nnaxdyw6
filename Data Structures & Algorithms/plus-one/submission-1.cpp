class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int cur_pos = digits.size()-1;
        while(cur_pos >= 0 && digits[cur_pos] == 9){
            digits[cur_pos] = 0;
            cur_pos--;
        }
        if(cur_pos < 0){
            digits.insert(digits.begin(),1);
        }
        else{
            digits[cur_pos]++;
        }
        return digits;
    }
};
