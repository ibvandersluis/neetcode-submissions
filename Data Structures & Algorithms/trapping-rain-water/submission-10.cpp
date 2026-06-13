class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n < 3) {
            return 0;
        }

        int totalWater = 0;

        for (int i = 0; i < n; ++i) {
            int maxLeft = 0;
            for (int j = i; j >= 0; --j) {
                maxLeft = max(maxLeft, height[j]);
            }

            int maxRight = 0;
            for (int k = i; k < n; ++k) {
                maxRight = max(maxRight, height[k]);
            }

            totalWater += min(maxLeft, maxRight) - height[i];
        }

        return totalWater;
    }
};
