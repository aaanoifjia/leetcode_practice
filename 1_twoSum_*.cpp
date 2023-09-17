// algorithm
// trick: uses map
// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.

Return true if it is possible. Otherwise, return false.

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> id;
        for(int i = 0; i < nums.size(); i++){   // O()
            id[nums[i]] = i;
        }
        for(int i = 0; i < nums.size(); i++){
            int left = target - nums[i];
            if (id.count(left) && id[left] != i){
                return {i, id[left]};
            }
        }
        return {}; 
    }
};