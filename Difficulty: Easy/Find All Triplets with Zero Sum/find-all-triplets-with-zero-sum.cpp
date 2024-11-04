//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    vector<vector<int>> findTriplets(vector<int> &arr) {
        int n = arr.size();
        if(n < 3) return {};
        vector<vector<int>> ans;
        
        unordered_map<int, vector<int>> mp;
        // First add all elements after i to the map
        for(int k = 0 ; k < n; k++) {
            mp[arr[k]].push_back(k);
        }
        
        for(int i = 0; i < n; ++i) {
            
            // Now check for pairs
            for(int j = i + 1; j < n; j++) {
                
                int sum = -1*(arr[i] + arr[j]) ;
                
                for( int k : mp[sum]){
                    if(k>j)ans.push_back({i, j,k}) ;
                }
             
            }
        }
        return ans;
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

        vector<vector<int>> res = ob.findTriplets(arr);
        sort(res.begin(), res.end());
        if (res.size() == 0) {
            cout << "[]\n";
        }
        for (int i = 0; i < res.size(); i++) {
            for (int j = 0; j < res[i].size(); j++) {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends