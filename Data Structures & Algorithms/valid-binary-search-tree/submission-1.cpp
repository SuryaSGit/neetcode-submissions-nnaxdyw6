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
    bool isValidBST(TreeNode* root) {
        return checkvalid(root, INT_MIN, INT_MAX);

    }
    bool checkvalid(TreeNode* subroot, int lb, int ub){
        if(subroot == nullptr){
            return true;
        }
        if(subroot -> val <= lb || subroot -> val >= ub){
            return false;
        }
        bool temp = checkvalid(subroot -> left, lb, subroot -> val);
        return temp && checkvalid(subroot -> right, subroot -> val, ub);
    }
};
