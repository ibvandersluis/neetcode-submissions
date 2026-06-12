class Solution {
public:
    int trap(vector<int>& height) {
        // Brute force
        int totalWater = 0;

        // Iterate over vector from start to end
        for (int i = 0; i < height.size(); ++i) {
            int maxL = 0;
            int maxR = 0;

            // Iterate left
            for (int j = 0; j < i; ++j) {
                maxL = max(maxL, height[j]);
            }

            // Iterate right
            for (int k = i; k < height.size(); ++k) {
                maxR = max(maxR, height[k]);
            }

            int minHeight = min(maxL, maxR);
            int occupied = height[i];
            int waterInColumn = max(0, minHeight - occupied);

            totalWater += waterInColumn;
        }

        return totalWater;
    }
};
