//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums) {

        // code here
        int n = nums.size();
        vector<long long int>dp;
        long long int sum = 1,zero=0;
        for(int i =0;i<n;++i){
            if(nums[i]==0)zero++;
            else sum*=nums[i];
        }
        for(int i =0;i<n;++i){
            if(zero>1)dp.push_back(0);
            else if(zero==1 && nums[i]==0)dp.push_back(sum);
            else if(zero==1 && nums[i]!=0)dp.push_back(0);
            else dp.push_back(sum/nums[i]);
        }
        return dp;
    }
};


//{ Driver Code Starts.
int main() {
    int t; // number of test cases
    cin >> t;
    while (t--) {
        int n; // size of the array
        cin >> n;
        vector<long long int> arr(n), vec(n);

        for (int i = 0; i < n; i++) // input the array
        {
            cin >> arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr); // function call

        for (int i = 0; i < n; i++) // print the output
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends