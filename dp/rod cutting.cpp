class Solution{
public:
    vector<vector<int>>dp;
    int mincost(vector<int>& cuts, int n){
      cuts.push_back(0);
      cuts.push_back(n);
      sort(cuts.begin(), cuts.end());
      int m= cuts.size();
      dp.assign(m,vector<int>(m,-1));
      return solve(0,m-1,cuts);
    }
    int solve(int i, int j, vector<int>& cuts){
      if(j-i<=1){
        return 0;
      }
      if(dp[i][j]!=-1) return dp[i][j];
      int ans= INT_MAX;
      for(int k=i+1;k<j;k++){
        int cost= solve(i,k,cuts)+solve(k,j,cuts)+(cuts[j]-cuts[i]);
        ans= min(ans, cost);
      }
      return dp[i][j]= ans;
    }
}
