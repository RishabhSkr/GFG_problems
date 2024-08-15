//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    set<string>st;
    int maxi;
    vector<vector<int>>dp;
    vector<vector<set<string>>>memo;
    void allLCS(int i, int j, string str, string &s, string &t) {
    // Base case: if we reach the start of either string
    if (i == 0 || j == 0) {
        // If we have a sequence of length equal to the maximum length
        if (str.size() == maxi) {
            st.insert(str);
        }
        return;
    }
    // already computed
    if(memo[i][j].find(str)!=memo[i][j].end())return ;

    // If characters match, include this character in the subsequence
    if (s[i - 1] == t[j - 1]) {
        allLCS(i - 1, j - 1, s[i - 1] + str, s, t);
    } else {
        // Explore both possibilities
        if (dp[i - 1][j] == dp[i][j]) {
            allLCS(i - 1, j, str, s, t);
        }
        if (dp[i][j - 1] == dp[i][j]) {
            allLCS(i, j - 1, str, s, t);
        }
        
    }
    memo[i][j].insert(str);
}
    vector<string> all_longest_common_subsequences(string s, string t) {
        // Code herei
        int n = s.size(),m = t.size();
        dp.resize(n+1,vector<int>(m+1,0));
        memo.resize(n+1,vector<set<string>>(m+1));
     
        for(int i =0;i<n;++i){
            for(int j =0;j<m;++j){  
                if(s[i]==t[j]){
                    dp[i+1][j+1]=1+dp[i][j];
                }else{
                    dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
                }
            }
        }
        maxi = dp[n][m];
        vector<string>res;
        allLCS(n,m,"",s,t);
        for(auto s:st)res.push_back(s);
        return res;
        
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        vector<string> ans = ob.all_longest_common_subsequences(s, t);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends