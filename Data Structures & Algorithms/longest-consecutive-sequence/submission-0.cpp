class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        int longest {0};
        unordered_set<int> in_set;
        vector<int> seq_starts {};

        for (int num : nums) {
            in_set.insert(num);
            while (in_set.count(num-1)) num--;
            seq_starts.push_back(num);
        }

        for (int start : seq_starts) {
            int count {1};
            while (in_set.count(start+1)) count++, start++;
            longest = count > longest ? count : longest;
        }

        return longest;
    }
};
