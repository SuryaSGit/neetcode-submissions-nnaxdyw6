class Solution {
public:

    string encode(vector<string>& strs) {
        string result;
        string temp;
        for(int i = 0; i < strs.size(); i++){
            temp = "";
            temp += to_string(strs[i].size())+"#";
            temp += strs[i];
            result += temp;
        }
        return result;
    }

    vector<string> decode(string s) {
        int cur = 0;
        vector<string>result;
        string cur_num = "";
        int length = 0;
        string temp;
        while(cur < s.size()){
            cur_num = "";
            while(s[cur]!='#'){
                cur_num += s[cur];
                cur++;
            }
            length = stoi(cur_num);
            cur++;
            temp = s.substr(cur,length);
            result.push_back(temp);
            cur += length;
        }
        return result;
    }
};
