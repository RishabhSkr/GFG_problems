//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        // code here
        //from right find the first non decreasing ele towards left
        // next find the element that is just greater than tha left decreasing ele
        // swap it after that reverse all the numb from left+1 to right.
        
        int n= arr.size();
        
        int left = n-2,right = n-1;
        
        while(left>=0 && arr[left]>=arr[right]){
            left--;
            right--;
        }
        
        if(left>=0){
            right = n-1;
            while(arr[left]>=arr[right]){
                right--;
            }
            swap(arr[right],arr[left]);
        }
        reverse(arr.begin()+left+1,arr.end());
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int n = arr.size();
        ob.nextPermutation(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends