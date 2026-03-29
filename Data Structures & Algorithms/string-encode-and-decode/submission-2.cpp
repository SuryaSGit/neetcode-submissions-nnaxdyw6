class Solution {
public:
    string encode(vector<string>& strs) {
        string result;
        // Optimization: One allocation instead of many
        size_t total_len = 0;
        for (const string& s : strs) total_len += s.size() + 10; 
        result.reserve(total_len);

        for (const string& s : strs) {
            // result += is MUCH faster than result = result + ...
            result += to_string(s.size());
            result += '#';
            result += s;
        }
        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;
        while (i < s.size()) {
            // Use find() to jump straight to the delimiter
            size_t found = s.find('#', i);
            
            // Extract length and move i to the start of the actual string
            int len = stoi(s.substr(i, found - i));
            i = found + 1;
            
            result.push_back(s.substr(i, len));
            i += len;
        }
        return result;
    }
};