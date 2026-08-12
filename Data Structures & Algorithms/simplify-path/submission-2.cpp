class Solution {
public:
    string simplifyPath(string path) {
        stack<string> dir_names;
        int pos = 0;
        while(pos < path.size()){
            while(pos < path.size() && path[pos] == '/'){
                pos++;
            }
            if(pos == path.size()){
                break;
            }
            if(path[pos] == '.' && (pos+1 == path.size() || path[pos+1] == '/')){
                pos++;
                continue;
            }
            if(path[pos] == '.' && path[pos+1] == '.' && (pos+2 == path.size() || path[pos + 2] == '/')){
                pos = pos + 2;
                if(dir_names.empty()){
                    continue;
                }
                dir_names.pop();
                continue;
            }
            string cur_name = "";
            while(pos < path.size() && path[pos] != '/'){
                cur_name = cur_name + path[pos];
                pos++;
            }
            dir_names.push(cur_name);
        }
        string res;
        stack<string> temp;
        while(!dir_names.empty()){
            temp.push(dir_names.top());
            dir_names.pop();
        }
        while(!temp.empty()){
            res = res + '/';
            res = res + temp.top();
            cout << temp.top() << endl;
            temp.pop();
        }
        if(res.size()==0){
            return "/";
        }
        return res;
    }
};