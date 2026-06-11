class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;

        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i-1] == nums[i]) {
                continue;
            }
            int l = i + 1;
            int r = nums.size() - 1;

            while (l < r) {
                int sum = nums[l] + nums[r];
                if (sum < -nums[i]) {
                    l++;
                } else if (sum > -nums[i]) {
                    r--;
                } else {
                    result.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    while (l < r && nums[l] == nums[l - 1]) {
                        l++;
                    }
                }
            }
        }
        return result;
    }
};
