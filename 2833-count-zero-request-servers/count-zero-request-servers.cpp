
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs,
                             int x, vector<int>& queries) {

        int m = queries.size();
        int L = logs.size();

        // Sort logs by time
        sort(logs.begin(), logs.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        // Sort query indices by query time
        vector<int> indices(m);
        iota(indices.begin(), indices.end(), 0);

        sort(indices.begin(), indices.end(),
             [&](int a, int b) {
                 return queries[a] < queries[b];
             });

        vector<int> cnt(n + 1, 0);
        vector<int> ans(m);

        int left = 0;
        int right = 0;
        int active = 0;

        for (int idx : indices) {

            int q = queries[idx];
            int start = q - x;

            // Add logs entering the window
            while (right < L && logs[right][1] <= q) {

                int id = logs[right][0];

                if (cnt[id] == 0) {
                    active++;
                }

                cnt[id]++;
                right++;
            }

            // Remove logs leaving the window
            while (left < L && logs[left][1] < start) {

                int id = logs[left][0];

                cnt[id]--;

                if (cnt[id] == 0) {
                    active--;
                }

                left++;
            }

            // Servers without any requests
            ans[idx] = n - active;
        }

        return ans;
    }
};
