//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
vector<vector<int>>dp;
    int solve(int i,int j,int arr[]){
        if(i==j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans = INT_MAX;
        for(int k=i;k<j;++k){
            int steps = arr[i-1]*arr[k]*arr[j]+solve(i,k,arr)+solve(k+1,j,arr);
            ans = min(ans,steps);
        }
        return dp[i][j]=ans;
    }

    int matrixMultiplication(int N, int arr[])
    {
        // code here
        dp.resize(N+1,vector<int>(N+1,-1));
        return solve(1,N-1,arr);
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