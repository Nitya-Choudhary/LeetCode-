bool subsetsum(vector<int>&nums, int target){
  int n= nums.size();
  vector<bool>dp(target+1,false);
  for(int i=0;i<n;i++){
    for(int j=target, j>=i;j--){
      dp[j]= dp[j] || dp[j-i];
    }
  }
  return dp[target];
}
