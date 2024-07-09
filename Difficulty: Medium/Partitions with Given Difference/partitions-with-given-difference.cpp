//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
vector<vector<int>> dp;
int mod = 1e9+7;

int solve(int i, int sum, vector<int>& arr) {
    // Base cases
    if (sum < 0) return 0; // sum should not be negative
    if (i == 0) {
        if (sum == 0 && arr[0] == 0) return 2; // edge case: both subsets could be empty
        if (sum == 0 || sum == arr[0]) return 1;
        return 0;
    }
    if (dp[i][sum] != -1) return dp[i][sum];

    int notTake = solve(i - 1, sum, arr); // not including current element
    int take = 0;
    if (sum >= arr[i]) take = solve(i - 1, sum - arr[i], arr); // including current element

    return dp[i][sum] = (take % mod + notTake % mod) % mod;
}

int countPartitions(int n, int d, vector<int>& arr) {
    int total = 0;
    for (auto x : arr) total += x;
    
    // sum of subsets should be non-fractional
    if ((total + d) % 2 != 0) return 0;
    
    int target = (total + d) / 2;
    dp.resize(n, vector<int>(target + 1, -1));
    return solve(n - 1, target, arr);
}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends