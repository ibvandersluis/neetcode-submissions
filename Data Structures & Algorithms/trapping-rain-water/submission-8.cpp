class Solution {
public:
    int trap(vector<int>& height) {
        // Mulit-array
        int nCols = height.size();

        if (nCols < 3) {
            return 0;
        }

        vector<int> maxLeft(height.size());
        vector<int> maxRight(height.size());

        // Left to right
        int currMaxLeft = 0;
        for (int i = 0; i < nCols; ++i) {
            currMaxLeft = max(currMaxLeft, height[i]);
            maxLeft[i] = currMaxLeft;
        }

        // Right to left
        int currMaxRight = 0;
        for (int i = nCols - 1; i >= 0; --i) {
            currMaxRight = max(currMaxRight, height[i]);
            maxRight[i] = currMaxRight;
        }

        // Sum water capacity for each column
        int totalWater = 0;
        for (int i = 0; i < nCols; ++i) {
            totalWater += min(maxLeft[i], maxRight[i]) - height[i];
        }

        return totalWater;
    }
};
