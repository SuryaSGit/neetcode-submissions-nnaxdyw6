class Solution {
public:
    int findManhattanDistance(vector<int> a, vector<int> b){
        return abs(a[0]-b[0]) + abs(a[1] - b[1]);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int numnodes = points.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> minheap;
        minheap.push({0,0});
        unordered_set<int> visited;
        int total_cost = 0;
        while(visited.size() < numnodes){
            int curnode = minheap.top().second;
            int curcost = minheap.top().first;
            minheap.pop();
            if(visited.contains(curnode)){
                continue;
            }
            visited.insert(curnode);
            total_cost = total_cost + curcost;
            for(int i = 0; i < numnodes; i++){
                if(visited.contains(i)){
                    continue;
                }
                minheap.push({findManhattanDistance(points[curnode],points[i]),i});
            }
        }
        return total_cost;
    }
};
