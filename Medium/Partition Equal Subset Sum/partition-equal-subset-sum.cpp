//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

	
	int help(int n,int i ,int *arr,int sum){
	    
	    if(i==n){
	        if(sum == 0)return 1;
	        return 0;
	    }
	  
	   if(sum<0)return 0;
	   
	   // if(dp[i][sum]!=-1)return dp[i][sum];
	    
	    int ans =0;
	    
	    ans = help(n,i+1,arr,sum-arr[i]) || help(n,i+1,arr,sum);
	    
	    return ans;
	}
    
    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for(int i  = 0 ;i<N ; ++i){
            sum += arr[i];
        }
        if(sum%2!=0)return false;
      return help(N,0,arr,sum/2);
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
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends