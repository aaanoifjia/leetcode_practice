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
    vector<int> inorderTraversal(TreeNode* root) {
        recursion(root);
        return asw;
    }
private:
    vector<int> asw;
    void recursion(TreeNode *cur){
        if (!cur){
            return;
        }
        if(cur->left){
            recursion(cur->left);
        }
        asw.push_back(cur->val);
        if(cur->right){
            recursion(cur->right);
        }
    }
};