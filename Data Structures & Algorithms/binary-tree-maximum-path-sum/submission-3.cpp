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
    int curmax = INT_MIN;
    int maxPathSum(TreeNode* root) {
        findmax(root);
        return curmax;
    }
    int findmax(TreeNode* subroot){
        if(subroot == nullptr){
            return 0;
        }
        int temp1 = findmax(subroot -> left);
        int temp2 = findmax(subroot -> right);
        int temp3 = subroot -> val;
        if(temp1 > 0){
            temp3 = temp3 + temp1;
        }
        if(temp2 > 0){
            temp3 = temp3 + temp2;
        }
        curmax = max(curmax, temp3);
        if(max(temp1,temp2)<0){
            return subroot -> val;
        }
        return max(temp1,temp2) + subroot -> val;
    }
};
