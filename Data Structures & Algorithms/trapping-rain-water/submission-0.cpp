class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() <= 1) return 0; // min size == 2

        int prefix[height.size()];
        int suffix[height.size()];
        int left {0};
        int right {height.size() - 1};
        int max_prefix {0};
        int max_suffix {0};

        while (left < height.size()) {
            max_prefix = max(max_prefix, height[left]);
            max_suffix = max(max_suffix, height[right]);
            prefix[left] = max_prefix;
            suffix[right] = max_suffix;
            left++;
            right--;
        }

        int sum {0};
        for (int i {0}; i < height.size(); ++i) {
            sum += (min(prefix[i], suffix[i]) - height[i]);
        }
        
        return sum;
    }
};
