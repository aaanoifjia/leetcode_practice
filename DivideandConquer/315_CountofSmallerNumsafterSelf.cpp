class FenwickTree {
    private:
        vector<int> sums_;
        static inline int lowbit(int x) { return x & (-x);}
    public:
        FenwickTree(int s): sums_(s+1, 0){} // first node is always 0; 
        
        // add val to all notes along
        void update(int i, int delta){
            while (i < sums_.size()){
                sums_[i] += delta;
                i += lowbit(i);
            }
        }
        // gets the query sum before and include the idx the nodes
        int query(int i) const {
            int sum = 0;
            while (i > 0){
                sum += sums_[i];
                i -= lowbit(i);
            }
            return sum;
        }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        // get rank
        set<int> sorted(nums.begin(), nums.end()); // sort and remove duplicates
        unordered_map<int, int> ranks;
        int rank = 0;
        for(const int num : sorted){ranks[num] = ++rank;}

        vector<int> asw; // do not initialize with the length, it's too slow
        FenwickTree ft = FenwickTree(nums.size());
        for(int i = nums.size() - 1; i >= 0; --i){
            int rk = ranks[nums[i]];
            asw.push_back(ft.query( rk - 1)); 
            ft.update(rk, 1); 
        }
        std::reverse(asw.begin(), asw.end());
        return asw;
    }

};