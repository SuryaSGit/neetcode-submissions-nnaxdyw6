class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int write = m + n - 1;
        int i = m - 1;
        int j = n - 1;
        while(i >= 0 || j >= 0){
            int aval = (i >= 0) ? nums1[i] : INT_MIN;
            int bval = (j >= 0) ? nums2[j] : INT_MIN;
            if(aval > bval){
                nums1[write] = aval;
                i--;
                write--;
            }
            else{
                nums1[write]=bval;
                j--;
                write--;
            }
        }
    }
};