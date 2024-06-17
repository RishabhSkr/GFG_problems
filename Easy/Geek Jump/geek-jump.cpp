//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int dp[100001];
  int solve(vector<int>&h,int n){
      if(n==0)return 0;
      if(n==1)return abs(h[n]-h[n-1]);
      if(dp[n]!=-1)return dp[n];
      int one = 0,two =0;
      one =abs(h[n]-h[n-1])+solve(h,n-1);
      two =abs(h[n]-h[n-2])+solve(h,n-2);
      return dp[n]=min(one,two);
  }
    int minimumEnergy(vector<int>& h, int n) {
        // Code here
        memset(dp,-1,sizeof(dp));
        return solve(h,n-1);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends