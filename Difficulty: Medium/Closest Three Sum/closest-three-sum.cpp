//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

// arr : given vector of elements
// target : given sum value

class Solution {
  public:
    int threeSumClosest(vector<int> arr, int target) {
        // Your code goes here
        sort(arr.begin(),arr.end());
        int n = arr.size();
        int ans =INT_MIN;
        int minDif=INT_MAX;
        for(int  i=0;i+2<n;++i){
            int j = i+1,k = n-1;
            while(j<k){
                int sum = arr[j]+arr[k]+arr[i];
                int diff = abs(sum-target); 
                if(diff<=minDif){
                    if(diff==minDif)ans=max(sum,ans);
                    else ans = sum;
                    minDif = diff;
                }
                if(sum>target)
                    k--;
                else
                    j++;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        // cin.ignore();
        // if (f)
        //     return 0;
        Solution ob;
        cout << ob.threeSumClosest(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends