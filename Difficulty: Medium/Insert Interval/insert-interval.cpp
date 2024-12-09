//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> insertInterval(vector<vector<int>> &interval,
                                       vector<int> &newInt) {
        // code here
        int n =interval.size();
        vector<vector<int>>ans;
       // pagle non overlapping interval insert kro
       int i =0;
       while(i<n && interval[i][1]<newInt[0]){
           ans.push_back(interval[i++]);
       }
       // merged interval insert kro
       while(i<n && max(interval[i][0],newInt[0])<=min(interval[i][1],newInt[1])){
           newInt[0]=min(interval[i][0],newInt[0]);
           newInt[1]=max(interval[i][1],newInt[1]);
           i++;
       }
       ans.push_back(newInt);
       // merged interval se bade ya remaining interval insert kro
       while(i<n){
           ans.push_back(interval[i++]);
       }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> intervals(N, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0] >> intervals[i][1];
        }
        vector<int> newInterval(2);
        cin >> newInterval[0] >> newInterval[1];

        Solution obj;
        vector<vector<int>> ans = obj.insertInterval(intervals, newInterval);
        cout << "[";
        for (int i = 0; i < ans.size(); i++) {
            cout << "[" << ans[i][0] << ',' << ans[i][1] << ']';
            if (i != (ans.size() - 1))
                cout << ",";
        }
        cout << "]" << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends