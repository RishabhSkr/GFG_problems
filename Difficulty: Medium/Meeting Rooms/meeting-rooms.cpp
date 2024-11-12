//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    bool canAttend(vector<vector<int>> &arr) {
        // Your Code Here
        vector<vector<int>>meet;
        sort(arr.begin(),arr.end(),[](vector<int>a,vector<int>b){
            if(a[0]==b[0])return a[1]<b[1];
            return a[0]<b[0];
        });
        meet.push_back(arr[0]);
        for(int i = 1;i<arr.size();++i){
            int start = arr[i][0];
            int end = arr[i][1];
            int prevS = meet.back()[0];
            int prevE = meet.back()[1];
            if(max(start,prevS)<min(end,prevE))return false;
            else meet.push_back(arr[i]);
        }
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> arr(n);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            arr[i].push_back(x);
            arr[i].push_back(y);
        }
        cin.ignore();
        Solution obj;
        bool ans = obj.canAttend(arr);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends