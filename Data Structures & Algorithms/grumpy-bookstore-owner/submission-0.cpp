class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int grumpies = 0;
        int res = 0;
        int sats = 0;
        for(int i = 0; i < grumpy.size(); i++){
            if(grumpy[i]){
                grumpies+=customers[i];
            }
            else{
                sats+=customers[i];
            }
            if(i >= minutes && grumpy[i-minutes]){
                grumpies-=customers[i-minutes];
            }
            res = max(res,grumpies);
        }
        return sats + res;
    }
};