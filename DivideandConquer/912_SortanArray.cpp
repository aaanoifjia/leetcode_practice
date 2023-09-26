// BST multiset
class Solution {
public:
  vector<int> sortArray(vector<int>& nums) {
    multiset<int> s(begin(nums), end(nums));
    return {begin(s), end(s)};
  }
};

class Solution {// quickSort might exceed time limit
public:
  vector<int> sortArray(vector<int>& nums) {
      quickSort(nums, 0, nums.size()-1);
      return nums;
  }
private:
    void quickSort(vector<int>& nums, int l, int r){
        if (l >= r) return;
        int p = nums[r];
        int idx = l;
        for (int i = l; i < r; i++){
            if (nums[i] < p){
                swap(nums[i], nums[idx]);
                idx++;
            }
        }
        swap(nums[r], nums[idx]);
        quickSort(nums, l, idx-1);
        quickSort(nums, idx+1, r);
    }
};

