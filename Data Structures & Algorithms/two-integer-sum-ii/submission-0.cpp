class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l {0};
        int r {(int)numbers.size() - 1};

        while (l < numbers.size() && r > 0 && l < r) {
            if (l != r && numbers[l] + numbers[r] == target) {
                return {l+1, r+1};
            }

            int l_comp {target - numbers[l]};
            int r_comp {target - numbers[r]};

            while (numbers[r] > l_comp) {
                r--;
            }
            while (numbers[l] < r_comp) {
                l++;
            }
        }

        return {};
    }
};
