class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> vals;
        for(int i = 0; i < position.size(); i++){
            pair<int,int> temp(position[i],speed[i]);
            vals.push_back(temp);
        }
        sort(vals.begin(), vals.end(), greater<pair<int, int>>());
        stack<double> v;
        for(int i = 0; i < vals.size(); i++){
            double temp2 = 1.0*(target-vals[i].first)/vals[i].second;
            if(v.empty()){
                v.push(temp2);
            }
            else{
                if(temp2 > v.top()){
                    v.push(temp2);
                }
            }
        }
        return v.size();
    }
};
