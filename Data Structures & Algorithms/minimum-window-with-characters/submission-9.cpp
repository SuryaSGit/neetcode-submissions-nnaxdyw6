class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size() && s!=t){
            return "";
        }
        if(s==t){
            return s;
        }
        string curmin = s;
        vector<int> a(150);
        vector<int> b(150);
        for(int i = 0; i < t.size(); i++){
            a[t[i]-'A']++;
        }
        bool changed = false;
        int curpos = 0;
        for(int i = 0; i < s.size(); i++){
            b[s[i]-'A']++;
            bool mogged = true;
            for(int j = 0; j < a.size(); j++){
                if(b[j] < a[j]){
                    mogged = false;
                    break;
                }
            }
            changed = mogged;
            bool fixed = false;
            while(mogged){
                if(curpos == i){
                    fixed = true;
                    break;
                }
                b[s[curpos]-'A']--;
                curpos++;
                if(b[s[curpos-1]-'A'] < a[s[curpos-1]-'A']){
                    mogged = false;
                    fixed = true;
                    curpos--;
                    b[s[curpos]-'A']++;
                }
            }
            if(fixed){
                cout << curpos << endl;
                cout << i << endl;
                cout << curmin.size() << endl;
            }
            if((i-curpos) < curmin.size()){
                if(fixed){
                    curmin = s.substr(curpos,1+i-curpos);  
                }
            }
        }
        if(!changed){
            return "";
        }
        return curmin;
    }
};
