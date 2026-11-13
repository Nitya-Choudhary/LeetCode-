
class Solution {
public:
    int minMoves2(vector<int>& nums) {

        // Sort the array
        sort(nums.begin(), nums.end());
        int median = nums[nums.size() / 2];

        int moves = 0;
        for (int num : nums) {
            moves += abs(num - median);
        }

        return moves;
    }
};
