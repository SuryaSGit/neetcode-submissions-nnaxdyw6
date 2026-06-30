class Solution {
public:
    int minOperations(vector<string>& logs) {
        int away_from_main = 0;
        for(int i = 0; i < logs.size(); i++){
            if(logs[i][1] == '.'){
                away_from_main--;
                if(away_from_main < 0){
                    away_from_main = 0;
                }
            }
            else if(logs[i][logs[i].size()-1] == '/' && logs[i][0] != '.'){
                away_from_main++;
            }
        }
        return away_from_main;
    }
};