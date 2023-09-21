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
    int maxPathSum(TreeNode* root) {
        asw = root->val;
        traversal(root);
        return asw;
    }
private:
    int asw;
    int traversal(TreeNode* root){
        if (!root) return INT_MIN;
        int left = traversal(root->left);
        int right = traversal(root->right);
        int curmax = max(max(left, 0), max(right,0)) + root->val;
        asw = max(curmax, asw);
        asw = max(asw, max(left, 0) + max(right,0) + root->val);
        return curmax;
    }
};