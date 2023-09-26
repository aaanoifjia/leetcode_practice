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

enum class State {NONE = 0, COVERED = 1, CAMERA = 2};

class Solution {
public:
    int minCameraCover(TreeNode* root) {
        if (!root) return 0;
        if (cover(root) == State::NONE) asw++;
        returßn asw;
    }
private:
    int asw;
    State cover(TreeNode* root){
        if (!root) return State::COVERED;
        State l = cover(root->left);
        State r = cover(root->right);
        if (l == State::NONE || r == State::NONE){
            asw++;
            return State::CAMERA;
        }
        if(l == State::CAMERA || r == State::CAMERA){
            return State::COVERED;
        }
        return State::NONE; 
    }
};