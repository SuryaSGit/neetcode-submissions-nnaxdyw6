class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool first_match = false;
        bool second_match = false;
        bool third_match = false;
        for(int i = 0; i < triplets.size(); i++){
            if(triplets[i][0] == target[0]){
                if(triplets[i][1] <= target[1] && triplets[i][2] <= target[2]){
                    first_match = true;
                }
            }
            if(triplets[i][1] == target[1]){
                if(triplets[i][0] <= target[0] && triplets[i][2] <= target[2]){
                    second_match = true;
                }
            }
            if(triplets[i][2] == target[2]){
                if(triplets[i][1] <= target[1] && triplets[i][0] <= target[0]){
                    third_match = true;
                }
            }
        }
        return (first_match && second_match && third_match);
    }
};
