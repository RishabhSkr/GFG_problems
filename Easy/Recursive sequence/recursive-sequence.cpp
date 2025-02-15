//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    long long sequence(int n){
        // code here
        long long mod = 1000000007;
        long long cnt= 1;
        long long res = 0;
        
        for(int i=1; i<=n; i++){
           long long ans = 1;
            for(int j=0; j<i; j++){
                ans = (ans * cnt)%mod;
                cnt++;
            }
            res = (res + ans)%mod;
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.sequence(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends