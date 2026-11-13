
class MedianCost {
public:
    multiset<long long> left, right;
    long long sumLeft = 0, sumRight = 0;

    // Keep left size equal to right or one larger
    void balance() {
        while (left.size() > right.size() + 1) {
            long long val = *left.rbegin();
            left.erase(prev(left.end()));
            sumLeft -= val;

            right.insert(val);
            sumRight += val;
        }

        while (left.size() < right.size()) {
            long long val = *right.begin();
            right.erase(right.begin());
            sumRight -= val;

            left.insert(val);
            sumLeft += val;
        }
    }

    void add(long long val) {
        if (left.empty() || val <= *left.rbegin()) {
            left.insert(val);
            sumLeft += val;
        } else {
            right.insert(val);
            sumRight += val;
        }

        balance();
    }

    void remove(long long val) {
        auto it = left.find(val);

        if (it != left.end()) {
            left.erase(it);
            sumLeft -= val;
        } else {
            it = right.find(val);
            right.erase(it);
            sumRight -= val;
        }

        balance();
    }

    // Minimum operations to make the window equal
    long long getCost() {
        long long median = *left.rbegin();

        return median * left.size() - sumLeft
             + sumRight - median * right.size();
    }
};

class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {

        int n = nums.size();

        const long long INF = LLONG_MAX / 4;

        // dp[i][j] = minimum cost to select
        // j non-overlapping windows from first i elements
        vector<vector<long long>> dp(
            n + 1, vector<long long>(k + 1, INF)
        );

        dp[0][0] = 0;

        MedianCost mc;

        for (int i = 1; i <= n; i++) {

            // Add current element to sliding window
            mc.add(nums[i - 1]);

            // Option 1: Don't select a window ending here
            for (int j = 0; j <= k; j++) {
                dp[i][j] = dp[i - 1][j];
            }

            // Option 2: Select the current window of size x
            if (i >= x) {

                long long cost = mc.getCost();

                for (int j = 1; j <= k; j++) {

                    if (dp[i - x][j - 1] != INF) {
                        dp[i][j] = min(
                            dp[i][j],
                            dp[i - x][j - 1] + cost
                        );
                    }
                }

                // Remove element leaving the window
                mc.remove(nums[i - x]);
            }
        }

        return dp[n][k];
    }
};
