class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // Use a vector as a stack for better cache locality
        vector<int> st;
        st.reserve(tokens.size()); 

        for (const string& s : tokens) {
            // Check if it's an operator (length 1 and not a digit)
            if (s.size() == 1 && !isdigit(s[0])) {
                int rhs = st.back(); st.pop_back();
                int lhs = st.back(); st.pop_back();
                
                if (s[0] == '+') st.push_back(lhs + rhs);
                else if (s[0] == '-') st.push_back(lhs - rhs);
                else if (s[0] == '*') st.push_back(lhs * rhs);
                else st.push_back(lhs / rhs);
            } else {
                st.push_back(stoi(s));
            }
        }
        return st.back();
    }
};