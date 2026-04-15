class Solution {
public:
    void bfs(vector<vector<char>>& board, int cur_row, int cur_col){
        queue<pair<int,int>> temp;
        temp.push({cur_row,cur_col});
        while(!temp.empty()){
            pair<int,int> cur = temp.front();
            temp.pop();
            board[cur.first][cur.second] = 'A';
            if(cur.first > 0 && board[cur.first-1][cur.second] == 'O'){
                temp.push({cur.first-1, cur.second});
            }
            if(cur.second > 0 && board[cur.first][cur.second-1] == 'O'){
                temp.push({cur.first, cur.second-1});
            }
            if(cur.first < board.size()-1 && board[cur.first+1][cur.second] == 'O'){
                temp.push({cur.first+1, cur.second});
            }
            if(cur.second < board[0].size()-1 && board[cur.first][cur.second+1] == 'O'){
                temp.push({cur.first, cur.second+1});
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        for(int i = 0; i < board.size(); i++){
            if(board[i][0]=='O'){
                bfs(board,i,0);
            }
            if(board[i][board[i].size()-1]=='O'){
                bfs(board,i,board[i].size()-1);
            }
        }
        for(int i = 1; i < board[0].size()-1; i++){
            if(board[0][i]=='O'){
                bfs(board,0,i);
            }
            if(board[board.size()-1][i]=='O'){
                bfs(board,board.size()-1,i);
            }
        }
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                if(board[i][j]=='A'){
                    board[i][j]='O';
                }
                else if(board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};
