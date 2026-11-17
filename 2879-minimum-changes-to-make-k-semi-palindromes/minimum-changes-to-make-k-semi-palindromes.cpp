
class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();

        // cost[i][j] = minimum changes needed
        // to make substring s[i...j] semi-palindrome
        vector<vector<int>> cost(n, vector<int>(n, 0));

        // Step 1: Precompute substring costs
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                int len = j - i + 1;
                int best = n;

                // Try all valid divisors
                for (int d = 1; d < len; d++) {

                    if (len % d != 0)
                        continue;

                    int changes = 0;

                    // Check each group
                    for (int offset = 0; offset < d; offset++) {

                        int l = i + offset;
                        int r = j - d + 1 + offset;

                        // Compare symmetric characters
                        while (l < r) {

                            if (s[l] != s[r])
                                changes++;

                            l += d;
                            r -= d;
                        }
                    }

                    best = min(best, changes);
                }

                cost[i][j] = best;
            }
        }

        // Step 2: DP
        // dp[i][parts] = minimum changes needed
        // to divide s[i...n-1] into parts substrings

        const int INF = 1e9;

        vector<vector<int>> dp(
            n + 1, vector<int>(k + 1, INF)
        );

        // Base case: empty string, zero parts
        dp[n][0] = 0;

        // Process starting positions backwards
        for (int i = n - 1; i >= 0; i--) {

            for (int parts = 1; parts <= k; parts++) {

                // End position of current substring
                for (int j = i + 1; j < n; j++) {

                    if (dp[j + 1][parts - 1] == INF)
                        continue;

                    dp[i][parts] = min(
                        dp[i][parts],
                        cost[i][j] + dp[j + 1][parts - 1]
                    );
                }
            }
        }

        return dp[0][k];
    }
};
