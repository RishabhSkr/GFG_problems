//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
// infinite coins or steps
// multiple use

// we should not use greedy becuse val = 25 and max ele = 5 it is not necessari;y 5 coins will 
    int solve(int n,int val ,vector<int>&coins,vector<vector<int>>& dp){
        //base
        if(n==0){
            if(val%coins[0]==0)return val/coins[0];
            else return 1e9;  // overflow occur if INT_MAX is used
        }
        if(dp[n][val]!=-1)return dp[n][val];
        // induction and hypothesis 0/1 knapsack
        int take = INT_MAX;
        if(coins[n]<=val){
            take=1+solve(n,val-coins[n],coins,dp);
        }
        int notTake =0+solve(n-1,val,coins,dp);
        return dp[n][val]=min(take,notTake);
        
    }
	public:
	int minCoins(vector<int> &coins, int M, int V) 
	{ 
	    // Your code goes here
	    vector<vector<int>> dp(M+1,vector<int>(V+1,-1));
	    int ans =  solve(M-1,V,coins,dp);
	    return ans>=1e9?-1:ans;
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