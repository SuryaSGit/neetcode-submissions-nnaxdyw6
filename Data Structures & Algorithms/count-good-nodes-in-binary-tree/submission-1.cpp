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
    int goodNodes(TreeNode* root) {
        return goodNodes(root,INT_MIN);
    }
    int goodNodes(TreeNode* subroot, int curmax){
        if(subroot == nullptr){
            return 0;
        }
        int result = 0;
        if(subroot -> val >= curmax){
            curmax = subroot -> val;
            result++;
        }
        result = result + goodNodes(subroot -> left, curmax);
        result = result + goodNodes(subroot -> right, curmax);
        return result;
    }
};
