//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> Series(int n) {
        // Code here
        int mod =1e9+7;
        vector<int>dp(n+1,0);
        dp[0]=0,dp[1]=1;
        for(int i = 2;i<=n;++i){
            dp[i]=(dp[i-1])%mod+(dp[i-2])%mod;
            dp[i]=dp[i]%mod;
        }
        return dp;
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

        vector<int> ans = obj.Series(n);
        for (auto x : ans) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends