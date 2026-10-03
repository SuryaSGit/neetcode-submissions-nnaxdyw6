class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> pascals(rowIndex + 1);
        vector<int> start;
        start.push_back(1);
        pascals[0] = start;
        for(int i = 1; i <= rowIndex; i++){
            vector<int> temp = pascals[i-1];
            vector<int> new_row;
            new_row.push_back(temp[0]);
            for(int i = 0; i < temp.size() - 1; i++){
                new_row.push_back(temp[i] + temp[i + 1]);
            }
            new_row.push_back(temp[temp.size()-1]);
            pascals[i] = new_row;
        }
        return pascals[rowIndex];
    }
};