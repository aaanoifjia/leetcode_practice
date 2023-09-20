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
class Solution { // 1. BFS recursion
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) {return asw;}
        vector<TreeNode*> rootLevel;
        rootLevel.push_back(root);
        curLevel(rootLevel);
        return asw;
    }
private:
    vector<vector<int>> asw;
    
    void curLevel(vector<TreeNode*> level){
        vector<int> curValues;
        vector<TreeNode*> nextLevel;
        for(TreeNode* node : level){
            curValues.push_back(node->val);
            if (node->left){nextLevel.push_back(node->left);}
            if (node->right){nextLevel.push_back(node->right);}
        }
        asw.push_back(curValues);
        if (!nextLevel.empty()){curLevel(nextLevel);}
    }
};

class Solution { // 2. BFS while loop, and use swap() to save space
private:
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> asw; 
        if (!root) {return asw;}
        vector<TreeNode*> cur, next;
        cur.push_back(root);
        while (!cur.empty()){
            asw.push_back({});
            for(TreeNode* node : cur){
                asw.back().push_back(node->val);
                if(node->left){next.push_back(node->left);}
                if(node->right){next.push_back(node->right);}
            }
            cur.swap(next); // swap trick!
            next.clear();  // !!
        }
        return asw;
    }
};


class Solution { // dfs

private:
    vector<vector<int>> asw;
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        DFS(root, 0);
        return asw; 
    }
private:
    void DFS(TreeNode* root, int depth){
        if (!root) return; 
        while(depth >= asw.size()) { // size should > indicies by 1
            asw.push_back({}); 
        }
        asw[depth].push_back(root->val);
        DFS(root->left, depth+1);
        DFS(root->right, depth+1);
    }
};