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
    bool isBalanced(TreeNode* root) {
        bal_ = true;
        int temp = findBal(root);
        return bal_;
    }
    int findBal(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int x = findBal(root -> left);
        int y = findBal(root->right);
        if(abs(x-y) > 1){
            bal_ = false;
        }
        return 1 + max(x,y);
    }
private:
    bool bal_;
};
