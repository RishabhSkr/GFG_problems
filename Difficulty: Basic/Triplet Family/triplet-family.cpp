//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool findTriplet(vector<int>& arr) {
        // Your code
        // x+y== k
        sort(arr.begin(),arr.end());
        int n = arr.size();
        for(int i =0;i<n;++i){
            for(int j =i+1;j<n;++j){
                int sum = arr[i]+arr[j];
                int s = 0 ,e = n-1;
                while(s<=e){
                    int mid = s+(e-s)/2;
                    if(arr[mid]==sum)return true;
                    if(arr[mid]<sum){
                        s=mid+1;
                    }else e=mid-1;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        bool res = obj.findTriplet(arr);
        if (res)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        // cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends