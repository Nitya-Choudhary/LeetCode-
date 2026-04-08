#include <bits/stdc++.h>
using namespace std;

// Class to solve 0/1 Knapsack using memoization
class Solution {
public:
    // Function to compute maximum value
    int knapSackUtil(int ind, int W, vector<int>& wt, 
                     vector<int>& val, vector<vector<int>>& dp) {
        // Base case: if only one item left
        if (ind == 0) {
            if (wt[0] <= W) return val[0];
            else return 0;
        }
        // If already computed return it
        if (dp[ind][W] != -1) return dp[ind][W];
        
        // Exclude current item
        int notTaken = knapSackUtil(ind - 1, W, wt, val, dp);
        
        // Include current item if possible
        int taken = INT_MIN;
        if (wt[ind] <= W) 
            taken = val[ind] + knapSackUtil(ind - 1, W - wt[ind], 
                                            wt, val, dp);
        
        // Store result in dp
        return dp[ind][W] = max(notTaken, taken);
    }

    // Main function to call
    int knapSack(int W, vector<int>& wt, vector<int>& val, int n) {
        vector<vector<int>> dp(n, vector<int>(W + 1, -1));
        return knapSackUtil(n - 1, W, wt, val, dp);
    }
};
