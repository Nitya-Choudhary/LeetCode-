
class Solution {
public:
    int beautifulPartitions(string s, int k, int minLength) {
        const int MOD = 1e9 + 7;
        int n = s.size();

        auto isPrime = [](char c) {
            return c == '2' || c == '3' ||
                   c == '5' || c == '7';
        };

        // Necessary conditions
        if (!isPrime(s[0]) || isPrime(s[n - 1]))
            return 0;

        if (1LL * k * minLength > n)
            return 0;

        // dp[j] = ways to partition first j characters
        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        for (int part = 1; part <= k; part++) {
            vector<int> ndp(n + 1, 0);
            long long prefix = 0;

            for (int i = 1; i <= n; i++) {
                int start = i - minLength;

                if (start >= 0 &&
                    start < n &&
                    isPrime(s[start]) &&
                    (start == 0 || !isPrime(s[start - 1]))) {
                    prefix = (prefix + dp[start]) % MOD;
                }

                if (i < n && !isPrime(s[i - 1]) &&
                    isPrime(s[i])) {
                    ndp[i] = prefix;
                }
            }

            // Last partition must end at n
            if (part == k) {
                ndp[n] = prefix;
            }

            dp = ndp;
        }

        return dp[n];
    }
};
