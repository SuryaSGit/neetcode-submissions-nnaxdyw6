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
        return dfs(root_, word, 0);
    }
    bool dfs(TrieNode* cur, string& word, int index){
        if(cur == nullptr){
            return false;
        }
        if(word.size() == index){
            if(cur->isLeaf){
                return true;
            }
            return false;
        }
        if(cur -> vals.size() == 0){
            return false;
        }
        cout << "Word: " << word << endl;
        char temp = word[index];
        bool result = false;
        if(temp != '.'){
            if (cur->vals.find(temp) == cur->vals.end()) {
                return false;
            }
            return dfs(cur->vals[temp],word,index+1);
        }
        else{
            for(const auto& pair : cur -> vals){
                result = result || dfs(pair.second,word,index +1);
            }
        }
        return result;
    }
private:
    TrieNode* root_;
};
