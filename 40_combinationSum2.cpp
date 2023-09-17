// dfs, set.insert()
// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

// Each number in candidates may only be used once in the combination.

// Note: The solution set must not contain duplicate combinations.




class Solution{
    public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target){
        set<vector<int>> asw;
        std::sort(candidates.begin(), candidates.end());
        vector<int> cur;
        dfs(cur, target, 0, candidates, asw);
        return vector<vector<int>>(asw.begin(), asw.end());
    }
    private:
    void dfs(vector<int>& cur, int target, int idx, vector<int>& candidates, set<vector<int>>& asw){
        if (target == 0) {
                asw.insert(cur);
                return;
            }
        for(int i = idx; i < candidates.size(); ++i){
            int x = candidates[i]; 
            if (x > target) return;
            cur.push_back(x); 
            dfs(cur, target - x, i + 1, candidates, asw); 
            cur.pop_back();
        }
    }
};