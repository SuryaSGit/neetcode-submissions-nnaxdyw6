class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n); 
        for(int i = 0; i < flights.size(); i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
            cout << flights[i][0] << " " << flights[i][1] << " " << flights[i][2] << endl;
        }
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> djk;
        djk.push({0,{0,src}});
        unordered_set<int> visited;
        while(djk.size() > 0){
            int cur_cost = djk.top().first;
            int cur_node = djk.top().second.second;
            int num_flights = djk.top().second.first;
            cout << "Cur Node: " << cur_node << endl;
            cout << "Cur Cost: " << cur_cost << endl;
            djk.pop();
            cout << "Num Flights: " << num_flights << endl;
            if(visited.contains(cur_node)){
                continue;
            }
            if(num_flights > k+1){
                continue;
            }
            if(cur_node == dst){
                return cur_cost;
            }
            for(int i = 0; i < adj[cur_node].size(); i++){
                pair<int,int> temp = adj[cur_node][i];
                if(!visited.contains(temp.first)){
                    cout << temp.second << endl;
                    djk.push({cur_cost + temp.second,{num_flights + 1, temp.first}});
                }
            }
        }
        return -1;
    }
};
