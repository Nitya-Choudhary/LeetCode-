class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;

        // Count frequency
        for (int x : nums)
            freq[x]++;

        // Convert map to vector of pairs {num, frequency}
        vector<pair<int,int>> v;
        for (auto &p : freq)
            v.push_back({p.first, p.second});

        // Sort by frequency in descending order
        sort(v.begin(), v.end(), [](auto &a, auto &b){
            return a.second > b.second;
        });

        // Pick top k
        vector<int> result;
        for (int i = 0; i < k; i++)
            result.push_back(v[i].first);

        return result;
    }
};
