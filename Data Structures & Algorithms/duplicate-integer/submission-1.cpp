class Solution {
public:
    bool hasDuplicate(vector<int>& nums) const {
        unordered_set<int> occurance;
        for (int num : nums) {
            if (occurance.count(num)) {
                return true;
            }
            occurance.insert(num);
        }
        return false;
    }
};