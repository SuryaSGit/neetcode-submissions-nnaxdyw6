class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> vals2(26);
        for(int i = 0; i < tasks.size(); i++){
            vals2[tasks[i]-'A']++;
        }
        priority_queue<int,vector<int>,less<int>> vals;
        queue<pair<int,int>> cooldown;
        for(int i = 0; i < 26; i++){
            if(vals2[i] > 0){
                vals.push(vals2[i]);   
            }
        }
        int count = 0;
        while(!vals.empty() || !cooldown.empty()){
            count++;
            if(!vals.empty()){
                int temp = vals.top();
                vals.pop();
                temp--;
                if(temp > 0){
                    cooldown.push({temp,count + n});
                }
            }
            while(!cooldown.empty() && cooldown.front().second <= count){
                vals.push(cooldown.front().first);
                cooldown.pop();
            }
        }
        return count;
    }
};
