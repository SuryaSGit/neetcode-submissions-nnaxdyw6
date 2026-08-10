class Solution {
public:
    string addStrings(string num1, string num2) {
        string res;
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry=0;
        while(i >= 0 || j >= 0 || carry > 0){
            long long cur = 0;
            if(i >= 0){
                cur = cur + num1[i]-'0';
                i--;
            }
            if(j >= 0){
                cur = cur + num2[j]-'0';
                j--;
            }
            cur = cur + carry;
            res.push_back('0'+cur%10);
            carry = cur/10;
        }
        reverse(res.begin(),res.end());
        return res;
    }
    string multiplybydigit(string num1, char num2){
        string res = "";
        //assuming num1 is longer
        int carry = 0;
        int i = num1.size() - 1;
        while(i >= 0 || carry > 0){
            int cur = 0;
            if(i >=0){
                cur = (num1[i]-'0') * (num2-'0');
                i--;
            }
            cur = cur + carry;
            res.push_back('0'+cur%10);
            carry = cur/10;
        }
        reverse(res.begin(),res.end());
        return res;
    }
    string multiply(string num1, string num2) {
        if(num1=="0" || num2 == "0"){
            return "0";
        }
        string res = "0";
        for(int i = num2.size()-1; i >= 0; i--){
            int base = -1 + num2.size() - i;
            string temp = multiplybydigit(num1,num2[i]);
            for(int j = 0; j < base; j++){
                temp.push_back('0');
            }
            res = addStrings(res,temp);
        }
        return res;
    }
};
