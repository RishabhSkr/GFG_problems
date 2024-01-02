//{ Driver Code Starts
// C++ program to find largest subarray sum with
// at-least k elements in it.
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    #define lli long long int
    long long int maxSumWithK(long long int a[], long long int n, long long int k) 
    {
        vector<lli>dp(n);
        dp[0]=a[0];
        for(int i = 1;i<n;++i){
           dp[i] = max(dp[i-1]+a[i],a[i]);
        }
        
        lli windowk=0,maxSum=0;
        for(int i =0;i<k;++i){
            windowk+=a[i];
        }
        maxSum = windowk;
        for(int i = k ;i<n;++i){
            windowk= windowk-a[i-k]+a[i];
            maxSum = max(maxSum,windowk);
            maxSum = max(maxSum,windowk+dp[i-k]);
        }
        return maxSum;
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    long long int t;
    cin >> t;
    while (t--) {
        long long int n, k, i;
        cin >> n;
        long long int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> k;
        Solution ob;
        cout << ob.maxSumWithK(a, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends