class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numToIdx;
        for (int i = 0; i < nums.size(); ++i) {
            int compliment = target - nums[i];
            if (numToIdx.find(compliment) != numToIdx.end()) {
                return {numToIdx[compliment], i};
            }
            numToIdx[nums[i]] = i;
        }
    }
};
