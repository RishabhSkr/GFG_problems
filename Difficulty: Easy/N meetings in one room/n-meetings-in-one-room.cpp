//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(int n, int start[], int end[]) {
        // Your code here
        vector<vector<int>>meet;
        for(int i =0;i<n;++i){
            meet.push_back({end[i],start[i]});
        }
        sort(meet.begin(),meet.end());
        vector<vector<int>>ans;
        ans.push_back({meet[0][1],meet[0][0]});
        for(int i =1;i<n;++i){
            int start = meet[i][1];
            int end = meet[i][0];
            if(start>ans.back()[1])ans.push_back({start,end});
           
        }
        return ans.size();
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++)
            cin >> start[i];

        for (int i = 0; i < n; i++)
            cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(n, start, end);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends