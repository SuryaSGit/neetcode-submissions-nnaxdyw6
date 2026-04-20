class Solution {
public:
    vector<string> result;
    void dfs(vector<string> curpath, string curloc, unordered_map<string,int>& enc, vector<vector<int>>& adj, int& numticks, vector<string>& dec){
        cout << "Cur Loc: " << curloc << endl;
        if(curpath.size() == numticks + 1){
            result = curpath;
            return;
        }
        if(result.size() > 0){
            return;
        }
        else{
            for(int j = 0; j < adj[enc[curloc]].size(); j++){
                int i = adj[enc[curloc]][j];
                if(i == enc[curloc]){
                    continue;
                }
                if(i >= 0){
                    cout << "Next Possible: " << dec[i] << endl;
                    curpath.push_back(dec[i]);
                    adj[enc[curloc]][j] = -1;
                    dfs(curpath,dec[i],enc,adj,numticks,dec);
                    curpath.pop_back();
                    adj[enc[curloc]][j] = i;
                }
            }
        }
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> airports;
        unordered_set<string> foundalr;
        for(int i = 0; i < tickets.size(); i++){
            if(!foundalr.contains(tickets[i][0])){
                airports.push_back(tickets[i][0]);
                foundalr.insert(tickets[i][0]);
            }
            if(!foundalr.contains(tickets[i][1])){
                airports.push_back(tickets[i][1]);
                foundalr.insert(tickets[i][1]);
            }
        }
        vector<vector<int>> adj(airports.size());
        sort(airports.begin(),airports.end());
        unordered_map<string,int> enc;
        for(int i = 0; i < airports.size(); i++){
            enc[airports[i]]=i;
        }
        for(int i = 0; i < tickets.size(); i++){
            adj[enc[tickets[i][0]]].push_back(enc[tickets[i][1]]);
            sort(adj[enc[tickets[i][0]]].begin(),adj[enc[tickets[i][0]]].end());
        }
        for(int i = 0; i < adj.size(); i++){
            cout << "Current Location: " << airports[i] << endl;
            for(int j : adj[i]){
                cout << airports[j] << endl;
            }
        }
        vector<string> path;
        path.push_back("JFK");
        int k = tickets.size();
        dfs(path,"JFK",enc,adj,k,airports);
        return result;
    }
};
