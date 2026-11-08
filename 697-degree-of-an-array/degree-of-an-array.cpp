class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int> freq, first, last;

        int degree = 0;
        int ans = nums.size();

        for(int i = 0; i < nums.size(); i++) {
            int x = nums[i];

            if(freq[x] == 0)
                first[x] = i;

            freq[x]++;
            last[x] = i;

            degree = max(degree, freq[x]);
        }

        for(auto it : freq) {
            int x = it.first;

            if(freq[x] == degree) {
                ans = min(ans, last[x] - first[x] + 1);
            }
        }

        return ans;
    }
};