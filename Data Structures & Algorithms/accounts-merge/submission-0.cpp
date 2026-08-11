class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string,vector<int>> email_to_account;
        for(int i = 0; i < accounts.size(); i++){
            vector<string> cur = accounts[i];
            for(int j = 1; j < cur.size(); j++){
                email_to_account[cur[j]].push_back(i);
            }
        }
        vector<vector<string>> res;
        unordered_set<string> visited;
        for(const auto& pair : email_to_account){
            string cur_name = accounts[pair.second[0]][0];
            queue<string> bfs;
            vector<string> cur_emails;
            if(!visited.contains(pair.first)){
                bfs.push(pair.first);
                visited.insert(pair.first);
                cur_emails.push_back(cur_name);
                cur_emails.push_back(pair.first);
            }
            while(!bfs.empty()){
                string cur = bfs.front();
                bfs.pop();
                for(int i : email_to_account[cur]){
                    for(int j = 1; j < accounts[i].size(); j++){
                        if(!visited.contains(accounts[i][j])){
                            bfs.push(accounts[i][j]);
                            visited.insert(accounts[i][j]);
                            cur_emails.push_back(accounts[i][j]);
                        }
                    }
                }
            }
            if(cur_emails.size() > 0){
                sort(cur_emails.begin()+1,cur_emails.end());
                res.push_back(cur_emails);
            }
        }
        return res;
    }
};