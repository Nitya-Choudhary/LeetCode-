vector<vector<int>>dp;
bool canpartition(vector<int>&nums){
  int n= nums.size();
  int sum= 0;
  for(int x:nums) sum= sum+x;
  if(sum%2!=0) return false;
  int target= sum/2;
  dp.assign(n,vector<int>(target,-1));
  return solve();
}

bool solve(int i, int s, vector<int>&nums){
  if(s==0) return true;
  if(i==nums.size()) return false;
  if(dp[s][i]!=-1) return dp[s][i];
  bool notake= solve(i+1, s, nums);
  bool take= false;
  if(nums[i]<=s){
    take= solve(i+1, s-nums[i],nums);
  }
  return dp[i][s]= (take || notake);
  
  
}
