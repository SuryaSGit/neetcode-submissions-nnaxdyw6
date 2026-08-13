class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int wordpointer = 0;
        string cur_num = "";
        for(int a = 0; a < abbr.size(); a++){
            if(abbr[a]-'0' <= 9){
                cur_num += abbr[a];
                continue;
            }
            if(cur_num.size() > 0){
                if(cur_num[0] == '0'){
                    return false;
                }
                wordpointer += stoi(cur_num);
                cur_num = "";
            }
            if(wordpointer >= word.size()){
                return false;
            }
            if(word[wordpointer]!=abbr[a]){
                return false;
            }
            wordpointer++;
        }
        if(cur_num.size() > 0){
            wordpointer += stoi(cur_num);
        }
        if(wordpointer == word.size()){
            return true;
        }
        return false;
    }
};