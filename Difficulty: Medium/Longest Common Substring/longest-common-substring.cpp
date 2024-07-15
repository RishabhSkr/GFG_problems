//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // your code here
   
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        int ans = -1e9;
        for(int i =0;i<n;++i){
            for(int j = 0;j<m;++j){
                if(S1[i]==S2[j]){
                    dp[i+1][j+1]= 1+dp[i][j];
                    ans = max(dp[i+1][j+1],ans);
                }
                else{
                    dp[i+1][j+1]= 0;
                }
            }
        }
        if(ans==-1e9)return 0;
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends