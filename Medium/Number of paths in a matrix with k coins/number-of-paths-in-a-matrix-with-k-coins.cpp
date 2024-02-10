//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
   int dp[101][101][101];
    int solve(vector<vector<int>>&arr,int n,int k,int i,int j){
        if(i==n-1 && j ==  n-1){
            if(k==arr[i][j])return 1;
            else return 0;
        }
        if(dp[i][j][k]!=-1)return dp[i][j][k];
        int  right = 0,down =0;
        if(i+1<=n-1 && k-arr[i][j]>=0){
            right = solve(arr,n,k-arr[i][j],i+1,j);
        }
         if(j+1<=n-1 && k-arr[i][j]>=0){
            down = solve(arr,n,k-arr[i][j],i,j+1);
        }
        return dp[i][j][k]=right+down;
    }
    long long numberOfPath(int n, int k, vector<vector<int>> &arr){
        
        // Code Here
        memset(dp,-1,sizeof(dp));
        return solve(arr,n,k,0,0);
    }
};

//{ Driver Code Starts.

int main()
{
    Solution obj;
    int i,j,k,l,m,n,t;
    cin>>t;
    while(t--)
    {
        cin>>k>>n;
        vector<vector<int>> v(n, vector<int>(n, 0));
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                cin>>v[i][j];
        cout << obj.numberOfPath(n, k, v) << endl;
    }
}
// } Driver Code Ends