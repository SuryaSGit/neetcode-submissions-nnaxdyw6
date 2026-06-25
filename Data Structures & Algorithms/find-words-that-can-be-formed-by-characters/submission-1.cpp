class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> temp(26);
        for(int i = 0; i < chars.size(); i++){
            temp[chars[i]-'a']++;
        }
        int sum = 0;
        for(int i = 0; i < words.size(); i++){
            vector<int> temp2(26);
            for(int j = 0; j < words[i].size(); j++){
                temp2[words[i][j]-'a']++;
            }
            bool flag = true;
            for(int j = 0; j < 26; j++){
                if(temp2[j] > temp[j]){
                    flag = false;
                }
            }
            if(flag){
                sum = sum + words[i].size();
            }
        }
        return sum;
    }
};