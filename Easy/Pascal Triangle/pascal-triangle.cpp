//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// #define ll long long
class Solution{
public:
vector<long long> nthRowOfPascalTriangle(int n) {
        // code here
        if(n==1) return {1};
        long long mod=1e9+7;
        vector<long long>ans={1, 1};
        if(n==2) return ans;
        for(int i=3; i<=n; i++){
            vector<long long>temp(i, 1);
            for(int j=1; j<=i-2; j++){
                temp[j]=(ans[j-1]+ans[j])%mod;
            }
            ans=temp;
        }
        return ans;
    }
};


//{ Driver Code Starts.


void printAns(vector<long long> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends