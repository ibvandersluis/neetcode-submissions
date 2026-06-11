class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        int longest {0};
        unordered_set<int> numset(nums.begin(), nums.end());
        vector<int> seq_starts {};

        for (int num : numset) {
            if (!numset.count(num-1)) {
                int count {1};
                while (numset.count(num+1)) count++, num++;
                longest = count > longest ? count : longest;
            }
        }

        return longest;
    }
};
