class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int high = 0;
        for(int i = 0; i < piles.size(); i++){
            high = max(high,piles[i]);
        }
        int low = 1;
        int mid = (low + high)/2;
        while(low <= high){
            int hours = 0; 
            for(int i = 0; i < piles.size(); i++){
                hours += (piles[i] + mid - 1) / mid;
            }
            if(hours <= h){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
            mid = (low + high)/2;
            if(low > mid){
                mid = low;
            }
        }
        return mid;
    }
};
