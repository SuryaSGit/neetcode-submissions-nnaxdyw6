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


// First value of preorder is root. So, anything to the left of that in inorder
// is in left subtree. So we can use this to recurse and make subtrees.
// Increment global var tracking updated nodes so far.
class Solution {
public:
    int temp = 0;
    unordered_map<int,int> vals;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++){
            vals[inorder[i]]= i;
        }
        return dfs(preorder,0,inorder.size()-1);
    }
    TreeNode* dfs(vector<int>& preorder, int l, int r){
        if(l > r){
            return nullptr;
        }
        int temp2 = preorder[temp];
        temp++;
        int mid = vals[temp2];
        TreeNode* root = new TreeNode(temp2);
        root -> left = dfs(preorder,l,mid-1);
        root -> right = dfs(preorder,mid+1,r);
        return root;
    }

};
