class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int zero = find(nums.begin(), nums.end(), 0) - nums.begin();

        bool inc = true, dec = true;

        for (int k = 0; k < n; k++) {
            if (nums[(zero + k) % n] != k)
                inc = false;

            if (nums[(zero - k + n) % n] != k)
                dec = false;
        }

        int ans = INT_MAX;

        if (inc)
            ans = min(zero, n - zero + 2);

        if (dec)
            ans = min(ans, min(n - zero, zero + 2));

        return ans == INT_MAX ? -1 : ans;
    }
};
