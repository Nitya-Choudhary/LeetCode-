
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        const int MAXX = 1024;

        vector<vector<bool>> dp(n, vector<bool>(MAXX, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                vector<bool> cur(MAXX, false);
                int v = grid[i][j];

                if (i == 0 && j == 0) {
                    cur[v] = true;
                } else {
                    if (i > 0) {
                        for (int x = 0; x < MAXX; x++) {
                            if (dp[j][x])
                                cur[x ^ v] = true;
                        }
                    }

                    if (j > 0) {
                        for (int x = 0; x < MAXX; x++) {
                            if (dp[j - 1][x])
                                cur[x ^ v] = true;
                        }
                    }
                }

                dp[j] = cur;
            }
        }

        for (int x = 0; x < MAXX; x++) {
            if (dp[n - 1][x])
                return x;
        }

        return -1;
    }
};
