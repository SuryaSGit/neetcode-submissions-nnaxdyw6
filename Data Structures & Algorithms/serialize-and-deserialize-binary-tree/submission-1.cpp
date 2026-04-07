/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr){
            return "";
        }
        queue<TreeNode*> temp;
        temp.push(root);
        string result;
        while(!temp.empty()){
            TreeNode* temp1 = temp.front();
            if(temp1 == nullptr){
                temp.pop();
                result = result + "n,";
            }
            else{
                temp.pop();
                temp.push(temp1 -> left);
                temp.push(temp1 -> right);
                result = result + (to_string(temp1 -> val));
                result = result + ',';
            }
        }
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0){
            return nullptr;
        }
        int count = 0;
        while(data[count]!=','){
            count++;
        }
        TreeNode* root = new TreeNode(stoi(data.substr(0,count)));
        count++;
        queue<TreeNode*> temp;
        temp.push(root);
        while(!temp.empty()){
            if(count > data.size()){
                break;
            }
            TreeNode* cur = temp.front();
            string current_data;
            int find_comma = count;
            while(data[find_comma]!=','){
                find_comma++;
            }
            current_data = data.substr(count,find_comma-count);
            if(current_data != "n"){
                cur -> left = new TreeNode(stoi(current_data));
                temp.push(cur -> left);
            }
            count=find_comma + 1;
            find_comma = count;
            while(data[find_comma]!=','){
                find_comma++;
            }
            current_data = data.substr(count,find_comma-count);
            if(current_data != "n"){
                cur -> right = new TreeNode(stoi(current_data));
                temp.push(cur -> right);
            }
            temp.pop();
            count = find_comma + 1;
        }
        return root;
    }
};
