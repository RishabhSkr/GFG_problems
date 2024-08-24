//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int LongestBitonicSequence(int n, vector<int> &nums) {
        // code here
        
        vector<int>dp(n,1),dp1(n,1),diff(n,0);
        // logic take LIS from left and Take LIS from reverse ordre or from right 
        // take add the LIS val at i of both dp  and do minus 1 because adding common lement two times
        // return max
        // LIS from LEFT
        for(int i = 1;i<n;i++){
           for(int j = i-1;j>=0;--j){
                if(nums[i]>nums[j] && dp[i]<1+dp[j]){
                    dp[i]= 1+dp[j];
                }
           }
        }
        //LIS from right -? it will give LDS
        int maxi =0;
        for(int i = n-2;i>=0;i--){
           for(int j = n-1;j>i;--j){
                if(nums[i]>nums[j] && dp1[i]<1+dp1[j]){
                    dp1[i]= 1+dp1[j];
                }
           }
           if(dp[i]==1 || dp1[i]==1)continue;
           maxi= max(maxi,dp1[i]+dp[i]-1);
        }
        
        
        return maxi;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        vector<int> nums(n);
        Array::input(nums, n);

        Solution obj;
        int res = obj.LongestBitonicSequence(n, nums);

        cout << res << endl;
    }
}

// } Driver Code Ends