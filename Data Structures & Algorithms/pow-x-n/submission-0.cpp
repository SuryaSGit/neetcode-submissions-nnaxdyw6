class Solution {
public:
    double myPow(double x, int n) {
        double temp = x;
        if(n > 0){
            for(int i = 0; i < n - 1; i++){
                temp = temp * x;
            }
        }
        else if(n == 0){
            return 1;
        }
        else{
            for(int i = 0; i < 1 + -n; i++){
                temp = temp / x;
            }
        }
        return temp;
    }
};
