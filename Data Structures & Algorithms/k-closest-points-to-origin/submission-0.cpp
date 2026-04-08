class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto comp = [](const vector<int>& a, const vector<int>& b) {
            return a[0]*a[0] + a[1]*a[1] > b[0]*b[0] + b[1]*b[1];
        };
        std::priority_queue<vector<int>,vector<vector<int>>, decltype(comp)> minHeap(comp);
        for(int i = 0; i < points.size(); i++){
            minHeap.push(points[i]);
        }
        vector<vector<int>>result;
        for(int i = 0; i < k; i++){
            result.push_back(minHeap.top());
            minHeap.pop();
        }
        return result;
    }
};
