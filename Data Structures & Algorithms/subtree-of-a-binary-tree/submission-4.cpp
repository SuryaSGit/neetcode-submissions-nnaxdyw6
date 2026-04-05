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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr){
            return false;
        }
        bool ans = false;
        ans = isSameTree(root,subRoot);
        if(ans){
            return true;
        }
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr){
            if(q!=nullptr){
                return false;
            }
            return true;
        }
        if(q==nullptr){
            return false;
        }
        if(p->val!=q->val){
            return false;
        }
        bool ans = (isSameTree(p->left,q->left) && isSameTree(p->right,q->right))&&(p->val == q -> val);
        return ans;
    }
};
