class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> repeat(26);
        for(int i = 0; i < s.size(); i++){
            repeat[s[i]-'a']=i;
        }
        vector<int> result;
        int curpos = 0;
        int lastpos = 0;
        while(curpos < s.size()){
            for(int i = curpos; i <= lastpos; i++){
                lastpos = max(lastpos,repeat[s[i]-'a']);
            }
            result.push_back(1+lastpos-curpos);
            curpos = lastpos + 1;
            lastpos = curpos;
        }
        return result;
    }
};
