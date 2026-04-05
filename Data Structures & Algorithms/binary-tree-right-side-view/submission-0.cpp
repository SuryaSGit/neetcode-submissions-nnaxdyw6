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

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        addNodes(root, 0, result);
        return result;
    }
    void addNodes(TreeNode* root, int level, vector<int>& vals){
        if(root == nullptr){
            return;
        }
        if(vals.size()==level){
            vals.push_back(root -> val);
        }
        addNodes(root -> right, level + 1, vals);
        addNodes(root -> left, level + 1, vals);
    }
};
