class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // int zero_count {0};
        // int nzp {0};

        // for (const int val : nums) {
        //     if (val == 0) {
        //         zero_count++;
        //     } else {
        //         if (!nzp) {
        //             nzp += val;
        //         } else {
        //             nzp *= val;
        //         }
        //     }
        // }

        // vector<int> res;
        // for (const int val : nums) {
        //     if (zero_count > 1) {
        //         res.push_back(0);
        //     } else if (zero_count == 1) {
        //         if (val == 0) {
        //             res.push_back(nzp);
        //         } else {
        //             res.push_back(0);
        //         }
        //     } else {
        //         res.push_back(nzp / val);
        //     }
        // }
        
        // return res;

        int n = nums.size();
        vector<int> res(n, 1);

        for (int i = 1; i < n; i++) {
            res[i] = res[i - 1] * nums[i - 1];
        }

        int postfix = 1;
        for (int i = n - 1; i >= 0; i--) {
            res[i] *= postfix;
            postfix *= nums[i];
        }
        return res;
    }
};
