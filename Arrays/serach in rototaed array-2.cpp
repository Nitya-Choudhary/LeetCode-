class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n= nums.size();
        unordered_map<int,int>freq;
        for(int i=0;i<n;i++){
            freq[nums[i]]=i;
        }
         return freq.count(target);

        
    }
};
