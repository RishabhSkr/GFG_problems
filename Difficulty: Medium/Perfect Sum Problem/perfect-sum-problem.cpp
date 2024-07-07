//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int mod = 1e9+7;
    int solve(int i,int arr[],int sum,vector<vector<int>>&dp){
        if(i < 0){
            if(sum == 0) return 1;
            else return 0;
        }
        if(i<0)return sum==0;
        if(dp[i][sum]!=-1)return dp[i][sum];
        int take =0;
        int notTake=solve(i-1,arr,sum,dp);
        if(arr[i]<=sum)take = (solve(i-1,arr,sum-arr[i],dp));
        return dp[i][sum]=(take%mod+notTake%mod)%mod;
    }
	int perfectSum(int arr[], int n, int sum)
	{
	    vector<vector<int>>dp(n,vector<int>(sum+1,-1));
	    
        return solve(n-1,arr,sum,dp);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends