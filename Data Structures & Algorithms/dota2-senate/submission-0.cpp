class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> rs;
        queue<int> ds;
        for(int i = 0; i < senate.size(); i++){
            if(senate[i] == 'R'){
                rs.push(i);
            }
            else{
                ds.push(i);
            }
        }
        int n = senate.size();
        while(rs.size() > 0 && ds.size() > 0){
            int r = rs.front();
            int d = ds.front();
            rs.pop();
            ds.pop();
            if(r < d){
                rs.push(r+ n);
            }
            else{
                ds.push(d+n);
            }
        }
        if(rs.size() == 0){
            return "Dire";
        }
        else{
            return "Radiant";
        }
    }
};