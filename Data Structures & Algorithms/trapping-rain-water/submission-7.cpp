class Solution {
public:
    int trap(vector<int>& height) {
        // Multi-array

        vector<int> leftMax(height.size());
        vector<int> rightMax(height.size());

        int currMaxL = height[0];
        for (int i = 0; i < height.size(); ++i) {
            currMaxL = max(height[i], currMaxL);
            leftMax[i] = currMaxL;
        }

        int currMaxR = height[height.size() - 1];
        for (int i = height.size() - 1; i >= 0; --i) {
            currMaxR = max(height[i], currMaxR);
            rightMax[i] = currMaxR;
        }

        int totalWater = 0;
        for (int i = 0; i < height.size(); ++i) {
            totalWater += min(leftMax[i], rightMax[i]) - height[i];
        }

        return totalWater;
    }
};
