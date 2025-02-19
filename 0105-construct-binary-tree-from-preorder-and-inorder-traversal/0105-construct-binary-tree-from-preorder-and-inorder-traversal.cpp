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
    void fillMap(unordered_map<int, int> &mapp, vector<int> &inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            int element = inorder[i];
            int index = i;
            mapp[element] = index;
        }
    }

    TreeNode* solve(vector<int> &preorder, vector<int> &inorder, int &preorderIndex, int inorderStart, int inorderEnd, int size, unordered_map<int, int> &mapp) {
        if (preorderIndex >= size || inorderEnd < inorderStart) {
            return nullptr;
        }

        // node
        int element = preorder[preorderIndex];
        TreeNode* root = new TreeNode(element);
        preorderIndex++;

        int inorderIndex = mapp[element];

        // left
        root->left = solve(preorder, inorder, preorderIndex, inorderStart, inorderIndex - 1, size, mapp);

        // right
        root->right = solve(preorder, inorder, preorderIndex, inorderIndex + 1, inorderEnd, size, mapp);

        return root;
    }

 
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
         if (preorder.empty()) {
            return nullptr;
        }

        int size = inorder.size();
        int preorderIndex = 0;
        int inorderStart = 0;
        int inorderEnd = inorder.size() - 1;
        unordered_map<int, int> mapp;
        fillMap(mapp, inorder);

        TreeNode* ans = solve(preorder, inorder, preorderIndex, inorderStart, inorderEnd, size, mapp);
        return ans;
    }
};