class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n < 3) {
            return 0;
        }

        vector<int> maxLeft(n);
        vector<int> maxRight(n);

        int currMaxLeft = 0;
        for (int i = 0; i < n; ++i) {
            currMaxLeft = max(currMaxLeft, height[i]);
            maxLeft[i] = currMaxLeft;
        }

        int currMaxRight = 0;
        for (int i = n - 1; i >= 0; --i) {
            currMaxRight = max(currMaxRight, height[i]);
            maxRight[i] = currMaxRight;
        }

        int totalWater = 0;
        for (int i = 0; i < n; ++i) {
            totalWater += min(maxLeft[i], maxRight[i]) - height[i];
        }

        return totalWater;
    }
};
