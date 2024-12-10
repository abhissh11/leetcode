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

    int ans = INT_MAX;
    int pre_val = INT_MAX;
    void func( TreeNode *root){
        if(root==NULL) return;
        func(root->left);
        ans= min(ans, abs(root->val - pre_val));
        pre_val = root->val;
        func(root->right);
    }
    
    int getMinimumDifference(TreeNode* root) {
        func(root);
        return ans;
    }
};