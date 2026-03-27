#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> mp;

        // Mark all numbers
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]] = true;
        }

        int longest = 0;

        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if (mp[num - 1] == false) {
                int current = num;
                int count = 1;
                while (mp[current + 1] == true) {
                    current++;
                    count++;
                }

                longest = max(longest, count);
            }
        }

        return longest;
    }
};
