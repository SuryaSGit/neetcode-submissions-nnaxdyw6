class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> vals;
        for(int i = 0; i < tokens.size(); i++){
            if(tokens[i]=="/"){
                int temp = vals.top();
                vals.pop();
                vals.top() = vals.top() / temp;
            }
            else if(tokens[i]=="*"){
                int temp = vals.top();
                vals.pop();
                vals.top() = vals.top() * temp;
            }
            else if(tokens[i]=="-"){
                int temp = vals.top();
                vals.pop();
                vals.top() = vals.top() - temp;
            }
            else if(tokens[i]=="+"){
                int temp = vals.top();
                vals.pop();
                vals.top() = vals.top() + temp;
            }
            else{
                vals.push(stoi(tokens[i]));
            }
        }
        return vals.top();
    }
};
