//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// long long int maxSum(int arr[], int n);

// } Driver Code Ends
class Solution {
  public:
    #define ll long long
    long long maxSum(vector<int>& arr) {
        // code here 1 2 4 8
        sort(arr.begin(),arr.end());
        int n = arr.size();
        
        ll sum = 0;
        int j = n-1,i =0;
        for(int i =0;i<j;i+=2,j-=2){
            swap(arr[i],arr[j]);
        }
        
        for(int i =0;i+1<n;++i){
            sum+=abs(arr[i]-arr[i+1]);
            
        }
        sum+=abs(arr[0]-arr[n-1]);
        return sum;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }

        Solution ob;
        long long ans = ob.maxSum(arr);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends