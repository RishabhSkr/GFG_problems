//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
//   We will keep 2 variables, one that will store maximum positive value - MAXI and one with minimum negative value - MINI.
// We will keep sure that MAXI, is always greater than equal to 1 and MINI is always less than equal to 1
// Now there are 3 cases:
// if arr[i] > 0, then MAXI is MAXI*arr[i], and MINI is min(MIN*arr[i], 1)
// if arr[i] == 0, then we need to see for another subarray, and make MAXI = MINI = 1
// if arr[i]<0, then MAXI becomes max(MINI*arr[i],1) and MINI becomes MAXI* arr[i]
// For every iteration MAXI stores the maximum value so far, so keep another variable OVERALLMAX to store max of all MAXIs.
// Print OVERALLMAX.
    // Function to find maximum product subarray
    int maxProduct(vector<int> &arr) {
        // Your Code Here
        int prefix = 1,suffix = 1;
        int n = arr.size();
        int ans = INT_MIN;
        for(int i = 0;i<n;++i){
            if(prefix==0)prefix = 1;
            if(suffix==0)suffix = 1;
            prefix *=arr[i];
            suffix *=arr[n-i-1];
            ans = max({ans,prefix,suffix});
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // int n, i;
        // cin >> n;
        // vector<int> arr(n);
        // for (i = 0; i < n; i++) {
        //     cin >> arr[i];
        // }

        vector<int> arr;
        string input;

        // Read array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        auto ans = ob.maxProduct(arr);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends