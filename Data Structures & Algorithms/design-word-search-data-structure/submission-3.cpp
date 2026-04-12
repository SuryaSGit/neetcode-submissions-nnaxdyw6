class TrieNode{
public:
    unordered_map<char,TrieNode*> vals;
    bool isLeaf;
    TrieNode(){
        isLeaf = false;
    }
};
class WordDictionary {
public:
    WordDictionary() {
        root_ = nullptr;
    }
    
    void addWord(string word) {
        if(root_ == nullptr){
            root_ = new TrieNode();
        }
        TrieNode* cur = root_;
        for(char c : word){
            if(cur->vals.contains(c)){
                cur = cur -> vals[c];
            }
            else{
                cur->vals[c] = new TrieNode();
                cur = cur -> vals[c];
            }
        }
        cur->isLeaf = true;
        
    }
    
    bool search(string word) {
        return dfs(root_, word);
    }
    bool dfs(TrieNode* cur, string word){
        if(cur == nullptr){
            return false;
        }
        if(word.size() == 0){
            if(cur->isLeaf){
                return true;
            }
            return false;
        }
        if(cur -> vals.size() == 0){
            return false;
        }
        cout << "Word: " << word << endl;
        char temp = word[0];
        word = word.substr(1);
        bool result = false;
        if(temp != '.'){
            return dfs(cur->vals[temp],word);
        }
        else{
            for(const auto& pair : cur -> vals){
                result = result || dfs(pair.second,word);
            }
        }
        return result;
    }
private:
    TrieNode* root_;
};
