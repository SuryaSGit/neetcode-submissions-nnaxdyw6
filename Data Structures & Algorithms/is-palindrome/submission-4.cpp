class Solution {
public:
    bool isPalindrome(string s) {
        int a = 0;
        int b = s.size()-1;
        while(a < b){
            while(s[a]<48 || s[a] > 122 || (s[a] > 90 && s[a] < 97)||(s[a] > 57 && s[a] < 65)){
                a++;
            }
            while(s[b]<48 || s[b] > 122 || (s[b] > 90 && s[b] < 97)||(s[b] > 57 && s[b] < 65)){
                b--;
            }
            
            s[a] = tolower(s[a]);
            s[b] = tolower(s[b]);
            cout << s[a] << s[b] << endl;
            if(a>b){
                return true;
            }
            if(s[a]!=s[b]){
                return false;
            }
            a++;
            b--;
        }
        return true;
    }
};
