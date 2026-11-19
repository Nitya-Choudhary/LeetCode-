
class Solution {
public:
    int minGroupsForValidAssignment(vector<int>& nums) {
        unordered_map<int, int> freq;

        // Step 1: Count frequency of each number
        for (int num : nums) {
            freq[num]++;
        }

        // Step 2: Find minimum frequency
        int minFreq = nums.size();

        for (auto& it : freq) {
            minFreq = min(minFreq, it.second);
        }

        // Step 3: Try possible group sizes
        for (int k = minFreq; k >= 1; k--) {

            int totalGroups = 0;
            bool valid = true;

            // Step 4: Check every frequency
            for (auto& it : freq) {
                int f = it.second;

                int a = f / (k + 1);
                int b = f % (k + 1);

                if (b == 0) {
                    totalGroups += a;
                }
                else if (k - b <= a) {
                    totalGroups += a + 1;
                }
                else {
                    valid = false;
                    break;
                }
            }

            // First valid k gives minimum groups
            if (valid) {
                return totalGroups;
            }
        }

        return nums.size();
    }
};
