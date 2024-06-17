//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  //memoization
  int dp[100000];
//   int solve(int ind,int k,vector<int>&h){
//      if(ind==0)return 0;
//      if(dp[ind]!=-1)return dp[ind];
//      int ans=INT_MAX;
//      for(int j =1;j<=k;++j){
//          if(ind-j>=0){
//              int steps = solve(ind-j,k,h)+abs(h[ind]-h[ind-j]);
//              ans = min(steps,ans);
//          }
//      }
//      return dp[ind]=ans;
//   }
    int minimizeCost(vector<int>& h, int n, int k) {
        // memset(dp,-1,sizeof(dp));
        // return solve(n-1,k,height);
        // method 2:
        dp[0]=0;
        for(int i =1;i<n;++i){
            int minJump = INT_MAX,jump=0;
            for(int j=1;j<=k;++j){
                if(i-j>=0){
                    jump= dp[i-j]+abs(h[i]-h[i-j]);
                }
                minJump = min(minJump,jump); 
            }
            dp[i]=minJump;
        }
        return dp[n-1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends