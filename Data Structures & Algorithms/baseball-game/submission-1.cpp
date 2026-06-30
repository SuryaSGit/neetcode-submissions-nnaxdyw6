class Solution {
public:
    int calPoints(vector<string>& operations) {
        int sum = 0;
        stack<int> scores;
        for(int i = 0; i < operations.size(); i++){
            if(operations[i] == "+"){
                int temp1 = scores.top();
                scores.pop();
                int temp2 = scores.top();
                scores.push(temp1);
                sum = sum + temp1 + temp2;
                scores.push(temp1 + temp2);
            }
            else if(operations[i] == "D"){
                int temp = scores.top() * 2;
                sum = sum + temp;
                scores.push(temp);
            }
            else if(operations[i]=="C"){
                sum = sum - scores.top();
                scores.pop();
            }
            else{
                scores.push(stoi(operations[i]));
                sum = sum + stoi(operations[i]);
            }
        }
        return sum;
    }
};