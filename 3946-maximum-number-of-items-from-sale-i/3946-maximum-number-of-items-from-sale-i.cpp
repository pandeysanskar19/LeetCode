#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = static_cast<int>(items.size());
        vector<int> bonus(n, 0);

        for (int i = 0; i < n; ++i) {
            int fi = items[i][0];
            for (int j = 0; j < n; ++j) {
                if (i != j && items[j][0] % fi == 0) {
                    ++bonus[i];
                }
            }
        }

        vector<int> dp(budget + 1, 0);

        for (int i = 0; i < n; ++i) {
            int price = items[i][1];
            if (price > budget) {
                continue;
            }

            vector<int> next_dp = dp;

            // First copy of item i: costs `price`, yields 1 + bonus[i] copies.
            for (int b = budget; b >= price; --b) {
                next_dp[b] = max(next_dp[b], dp[b - price] + 1 + bonus[i]);
            }

            // Additional copies of item i: costs `price` each, yields +1 copy per copy.
            for (int b = price; b <= budget; ++b) {
                next_dp[b] = max(next_dp[b], next_dp[b - price] + 1);
            }

            dp.swap(next_dp);
        }

        int ans = 0;
        for (int b = 0; b <= budget; ++b) {
            ans = max(ans, dp[b]);
        }
        return ans;
    }
};