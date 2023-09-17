// 1. O(nlog n)
// counts num of each elt, uses map
// Description: Given an array of integers nums and a positive integer k, 
// check whether it is possible to divide this array into sets of k consecutive numbers.

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if (nums.size() % k){ return false; }

        map<int, int> m; 
        for (int num : nums) ++m[num]; // // O(nlog n) 

        while(m.size()){ // O(n) each elt is visited once
            auto it = m.begin();
            int head = it->first;   
            for (int i = 0; i < k; ++i){
                if (it->first != head + i) return false; 
                if (--(it->second) == 0) m.erase(it);
                ++it;
                
            }
        }
    return true;
    }
};


