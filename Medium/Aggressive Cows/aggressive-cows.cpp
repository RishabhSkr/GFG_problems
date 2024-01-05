//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    bool placeCow(int mid,vector<int>&nums,int k){
        int cnt = k, n = nums.size();
        int lastPos = nums[0];
        for(int i=0 ;i<n; ++i){
           if(nums[i]-lastPos>=mid){
               cnt--;
               lastPos = nums[i];
           }
        }
        return cnt<=1;
    }
    int solve(int n, int k, vector<int> &nums) {
    
        // Write your code here
        int ans =-1;
        sort(nums.begin(),nums.end());
        int low = 1,high = nums[n-1];// sortibg because min dis can be adj stalls:
        while(low<=high){
            int mid  = low + (high-low)/2;
            if(placeCow(mid,nums,k)){
                ans = mid;
                low = mid +1;
            }
            else high = mid-1;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends