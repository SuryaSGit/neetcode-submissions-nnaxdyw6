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
    int diameterOfBinaryTree(TreeNode* root) {
        pair<int,int> result = findDia(root);
        return result.second;
    }
    pair<int,int> findDia(TreeNode* root){
        pair<int,int> result;
        if(root == nullptr){
            result.first = 0;
            result.second = 0;
            return result;
        }
        pair<int,int> left_res = findDia(root -> left);
        pair<int,int> right_res = findDia(root -> right);
        result.first = 1 + max(left_res.first,right_res.first);
        result.second = max(left_res.second,right_res.second);
        result.second = max(result.second, left_res.first + right_res.first);
        return result;
    }
};
