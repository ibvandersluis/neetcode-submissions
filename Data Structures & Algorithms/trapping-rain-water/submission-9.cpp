class Solution {
public:
    int trap(vector<int>& height) {
        // Two pointers
        int nCols = height.size();

        if (nCols < 3) {
            return 0;
        }

        int maxL = 0;
        int maxR = 0;

        int l = 0;
        int r = nCols - 1;

        int totalWater = 0;
        while (l < r) {
            maxL = max(maxL, height[l]);
            maxR = max(maxR, height[r]);

            int minHeight = min(maxL, maxR);

            if (maxL < maxR) {
                totalWater += minHeight - height[l];
                l++;
            } else {
                totalWater += minHeight - height[r];
                r--;
            }
        }
        return totalWater;
    }
};
