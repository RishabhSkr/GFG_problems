//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  // T.C->O(n),S.C>O(n)
 #define ll long long 
    ll dp[4][3][26];  // Memoization table
    int dirn[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};  // Directions for movement
    ll solve(int i, int j, int n, int input[4][3]) {
        if (n == 1) {
            return 1;  // Base case: only one digit sequence
        }
        if (dp[i][j][n] != -1) return dp[i][j][n];  // Return precomputed result
        
        ll total = 0;
        total += solve(i, j, n - 1, input);  // Count sequences starting from the current digit
        
        for (int k = 0; k < 4; ++k) {
            int newx = i + dirn[k][0];
            int newy = j + dirn[k][1];
            if (newx >= 0 && newx < 4 && newy >= 0 && newy < 3 && input[newx][newy] != -1) {
                total += solve(newx, newy, n - 1, input);  // Explore all 4 directions
            }
        }
        
        return dp[i][j][n] = total;  // Store the result in the memoization table
    }
    
    long long getCount(int n) {
        int input[4][3] = {
           {1, 2, 3},
           {4, 5, 6},
           {7, 8, 9},
           {-1, 0, -1}
        };
        memset(dp, -1, sizeof(dp));  // Initialize the memoization table with -1
        
        ll cnt = 0;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (input[i][j] == -1) continue;  // Skip invalid positions
                cnt += solve(i, j, n, input);  // Count sequences starting from each valid position
            }
        }
        return cnt;
    }

};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}

// } Driver Code Ends