class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n < 3) {
            return 0;
        }

        int l = 0;
        int r = n - 1;

        int currMaxLeft = height[l];
        int currMaxRight = height[r];

        int totalWater = 0;

        while (l < r) {
            if (currMaxLeft < currMaxRight) {
                totalWater += currMaxLeft - height[l];
                ++l;
                currMaxLeft = max(currMaxLeft, height[l]);
            } else {
                totalWater += currMaxRight - height[r];
                --r;
                currMaxRight = max(currMaxRight, height[r]);
            }
        }

        return totalWater;
    }
};
