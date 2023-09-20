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
    int sumNumbers(TreeNode* root) {
        return DFS(root, 0);
    }
private:
    int DFS(TreeNode* root, int cur){
        if(!root) return 0;
        if (!root->left && !root->right) return cur*10 + root->val;
        cur = cur*10 + root->val;
        return DFS(root->left, cur) + DFS(root->right, cur);
    }   
};