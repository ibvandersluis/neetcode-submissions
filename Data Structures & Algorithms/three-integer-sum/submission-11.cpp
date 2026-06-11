class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) {
            return {};
        }

        constexpr int target = 0;

        // sort in nondecreasing order
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;

        for (int i = 0; i < nums.size() - 2; ++i) {
            if (nums[i] > 0) {
                break;
            }
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            int l = i + 1;
            int r = nums.size() - 1;

            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum > target) {
                    --r;
                } else if (sum < target) {
                    ++l;
                } else {
                    res.push_back({nums[i], nums[l], nums[r]});
                    --r;
                    ++l;
                    while (l < r && nums[l] == nums[l - 1]) {
                        l++;
                    }
                }
            }

            while (i < nums.size() - 1 && nums[i] == nums[i + 1]) {
                ++i;
            }
        }

        return res;
    }
};
