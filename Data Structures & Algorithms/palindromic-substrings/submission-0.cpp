class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int p1 = 0;
        int p2 = 0;
        int count = 0;
        for(int start = 0; start < n; start++){
            p1 = start;
            p2 = start;
            while(p1 >= 0 && p2 < n){
                if(s[p1] != s[p2]){
                    break;
                }
                count++;
                p1--;
                p2++;
            }
            p1 = start;
            p2 = start+1;
            while(p1 >= 0 && p2 < n){
                if(s[p1] != s[p2]){
                    break;
                }
                count++;
                p1--;
                p2++;
            }
        }
        return count;
    }
};
