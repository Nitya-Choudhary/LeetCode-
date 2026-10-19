
class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1'000'000'007;

        vector<int> dp(n + 1, 0);
        dp[1] = 1;

        long long sharing = 0;

        for (int day = 2; day <= n; day++) {
            // People who start sharing today
            if (day - delay >= 1) {
                sharing = (sharing + dp[day - delay]) % MOD;
            }

            // People who forget today can no longer share
            if (day - forget >= 1) {
                sharing = (sharing - dp[day - forget] + MOD) % MOD;
            }

            // Newly informed people today
            dp[day] = sharing;
        }

        // Count people who still remember on day n
        long long ans = 0;

        for (int day = max(1, n - forget + 1); day <= n; day++) {
            ans = (ans + dp[day]) % MOD;
        }

        return ans;
    }
};
