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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> temp;
        buildTraversal(root,temp,k);
        return temp[temp.size()-1];
    }
    void buildTraversal(TreeNode* subroot, vector<int>& vals, int&k){
        if(subroot == nullptr || k == 0){
            return;
        }
        buildTraversal(subroot -> left, vals,k);
        if(k!= 0){
            vals.push_back(subroot -> val);
            k--;
        }
        if (k > 0){
            buildTraversal(subroot -> right, vals,k);
        }
    }
};
