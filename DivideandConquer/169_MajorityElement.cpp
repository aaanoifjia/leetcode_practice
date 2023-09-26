class Solution { //Time: O(n), Space： O(1)
public:
    int majorityElement(vector<int>& nums) {
        int asw = nums.front();
        int count = 0;
        for(int i : nums){
            if (i == asw) count++;
            else if(count-- == 0){
                asw = i;
                count = 1;
            }
        }
        return asw; 
    }
};

class Solution { // sorting base 1- Full sort
public:
    int majorityElement(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};

class Solution { // Sorting 2 average O(n)
public:
    int majorityElement(vector<int>& nums) {
        nth_element(nums.begin(), nums.begin() + nums.size()/2, nums.end());
        return nums[nums.size()/2];
    }
};




