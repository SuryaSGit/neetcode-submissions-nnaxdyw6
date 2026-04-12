class Solution {
public:
    vector<string> result;
    void dfs(string& digits, int i, string cur){
        if(i == digits.size()){
            result.push_back(cur);
            return;
        }
        char curl = digits[i];
        if(curl == '2'){
            cur = cur + "a";
            dfs(digits,i+1,cur);
            cur.pop_back();
            cur = cur + "b";
            dfs(digits, i + 1, cur);
            cur.pop_back();
            cur = cur + "c";
            dfs(digits,i+1,cur);
            cur.pop_back();
        }
        else if(curl == '3'){
            cur = cur + "d";
            dfs(digits,i+1,cur);
            cur.pop_back();
            cur = cur + "e";
            dfs(digits, i + 1, cur);
            cur.pop_back();
            cur = cur + "f";
            dfs(digits,i+1,cur);
            cur.pop_back();
        }
        else if(curl == '4'){
            cur = cur + "g";
            dfs(digits,i+1,cur);
            cur.pop_back();
            cur = cur + "h";
            dfs(digits, i + 1, cur);
            cur.pop_back();
            cur = cur + "i";
            dfs(digits,i+1,cur);
            cur.pop_back();
        }
        else if(curl == '5'){
            cur = cur + "j";
            dfs(digits,i+1,cur);
            cur.pop_back();
            cur = cur + "k";
            dfs(digits, i + 1, cur);
            cur.pop_back();
            cur = cur + "l";
            dfs(digits,i+1,cur);
            cur.pop_back();
        }
        else if(curl == '6'){
            cur = cur + "m";
            dfs(digits,i+1,cur);
            cur.pop_back();
            cur = cur + "n";
            dfs(digits, i + 1, cur);
            cur.pop_back();
            cur = cur + "o";
            dfs(digits,i+1,cur);
            cur.pop_back();
        }
        else if(curl == '7'){
            cur = cur + "p";
            dfs(digits,i+1,cur);
            cur.pop_back();
            cur = cur + "q";
            dfs(digits, i + 1, cur);
            cur.pop_back();
            cur = cur + "r";
            dfs(digits,i+1,cur);
            cur.pop_back();
            cur = cur + "s";
            dfs(digits,i+1,cur);
            cur.pop_back();
        }
        else if(curl == '8'){
            cur = cur + "t";
            dfs(digits,i+1,cur);
            cur.pop_back();
            cur = cur + "u";
            dfs(digits, i + 1, cur);
            cur.pop_back();
            cur = cur + "v";
            dfs(digits,i+1,cur);
            cur.pop_back();
        }
        else if(curl == '9'){
            cur = cur + "w";
            dfs(digits,i+1,cur);
            cur.pop_back();
            cur = cur + "x";
            dfs(digits, i + 1, cur);
            cur.pop_back();
            cur = cur + "y";
            dfs(digits,i+1,cur);
            cur.pop_back();
            cur = cur + "z";
            dfs(digits,i+1,cur);
            cur.pop_back();
        }
        
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0){
            return result;
        }
        string temp;
        dfs(digits,0,temp);
        return result;
    }
};
