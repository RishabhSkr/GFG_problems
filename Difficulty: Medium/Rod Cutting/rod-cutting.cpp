//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
 vector<vector<int>>dp;
//   int solve(int ind,int L , int *price){
//       // base case  
//       if(ind==0)
//         return L*price[0];  // we reach the index 0 that is 
// //  len =1 and we requred rod of N rem so val= N*rod[0] ->rod len 1 price *N required to make
//       int notTake = solve(ind-1,L,price);
//       int take=INT_MIN;
//       int rodLen = ind+1;
//       if(dp[ind][L]!=-1)return dp[ind][L];
//       if(rodLen<=L){
//           take = price[ind]+solve(ind,L-rodLen,price);
//       }
//       return dp[ind][L]=max(take,notTake);
//   }
    int cutRod(int price[], int n) {
        //code here
        dp.resize(n,vector<int>(n+1,0));
        // base case 
        for(int i =0;i<=n;++i){
            dp[0][i]=i*price[0];
        }
        for(int i =1;i<n;++i){
            for(int len = 0;len<=n;++len){
                int notTake =dp[i-1][len];
                  int take=INT_MIN;
                  int rodLen =i+1;
                  if(rodLen<=len){
                      take = price[i]+dp[i][len-rodLen];  // current len -rodlen
                  }
                  dp[i][len]=max(take,notTake);   
            }
        }
        return dp[n-1][n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends