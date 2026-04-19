class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,vector<string>> adj;
        bool found = false;
        bool begin_word_in = false;
        int word_length = beginWord.size();
        for(string x : wordList){
            if(x == beginWord){
                begin_word_in=true;
            }
        }
        if(!begin_word_in){
            wordList.push_back(beginWord);
        }
        for(int i = 0; i < wordList.size(); i++){
            string a = wordList[i];
            if(a==endWord){
                found = true;
            }
            for(int j = i; j < wordList.size(); j++){
                string b = wordList[j];
                int num_dif = 0;
                for(int k = 0; k < word_length; k++){
                    if(a[k]!=b[k]){
                        num_dif++;
                    }
                    if(num_dif > 1){
                        break;
                    }
                }
                if(num_dif==1){
                    adj[a].push_back(b);
                    adj[b].push_back(a);
                }
            }
        }
        if(!found){
            return 0;
        }
        unordered_set<string> visited;
        visited.insert(beginWord);
        queue<pair<string,int>> to_search;
        to_search.push({beginWord,1});
        while(!to_search.empty()){
            string cur = to_search.front().first;
            int cur_level = to_search.front().second;
            to_search.pop();
            for(string i : adj[cur]){
                if(!visited.contains(i)){
                    to_search.push({i,cur_level+1});
                    visited.insert(i);
                    if(i==endWord){
                        return cur_level+1;
                    }
                }
            }
        }
        return 0;
    }
};
