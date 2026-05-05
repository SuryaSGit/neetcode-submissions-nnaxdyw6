class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int,int> count;
        for(int i : hand){
            count[i]++;
        }
        if(hand.size()%groupSize!=0){
            return false;
        }
        int numhands = hand.size()/groupSize;
        for(int i = 0; i < hand.size(); i++){
            int temp = hand[i];
            while(count[temp-1] > 0){
                temp--;
            }
            if(count[temp] > 0){
                for(int j = 0; j < groupSize; j++){
                    if(count[temp+j] == 0){
                        return false;
                    }
                    count[temp+j]--;
                }
                numhands--;
                if(numhands == 0){
                    return true;
                }
            } 
        }
        return false;
    }
};
