int profit(vector<int>&prices){
  int n= prices.size();
  vector<vector<int>>dp(n,vector<int>(2,-1));
  return solve();
}

void solve(int i, int buy, vector<int>&prices){
  if(i>=prices.size()) return 0;
  if(dp[i][buy]!=-1) return dp[i][buy];
  int profit=0;
  if(buy){
    profit= max(-prices[i]+solve(i+1,0,prices), solve(i+1,1,buy));
    
  }
  else{
    profit= max(prices[i]+solve(i+2,1,prices), solve(i+1,0,prices));
  }
  return dp[i][buy]= profit;
}
