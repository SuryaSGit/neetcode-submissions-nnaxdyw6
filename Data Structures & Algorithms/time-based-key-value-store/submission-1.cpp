class TimeMap {
public:
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        vals_[key].push_back(value);
        vals2_[key].push_back(timestamp);
        cout << "LINE 37" << endl;
    }
    
    string get(string key, int timestamp) {
        cout << "HI" << endl;
        vector<int> temp = vals2_[key];
        if(temp.size()==0){
            return "";
        }
        if(temp[0] > timestamp){
            return "";
        }
        int low = 0;
        int high = temp.size()-1;
        int mid = (low+high)/2;
        int ans = -1;
        while(low <= high){
            if(temp[mid]==timestamp){
                ans = mid;
                break;
            }
            if(temp[mid] > timestamp){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
            mid = (low + high) / 2;
        }
        if(ans == -1){
            ans = mid;
        }
        cout << "LINE 37" << endl;
        return vals_[key][ans]; 
    }
private:
    unordered_map<string,vector<string>> vals_;
    unordered_map<string,vector<int>> vals2_;
};
