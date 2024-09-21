//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int lps(string s) {
        // Your code goes here
        int m = s.size();
        int len = 0;
        int j = 1;
        int dp[m]={0};
        
        while(j<m){
            if(s[j]==s[len]){
                len++;
                dp[j]=len;
                j++;
            }else{
                if(len!=0){
                    len=dp[len-1];
                }else{
                    dp[len]=0;
                    j++;
                }
            }
        }
        return dp[m-1];
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;

        Solution ob;

        cout << ob.lps(str) << "\n";
    }

    return 0;
}

// } Driver Code Ends