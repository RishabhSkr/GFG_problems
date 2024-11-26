//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // arr: input array
    // Function to find maximum circular subarray sum.
     int kadaneMax(vector<int>&nums){
        int currSum = nums[0];
        int maxSum = nums[0];
        int n = nums.size();
        for(int i =1;i<n;++i){
            currSum = max(nums[i],currSum+nums[i]);
            maxSum = max(currSum,maxSum);
        }
        return maxSum;
    }
    int kadaneMin(vector<int>&nums){
        int currSum = nums[0];
        int minSum = nums[0];
        int n = nums.size();
        for(int i =1;i<n;++i){
            currSum = min(nums[i],currSum+nums[i]);
            minSum = min(currSum,minSum);
        }
        return minSum;
    }
    // logic ->maxSubarr using kadane in array we can find easliye 
    // now case 2 if maxSubarr in circular arr around edge -> how can be solve
    // suppos we know if we find minSumsubarray -> using kadanes in a array we get the total-minSbarr= maxSub around edges because s1+s2=total(s1 maxSubarray around corners and s2 min subarra in array,)
    // max will max(maxSubarr,total-minsubarr) if minSumsub!=total otherwise maxSubarr will be ans
    int circularSubarraySum(vector<int> &nums) {

        // your code here
          int total =0;
        for(int i =0;i<nums.size();++i)total+=nums[i];
        int maxSumSubarr = kadaneMax(nums);
        int minSumSubarr = kadaneMin(nums);
        if(total==minSumSubarr)return maxSumSubarr;
        return max(maxSumSubarr,total-minSumSubarr); 
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.circularSubarraySum(arr);

        cout << res << endl;
    }
    return 0;
}

// } Driver Code Ends