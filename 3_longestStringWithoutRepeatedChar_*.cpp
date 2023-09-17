// trick: Uses HashTable and Sliding Window
// notes:   - unordered_map is generally faster than std::map on insertion, so use map 
//          only when you need ordered objects
//          - iteration of unordered_map: begin() and end(), iterator->first is the key
//          while iterator->second is the value. 

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // idx['x'] = the indicies of the last occurance of 'x', size is 128 because 
        //      input only contains ascii chars
        vector<int> idx(128, -1);   // 128 dimension vector of number -1
        int max_len = 0; 
        for (int i = 0, j = 0; j < s.size(); ++j){
            i = max(i, idx[s[j]] + 1);
            idx[s[j]] = j;
            max_len = max(max_len, j - i + 1); 
        }
        return max_len; 
    }
};