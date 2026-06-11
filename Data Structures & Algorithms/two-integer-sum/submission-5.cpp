class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Hash map
        unordered_map<int, int> um;

        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (um.find(complement) != um.end()) {
                return {um[complement], i};
            } else {
                um[nums[i]] = i;
            }
        }
        
        return {};
    }
};
