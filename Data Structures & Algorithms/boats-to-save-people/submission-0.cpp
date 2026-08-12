class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int light = 0;
        int heavy = people.size()-1;
        int count = 0;
        while(light <= heavy){
            if(light == heavy){
                return count+1;
            }
            if(people[heavy] + people[light] <= limit){
                heavy--;
                light++;
                count++;
            }
            else{
                heavy--;
                count++;
            }
        }
        return count;
    }
};