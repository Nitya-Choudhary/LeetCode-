class Solution{
public:
      int LCS(string s1, string s2){
        int m= s1.size();
        int n= s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=m;i++){
          for(int j=1;j<=n;j++){
            if(s[i-1]==s2[j-1]){
              dp[i][j]=1+dp[i-1][j-1];
              
            }
            else{
              dp[i][j]= max(dp[i][j-1],dp[j][i-1]);
            }
          }
        }
        return dp[n][m];
        
      }
}
