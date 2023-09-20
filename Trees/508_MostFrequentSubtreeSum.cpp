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
private:
    vector<int> asw;
    int max, sum;
    unordered_map<int, int> count;
    int traversal(TreeNode* root){
        if (!root) return 0;
        sum = root->val + traversal(root->left) + traversal(root->right);
        count[sum]++;
        int freq = count[sum];
        if (freq == max){
            asw.push_back(sum);
        }
        if(freq > max){
            max++;
            asw.clear();
            asw.push_back(sum);
        }
        return sum;
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        traversal(root);a
        return asw; 
    }
    
};