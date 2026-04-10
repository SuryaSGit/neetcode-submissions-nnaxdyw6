class Solution {
public:
    bool found;
    void dfs(vector<vector<char>>& board, string word, string cur, int cur_x, int cur_y, vector<vector<bool>> visited){
        if(cur == word){
            found = true;
            return;
        }
        if(found){
            return;
        }
        if(cur.size() > word.size()){
            return;
        }
        if(word.substr(0, cur.size()) != cur){
            return;
        }
        if(cur.size()==1){
            visited[cur_x][cur_y] = true;
        }
        if(cur_x > 0 && visited[cur_x-1][cur_y]==false){
            cur = cur + board[cur_x - 1][cur_y];
            visited[cur_x-1][cur_y] = true;
            dfs(board,word,cur,cur_x-1,cur_y,visited);
            cur.pop_back();
            visited[cur_x-1][cur_y] = false;
        }
        if(cur_x < board.size()-1 && visited[cur_x+1][cur_y]==false){
            cur = cur + board[cur_x + 1][cur_y];
            visited[cur_x+1][cur_y] = true;
            dfs(board,word,cur,cur_x+1,cur_y,visited);
            cur.pop_back();
            visited[cur_x+1][cur_y] = false;
        }
        if(cur_y > 0 && visited[cur_x][cur_y-1]==false){
            cur = cur + board[cur_x][cur_y-1];
            visited[cur_x][cur_y-1] = true;
            dfs(board,word,cur,cur_x,cur_y-1,visited);
            cur.pop_back();
            visited[cur_x][cur_y-1] = false;
        }
        if(cur_y < board[0].size()-1 && visited[cur_x][cur_y+1]==false){
            cur = cur + board[cur_x][cur_y+1];
            visited[cur_x][cur_y+1] = true;
            dfs(board,word,cur,cur_x,cur_y+1,visited);
            cur.pop_back();
            visited[cur_x][cur_y+1] = false;
        }
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        found = false;
        vector<vector<bool>> temp;
        for(int i = 0; i < board.size(); i++){
            vector<bool> temp2(board[i].size());
            temp.push_back(temp2);
        }
        for(int i = 0; i < board.size();i++){
            for(int j = 0; j < board[i].size();j++){
                string temp5;
                temp5 = temp5 + board[i][j];
                dfs(board,word,temp5,i,j,temp);
            }
        }
        return found;
    }
};
