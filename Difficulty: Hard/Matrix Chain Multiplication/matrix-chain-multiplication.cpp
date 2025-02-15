//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    // int solve(int i,int j,int arr[]){
    //     if(i==j)return 0;
    //     if(dp[i][j]!=-1)return dp[i][j];
    //     int ans = INT_MAX;
    //     for(int k=i;k<j;++k){  
    //         int steps = arr[i-1]*arr[k]*arr[j]+solve(i,k,arr)+solve(k+1,j,arr);
    //         ans = min(ans,steps);
    //     }
    //     return dp[i][j]=ans;
    // }

    int matrixMultiplication(int n, int arr[])
    {
        // code here
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=n-1;i>=1;--i){
            for(int j = i+1;j<n;++j){
                int ans = INT_MAX;
                for(int k=i;k<j;++k){
                    int steps = arr[i-1]*arr[k]*arr[j]+dp[i][k]+dp[k+1][j];
                    ans = min(ans,steps);
                }
                dp[i][j]=ans;
            }
        }
        return dp[1][n-1];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends