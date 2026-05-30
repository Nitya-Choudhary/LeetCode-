class Solution {
public:
    int dp[71][71][71];

    int solve(int row, int col1, int col2, vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if (col1 < 0 || col1 >= n || col2 < 0 || col2 >= n)
            return -1e8;

        if (row == m - 1) {
            if (col1 == col2)
                return grid[row][col1];
            return grid[row][col1] + grid[row][col2];
        }

        if (dp[row][col1][col2] != -1)
            return dp[row][col1][col2];

        int cherries = (col1 == col2)
                           ? grid[row][col1]
                           : grid[row][col1] + grid[row][col2];

        int maxi = 0;

        for (int d1 = -1; d1 <= 1; d1++) {
            for (int d2 = -1; d2 <= 1; d2++) {
                maxi = max(maxi,
                           solve(row + 1, col1 + d1, col2 + d2, grid));
            }
        }

        return dp[row][col1][col2] = cherries + maxi;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        int n = grid[0].size();

        return solve(0, 0, n - 1, grid);
    }
};
