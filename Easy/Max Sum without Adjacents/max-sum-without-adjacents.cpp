//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
// 	int ans=INT_MIN;
// 	int solve(int *arr,int n){
// 	    if(n<0)return 0;
// 	    int sum =0;
// 	    sum =arr[n]+solve(arr,n-2); 
// 	    return ans=max(sum,ans);
// 	}
	 //2 vairableapproach
	int findMaxSum(int *arr, int n) {
	    // code here
	    int preMax = 0,currMax=0;
	    for(int i=0 ; i<n;++i){
	        int temp= max(preMax + arr[i],currMax);
	        preMax=currMax;
	        currMax= temp;
	    }
            return currMax;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends