
class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[n - 1];
        int ans = 0;

        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] * (n - i - 1) > sum) {
                ans++;
            }
            sum += nums[i];
        }

        return ans;
    }
};
