int uniquepaths(vector<vector<int>>&matrix){
  int n= matrix.size();
  int m= matrix[0].size();
  vector<vector<int>>dp(m,vector<int>(n,-1));
  return solve(m-1,n-1,matrix,dp);
}

int solve(int i, int j, vector<vector<int>>matrix, vector<vector<int>>&dp){
  if(i==0 || j==0) return 1;
  if(i<0|| j<0) return 0;
  if(matrix[i][j]==1) return 0;
  if(dp[i][j]!=-1) return dp[i][j];
  int up= solve(i-1,j,matrix,dp);
  int left= solve(i,j-1,matrix,dp);
  retrun dp[i][j]= up +left;
}
