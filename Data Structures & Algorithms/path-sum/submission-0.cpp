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
    bool dfs(TreeNode* root, int targetSum, int curSum){
        if(root == nullptr){
            return false;
        }
        curSum += root -> val;
        if(curSum == targetSum && root->left == nullptr && root -> right == nullptr){
            return true;
        }
        return dfs(root->left,targetSum,curSum) || dfs(root->right,targetSum,curSum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return dfs(root,targetSum,0);
    }
};