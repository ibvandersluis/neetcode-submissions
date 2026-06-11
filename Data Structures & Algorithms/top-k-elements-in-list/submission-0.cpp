class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        vector<vector<int>> freq(nums.size()+1);

        for (const int n : nums) {
            count[n]++;
        }

        for (const auto& e : count) {
            freq[e.second].push_back(e.first);
        }

        vector<int> res;
        for (auto i = freq.size() - 1; i > 0; i--) {
            for (const int n : freq[i]) {
                res.push_back(n);
                if (res.size() >= k) {
                    return res;
                }
            }
        }

        return res;
    }
};
