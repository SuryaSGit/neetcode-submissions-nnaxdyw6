class TrieNode {
public:
    TrieNode* children[26];
    bool isLeaf;

    TrieNode() {
        isLeaf = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};
class PrefixTree {
public:
    PrefixTree() {
        root = nullptr;
    }
    
    void insert(string word) {
        if(root == nullptr){
            root = new TrieNode();
        }
        TrieNode* cur = root;
        for(char x : word){
            if(cur->children[x-'a'] == nullptr){
                cur->children[x-'a'] = new TrieNode();
            }
            cur = cur -> children[x-'a'];
        }
        cur -> isLeaf = true;
    }
    
    bool search(string word) {
        TrieNode* cur = root;
        if(cur == nullptr){
            return false;
        }
        for(char x : word){
            if(cur->children[x-'a']==nullptr){
                return false;
            }
            else{
                cur = cur->children[x-'a'];
            }
        }
        return cur->isLeaf;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        if(cur == nullptr){
            return false;
        }
        for(char x : prefix){
            if(cur->children[x-'a']==nullptr){
                return false;
            }
            else{
                cur = cur->children[x-'a'];     
            }
        }
        return true;
    }
private:
    TrieNode* root;
};

class Solution {
public:
    vector<string> result;
    void dfs(int cur_x, int cur_y, vector<vector<char>>& board, PrefixTree*& pref, string cur){
        cur.push_back(board[cur_x][cur_y]);
        if(!pref->startsWith(cur)){
            return;
        }
        if(pref->search(cur)){
            bool notfound = true;
            for(string j : result){
                if(j == cur){
                    notfound = false;
                }
            }
            if(notfound){
                result.push_back(cur);
            }
        }
        if(result.size()==wordsize_){
            return;
        }
    
        char temp = board[cur_x][cur_y];
        board[cur_x][cur_y] = '#';
        if(cur_x > 0){
            if(board[cur_x - 1][cur_y]!='#'){
                dfs(cur_x-1, cur_y, board, pref, cur);
            }
        }
        if(cur_y > 0){
            if(board[cur_x][cur_y - 1]!='#'){
                dfs(cur_x, cur_y-1, board, pref, cur);
            }
        }
        if(cur_x < board.size()-1){
            if(board[cur_x + 1][cur_y]!='#'){
                dfs(cur_x+1, cur_y, board, pref, cur);
            }
        }
        if(cur_y < board[0].size()-1){
            if(board[cur_x][cur_y + 1]!='#'){
                dfs(cur_x, cur_y+1, board, pref, cur);
            }
        }
        board[cur_x][cur_y] = temp;

    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        PrefixTree* diction = new PrefixTree();
        for(string x : words){
            diction -> insert(x);
        }
        wordsize_ = words.size();
        cout << wordsize_ << endl;
        string temp;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size();j++){
                dfs(i,j,board,diction,temp);
                if(result.size() == words.size()){
                    return result;
                }
            }
        }
        return result;
    }
private:
    int wordsize_; 
};
