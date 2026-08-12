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
    unordered_map<TreeNode*,int> dp;
    int dfs(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        if(dp.contains(root)){
            return dp[root];
        }
        int stealnow = root -> val;
        int no_steal = dfs(root->left) + dfs(root->right);
        int bestchild = 0;
        if(root -> left != nullptr){
            bestchild = dfs(root->left->left) +  dfs(root -> left -> right);
        }
        if(root -> right != nullptr){
            bestchild = bestchild + dfs(root->right->left) + dfs(root -> right -> right);
        }
        dp[root] = max(stealnow+bestchild,no_steal);
        return max(stealnow+bestchild,no_steal);
    }
    int rob(TreeNode* root) {
        return dfs(root);
    }
};