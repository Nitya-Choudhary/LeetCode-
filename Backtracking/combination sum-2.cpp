class Solution {
public:
    vector<vector<int>> result;

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());  // important
        vector<int> curr;
        backtrack(candidates, 0, curr, target);
        return result;
    }

private:
    void backtrack(vector<int>& candidates, int start, vector<int>& curr, int target) {
        if (target == 0) {
            result.push_back(curr);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            // ❗ Skip duplicates
            if (i > start && candidates[i] == candidates[i-1])
                continue;

            if (candidates[i] > target) break; // optimization

            curr.push_back(candidates[i]);
            backtrack(candidates, i + 1, curr, target - candidates[i]); // no reuse → i+1
            curr.pop_back();
        }
    }
};
