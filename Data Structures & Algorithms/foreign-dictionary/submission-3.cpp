class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        vector<vector<int>> adj(26);
        if(words.size()==1){
            return words[0];
        }
        unordered_set<int> found_chars;
        for(int i = 0; i < words.size() - 1; i++){
            for(char x : words[i]){
                found_chars.insert(x-'a');
            }
            for(char x : words[i+1]){
                found_chars.insert(x-'a');
            }
            if(words[i+1].starts_with(words[i])){
                continue;
            }
            if(words[i].starts_with(words[i+1])){
                return "";
            }
            int min_l = min(words[i].size(), words[i+1].size());
            for(int j = 0; j < min_l; j++){
                if(words[i][j]!=words[i+1][j]){
                    int temp1 = words[i][j]-'a';
                    int temp2 = words[i+1][j]-'a';
                    bool found = false;
                    for(int x : adj[temp1]){
                        if(x == temp2){
                            found = true;
                            break;
                        }
                    }
                    if(!found){
                        adj[temp1].push_back(temp2);
                    }
                    break;
                }
            }
        }
        cout << found_chars.size() << endl;
        vector<int> in_degree(26);
        for(int i = 0; i < 26; i++){
            if(!found_chars.contains(i)){
                in_degree[i] = -1;
            }
            for(int j : adj[i]){
                in_degree[j]++;
            }
        }
        queue<int> to_process;
        for(int i = 0; i < 26; i++){
            if(in_degree[i]==0){
                to_process.push(i);
            }
        }
        string result;
        while(!to_process.empty()){
            int cur = to_process.front();
            to_process.pop();
            for(int j : adj[cur]){
                in_degree[j]--;
                if(in_degree[j]==0){
                    to_process.push(j);
                }
            }
            result = result +static_cast<char>('a' + cur);
        }
        for(int i = 0; i < 26; i++){
            if(in_degree[i] > 0){
                return "";
            }
        }
        return result;
    }
};
