class Solution {
public:
    vector<vector<bool>> board;
    vector<vector<string>> result;
    vector<bool> cols;
    vector<bool> right_diag;
    vector<bool> left_diag;
    void dfs(int& n, int layer){
        if(layer == n){
            vector<string> temp;
            for(int i = 0; i < board.size(); i++){
                string cur;
                for(int j = 0; j < board[i].size(); j++){
                    if(board[i][j]){
                        cur=cur + "Q";
                    }
                    else{
                        cur = cur + ".";
                    }
                }
                temp.push_back(cur);
            }
            result.push_back(temp);
            return;
        }
        for(int i = 0; i < n; i++){
            if(cols[i]==true){
                continue;
            }
            if(left_diag[-1 + layer + n - i]==true){
                continue;
            }
            if(right_diag[layer + i] == true){
                continue;
            }
            cols[i]=true;
            left_diag[-1 + layer + n - i] = true;
            right_diag[layer + i] = true;
            board[layer][i] = true;
            dfs(n,layer + 1);
            cols[i]=false;
            left_diag[-1 + layer + n - i] = false;
            right_diag[layer + i] = false;
            board[layer][i] = false;
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        for(int i = 0; i < n; i++){
            cols.push_back(false);
            vector<bool> temp;
            for(int j = 0; j < n; j++){
                temp.push_back(false);
            }
            board.push_back(temp);
        }
        for(int i = 0; i < 2*n-1; i++){
            left_diag.push_back(false);
            right_diag.push_back(false);
        }
        dfs(n,0);
        return result;
    }
};
