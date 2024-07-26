//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int countMin(string s1){
    //complete the function here
        string s2 =s1;
        reverse(s2.begin(),s2.end());
        int n = s1.size();
        
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        
        for(int i =0;i<n;++i){
            for(int j =0;j<n;++j){
                if(s1[i]==s2[j]){
                    dp[i+1][j+1]= 1+dp[i][j];
                }else{
                    dp[i+1][j+1]= max(dp[i+1][j],dp[i][j+1]);
                }
            }
        }
        int notCommon = n-dp[n][n];
        return notCommon;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends