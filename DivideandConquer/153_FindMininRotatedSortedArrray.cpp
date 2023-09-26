#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        return binSearch(nums, 0, nums.size() - 1);
    }
private:
    int binSearch(vector<int>& nums, int l, int r){
        if (l == r) return nums[l];
        int mid = l + (r - l)/2;
        cout<<l << ' ' << mid << ' '<< r << '\n';
        int v = nums[mid];
        if (nums[l] <= v && v <= nums[r]) return nums[l];
        if (nums[l] > v) return binSearch(nums, l, mid);
        return binSearch(nums, mid + 1, r);
    }
};

int main(){
    Solution s;
    vector<int> vct;
    vct.push_back(3);
    vct.push_back(4);
    vct.push_back(5);
    vct.push_back(1);
    vct.push_back(2);

    cout << s.findMin(vct);
    return 0;
}
