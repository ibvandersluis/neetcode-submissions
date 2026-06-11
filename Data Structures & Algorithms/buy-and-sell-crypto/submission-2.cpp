class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lowest {100};
        int greatest_diff {0};

        for (const int price : prices) {
            lowest = min(lowest, price);
            greatest_diff = max(greatest_diff, price - lowest);
        }

        return greatest_diff;
    }
};
