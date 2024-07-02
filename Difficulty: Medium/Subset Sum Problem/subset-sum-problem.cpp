//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
int dp[101][10001];
bool solve(int i,vector<int>&arr,int sum){
    if(i==0){
        if(sum-arr[0]==0)return true;
        return false;
    }
    if(sum==0)return true;
    if(dp[i][sum]!=-1)return dp[i][sum];
    bool take = false;
    if(arr[i]<= sum)take= solve(i-1,arr,sum-arr[i]);
    bool notTake =solve(i-1,arr,sum);
    return dp[i][sum]=take|notTake;
}
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        memset(dp,-1,sizeof(dp));
        return solve(arr.size()-1,arr,sum);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends