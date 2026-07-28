class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> cur_words;
        vector<string> res;
        int cur_size = 0;
        for(int i = 0; i < words.size(); i++){
            if(cur_size+words[i].size() > maxWidth){
                cur_words[cur_words.size()-1].pop_back();
                cur_size--;
                res.push_back(process(cur_words,cur_size,maxWidth));
                cur_words.clear();
                cur_words.push_back(words[i] + ' ');
                cur_size = words[i].size()+1;
            }
            else{
                cur_words.push_back(words[i] + ' ');
                cur_size = cur_size + words[i].size() + 1;
            }
        }
        string temp;
        for(int i = 0; i < cur_words.size(); i++){
            temp = temp + cur_words[i];
        }
        temp.pop_back();
        for(int i = temp.size(); i < maxWidth; i++){
            temp.push_back(' ');
        }
        res.push_back(temp);
        return res;
    }
    string process(vector<string> words, int cursize, int maxwidth){
        if(words.size() == 1){
            string temp = words[0];
            while(temp.size() < maxwidth){
                temp.push_back(' ');
            }
            return temp;
        }
        int numspaces = maxwidth - cursize;
        string res;
        cout << maxwidth << cursize << endl;
        int size = words.size()-1;
        for(int i = 0; i < numspaces; i++){
            int cur = i%size;
            words[cur].push_back(' ');
        }
        for(int i = 0; i < words.size(); i++){
            res = res + words[i];
        }
        cout << res.size() << endl;
        return res;
    }
};