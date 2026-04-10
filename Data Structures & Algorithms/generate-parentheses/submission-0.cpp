class Solution {
public:
    vector<string> result;
    void dfs(string cur, int unclosed, int n){
        if(cur.size() == 2*n){
            result.push_back(cur);
            return;
        }
        if(unclosed == 2*n - cur.size()){
            cur.push_back(')');
            dfs(cur,unclosed-1,n);
            return;
        }
        cur.push_back('(');
        dfs(cur,unclosed+1,n);
        if(unclosed > 0){
            cur.pop_back();
            cur.push_back(')');
            dfs(cur,unclosed-1,n);
        }
    }
    vector<string> generateParenthesis(int n) {
        dfs("",0,n);
        return result;
    }
};
