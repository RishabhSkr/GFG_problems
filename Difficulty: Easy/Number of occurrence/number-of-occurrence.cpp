//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countFreq(vector<int>& arr, int tar) {
        // code here
        // O(n) Approach O(1) simple iterate and count
        // Expected Approach-> Bin Search (logn)
        // Algo :
            // find just greater num > tar and lower num  less than the target using BS
            // diff of their indexes given cnt of target
        
        int n = arr.size();
        int lo = 0 ,hi = n-1;
        int lower = -1;
        
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(arr[mid]==tar){
                lower = mid;
                hi = mid-1;
            }
            else if(arr[mid]>tar){
                hi= mid-1;
            }else lo = mid+1;
        }
        
        if(lower==-1)return 0;
        int high= -1;
        
        lo = 0,hi = n-1;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(arr[mid]==tar){
                high = mid;
                lo = mid+1;
            }
            else if(arr[mid]>tar){
                hi= mid-1;
            }else lo = mid+1;
        }
        return (high-lower+1);
        
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.countFreq(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends