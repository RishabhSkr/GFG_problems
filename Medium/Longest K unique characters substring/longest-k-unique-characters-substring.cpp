//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
        int n = s.size();
        vector<int>mp(26,0);
        int cnt =0;
        int i =0;
        int maxLen = -1;
        for(int j = 0;j<n;++j){
            if(mp[s[j]-'a']==0)cnt++;
            mp[s[j]-'a']++;
            if(cnt>k){
                mp[s[i]-'a']--;
                if(mp[s[i]-'a']==0)cnt--;
                // if(mp[s[i]]==0)mp.erase(mp[s[i]]);
                i++;
            }
            // cout<<i<<j<<" "<<j-i+1<<endl;
            if(cnt==k)maxLen = max(maxLen,j-i+1);
        }
        return maxLen;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends