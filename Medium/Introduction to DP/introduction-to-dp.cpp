//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int mod = 1e9+7;
  long long int dp[10001];
    long long int solve(int n) {
        // code here
        if(n==0)return 0;
        if(n==1)return 1;
        if(dp[n]!=-1)return dp[n];
        return dp[n]= (solve(n-1)%mod+solve(n-2)%mod)%mod;
    }
long long int topDown(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n);
    }
    
    long long int bottomUp(int n) {
        // code here
        long long int prev2 = 0, prev =1;
        for(int i=2;i<=n;++i){
            long long int curr = (prev2+prev)%mod;
            prev2 =prev%mod;
            prev = curr%mod;
        }
        return prev;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    }
}
// } Driver Code Ends