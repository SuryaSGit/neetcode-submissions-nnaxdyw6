class Solution {
public:
    bool checkValidString(string s) {
        int always_close = 0;
        int always_open = 0; 
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                always_close++;
                always_open++;
            }
            else if(s[i] == ')'){
                always_close--;
                always_open--;
            }
            else{
                always_close--;
                always_open++;
            }
            if(always_open < 0){
                return false;
            }
            if(always_close < 0){
                always_close = 0;
            }
        }
        return(always_close == 0);
    }
};
