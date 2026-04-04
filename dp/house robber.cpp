#include <iostream>
using namespace std;

class Solution{
public:
      int rob(vector<int>&nums){
        int n= nums.size();
        vector<int>dp(n,-1);
        
      }
     int solve(vector<int>&nums, int ind,int n){
       if(ind<0) return 0;
       if(ind==0) return nums[0];
       if(dp[ind]!=-1) return dp[ind];
       int pick=nums[ind]+solve(nums,ind-2,n);
       int nonpick= solve(nums,ind-1,n);
       return dp[ind]= max(pick,nonpick);
       
     }
};
