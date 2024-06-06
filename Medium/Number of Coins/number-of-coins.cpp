//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
// infinite coins or steps
// multiple use

// we should not use greedy becuse val = 25 and max ele = 5 it is not necessari;y 5 coins will 
// T.C(exponential) S.C(VAL) Recursion
// T.C(more than N) 
    // int solve(int n,int val ,vector<int>&coins,vector<vector<int>>& dp){
    //     //base 
    //     if(n==0){
    //         if(val%coins[0]==0)return val/coins[0];
    //         else return 1e9;  // overflow occur if INT_MAX is used
    //     }
    //     if(dp[n][val]!=-1)return dp[n][val];
    //     // induction and hypothesis 0/1 knapsack
    //     int take = INT_MAX;
    //     if(coins[n]<=val){
    //         take=1+solve(n,val-coins[n],coins,dp);
    //     }
    //     int notTake =0+solve(n-1,val,coins,dp);
    //     return dp[n][val]=min(take,notTake);
        
    // }
	public:
	int minCoins(vector<int> &arr, int n, int T) 
	{ 
	   // int ans =  solve(M-1,V,coins,dp);
	   // Method 2: DP
	   // base case
	    // Initialize the first row of the DP table
    
    // Create a 2D DP (Dynamic Programming) table with n rows and T+1 columns
    vector<vector<int>> dp(n, vector<int>(T + 1, 0));
    
    // Initialize the first row of the DP table
    for (int i = 0; i <= T; i++) {
        if (i % arr[0] == 0)
            dp[0][i] = i / arr[0];
        else
            dp[0][i] = 1e9; // Set it to a very large value if not possible
    }
    
    // Fill the DP table using a bottom-up approach
    for (int ind = 1; ind < n; ind++) {
        for (int target = 0; target <= T; target++) {
            // Calculate the minimum elements needed without taking the current element
            int notTake = dp[ind - 1][target];
            
            // Calculate the minimum elements needed by taking the current element
            int take = 1e9; // Initialize 'take' to a very large value
            if (arr[ind] <= target)
                take = 1 + dp[ind][target - arr[ind]];
                
            // Store the minimum of 'notTake' and 'take' in the DP table
            dp[ind][target] = min(notTake, take);
        }
    }
    
    // The answer is in the bottom-right cell of the DP table
    int ans = dp[n - 1][T];
    // If 'ans' is still very large, it means it's not possible to form the target sum
    if (ans >= 1e9)
        return -1;
    
    return ans; 
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        vector<int> coins(m);
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends