class Solution {
public:
    string increment(string input, int pos, bool inc){
        if(inc){
            if(input[pos] == '9'){
                input[pos] = '0';
            }
            else{
                input[pos]++;
            }
        }
        else{
            if(input[pos] == '0'){
                input[pos] = '9';
            }
            else{
                input[pos]--;
            }
        }
        return input;
    }
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deads;
        for(string cur : deadends){
            deads.insert(cur);
        }
        if(deads.contains("0000")){
            return -1;
        }
        unordered_set<string> visited;
        queue<pair<int,string>> to_process;
        to_process.push({0,"0000"});
        while(!to_process.empty()){
            string cur = to_process.front().second;
            int cur_steps = to_process.front().first;
            if(cur == target){
                return to_process.front().first;
            }
            to_process.pop();
            for(int i = 0; i < 4; i++){
                int digit = cur[i] - '0';
                int target_digit = target[i] - '0';
                string up = increment(cur,i,true);
                string low = increment(cur,i,false);
                if(!deads.contains(up) && !visited.contains(up)){
                    to_process.push({cur_steps+1,up});
                    visited.insert(up);
                }
                if(!deads.contains(low) && !visited.contains(low)){
                    to_process.push({cur_steps + 1,low});
                    visited.insert(low);
                }
            }
        } 
        return -1;
    }
};