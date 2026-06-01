class Solution{
public:
      vector<vector<int>> combinationsum(vector<int>& nums, int target){
        vector<int>curr;
        vector<vector<int>>result;
        backtrack(nums,0,target,curr,result);
        return result;
      }
      void backtrack(vector<int>& nums, int start, int target, vector<int>curr, vector<vector<int>>result){
        int n=nums.size();
        if(target==0) result.push_back(curr); 
        return;
        if(target<0) return ;
        for(int i= start;i<n;i++){
          curr.push_back(nums[i]);
          backtrack(nums,i, target-nums[i], curr,result);
          curr.pop_back();
          
        }
        
      }
}
