//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
/*You are required to complete this method*/

class Solution
{
    public:
    int dp[1001][1001], mod = 1e9 + 7;

    int solve(string &s, string &t, int i, int j) {
        if (j == t.length()) return 1;
        if (i == s.length()) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        
        int match = 0, notMatch = 0;
        if (s[i] == t[j]) {
            match = solve(s, t, i + 1, j + 1);
            notMatch = solve(s, t, i + 1, j);
        } else {
            notMatch = solve(s, t, i + 1, j);
        }
        
        return dp[i][j] = (match + notMatch) % mod;
    }
    
    int subsequenceCount(string s, string t) {
        memset(dp, -1, sizeof(dp));
        return solve(s, t, 0, 0);
    }
};
 


//{ Driver Code Starts. 

//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		Solution ob;
		cout<<ob.subsequenceCount(s,tt)<<endl;
		
		
	}
  
}
// } Driver Code Ends