class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> vals(9,std::vector<int>(9));
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j]=='.'){
                    vals[i][j] = -1;
                }
                else{
                    vals[i][j] = (board[i][j])-'0';
                }
            }
        }
        unordered_set<int> temp;
        for(int i = 0; i < 9; i++){
            temp = {};
            for(int j = 0; j < 9; j++){
                if(vals[i][j]==-1){
                    continue;
                }
                if(temp.contains(vals[i][j])){
                    return false;
                }
                temp.insert(vals[i][j]);
            }
        }
        for(int i = 0; i < 9; i++){
            temp = {};
            for(int j = 0; j < 9; j++){
                if(vals[j][i]==-1){
                    continue;
                }
                if(temp.contains(vals[j][i])){
                    return false;
                }
                temp.insert(vals[j][i]);
            }
        }
        for(int i = 0; i < 9; i = i + 3){
            for(int j = 0; j < 9; j = j + 3){
                temp = {};
                for(int k = 0; k < 3; k++){
                    for(int l = 0; l < 3; l++){
                        if(vals[i+k][j+l]==-1){
                            continue;
                        }
                        if(temp.contains(vals[i+k][j+l])){
                            return false;
                        }
                        temp.insert(vals[i+k][j+l]);
                    }
                }
            }
        }
        return true;
    }
};
