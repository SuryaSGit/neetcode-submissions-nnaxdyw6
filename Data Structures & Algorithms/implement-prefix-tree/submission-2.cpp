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
