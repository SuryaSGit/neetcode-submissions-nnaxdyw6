class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        set<int> temp;
        for(int i = 0; i < arr2.size(); i++){
            temp.insert(arr2[i]);
        }
        vector<int> result;
        for(int i = 0; i < arr2.size(); i++){
            for(int j = 0; j < arr1.size(); j++){
                if(arr1[j]==arr2[i]){
                    result.push_back(arr1[j]);
                }
            }
        }
        vector<int> temp2;
        for(int i = 0; i < arr1.size(); i++){
            if(!temp.contains(arr1[i])){
                temp2.push_back(arr1[i]);
            }
        }
        sort(temp2.begin(),temp2.end());
        for(int i = 0; i < temp2.size(); i++){
            result.push_back(temp2[i]);
        }
        return result;



    
    }
};