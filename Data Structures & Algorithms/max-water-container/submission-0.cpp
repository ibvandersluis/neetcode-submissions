class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left {0};
        int right {heights.size() - 1};
        int max_vol {0};
        
        while (left < right) {
            int width {right - left};
            int height {min(heights[left], heights[right])};
            int vol {width * height};
            max_vol = max(vol, max_vol);

            if (heights[left] > heights[right]) {
                right--;
            } else {
                left++;
            }
        }

        return max_vol;
    }
};
