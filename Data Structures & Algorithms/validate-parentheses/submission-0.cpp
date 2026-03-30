class Solution {
public:
    bool isValid(string s) {
        stack<char> temp;
        for(int i = 0; i < s.size(); i++){
            if(s[i]=='('||s[i]=='{'||s[i]=='['){
                temp.push(s[i]);
            }
            if(s[i]==']'||s[i]=='}'||s[i]==')'){
                if(temp.size()==0){
                    return false;
                }
                char temp2;
                if(s[i]==')'){
                    temp2= '(';
                }
                if(s[i]==']'){
                    temp2= '[';
                }
                if(s[i]=='}'){
                    temp2= '{';
                }
                if(temp.top()!=temp2){
                    return false;
                }
                temp.pop();
            }
        }
    if(temp.size()>0){
        return false;
    }
    return true;
   
    }
    
};
