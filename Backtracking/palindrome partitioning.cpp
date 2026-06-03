class Solution {
public:
    vector<vector<string>> ans;
    vector<string> cur;
    vector<vector<bool>> dp;

    void solve(string &s, int idx) {
        if (idx == s.size()) {
            ans.push_back(cur);
            return;
        }

        for (int j = idx; j < s.size(); j++) {
            if (dp[idx][j]) {
                cur.push_back(s.substr(idx, j - idx + 1));
                solve(s, j + 1);
                cur.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n = s.size();
        dp.assign(n, vector<bool>(n, false));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j - i < 2 || dp[i + 1][j - 1]))
                    dp[i][j] = true;
            }
        }

        solve(s, 0);
        return ans;
    }
};
