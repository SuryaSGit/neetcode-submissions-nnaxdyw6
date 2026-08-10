class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> alr_seen;
        int cur = n;
        while(!alr_seen.contains(1)){
            if(alr_seen.contains(cur)){
                return false;
            }
            alr_seen.insert(cur);
            int temp = 0;
            string cur_num = to_string(cur);
            for(char x : cur_num){
                temp = temp + ((x-'0') * (x-'0'));
            }
            cur = temp;
            cout<<cur << endl;
        }
        return true;
    }
};
