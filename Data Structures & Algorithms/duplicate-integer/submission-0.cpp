class Solution {
public:
    bool hasDuplicate(vector<int>& nums) const {
        unordered_map<int, bool> occurance_map;
        for (size_t i = 0; i < nums.size(); ++i) {
            int val = nums[i];
            if (occurance_map.find(val) != occurance_map.end()) {
                return true;
            }
            occurance_map[val] = true;
        }
        return false;
    }
};