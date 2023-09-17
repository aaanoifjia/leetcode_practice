
// Time: O(n^2), Space: O(n)
// Description: Given an integer array nums, return all the triplets 
// [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, 
// and nums[i] + nums[j] + nums[k] == 0.
// Notice that the solution set must not contain duplicate triplets.

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        unordered_map<int, int> m;
        for (int n : nums) ++m[n]; 
        int n = nums.size();
        vector<vector<int>> asw; 
        for (int i = 0; i < n ; ++i){
            if (i && nums[i-1] == nums[i]) continue;
            for (int j = i + 1; j < n; ++j){
                if (j - 1 != i && nums[j-1] == nums[j]) continue;
                int z = 0 - nums[j] - nums[i];
                if (z < nums[j]) continue;
                if (!m.count(z)) continue;
                if (m[z] > (nums[j] == z) + (nums[i] == z)){ // trick: checks num of z
                    asw.push_back({nums[i], nums[j], z});
                }
            }
        }
        return asw; 

    }
};