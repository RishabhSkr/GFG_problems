//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    /*You are required to complete this method*/
    //memoize
    vector<vector<int>>dp;
    bool solve(int i,int j,string &p,string &s){
        // base case
        if(i<0 && j<0)return true;
        if(i<0 && j>=0)return false; 
        // edge case if(s end but pat stil left)
        if(i>=0 && j<0){
            for(int ind  = 0;ind<=i;++ind){
                if(p[ind]!='*')return false;
            }
            return true;
        }
        
        if(dp[i][j]!=-1)return dp[i][j];
        // normal ans and ?
        // if(*) case 1 -> empty string i-1,j-1 || case 2 : treat as seq i,j-1
        if(p[i]==s[j] || p[i]=='?')return dp[i][j]=solve(i-1,j-1,p,s);
        else if(p[i]=='*')return dp[i][j]=solve(i-1,j,p,s) || solve(i,j-1,p,s);
        return dp[i][j]=false;
        
    }
    int wildCard(string pattern, string str) {
        // code here
        int p = pattern.size(),n = str.size();
        dp.resize(p+1,vector<int>(n+1,-1));
        return solve(p-1,n-1,pattern,str);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, text;
        cin >> pat;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> text;
        Solution obj;
        cout << obj.wildCard(pat, text) << endl;
    }
}

// } Driver Code Ends