//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int,int>>meet;
        for(int i=0;i<n;++i){
            meet.push_back({end[i],start[i]});
        }
        sort(meet.begin(),meet.end());
        vector<pair<int,int>>ans;
        ans.push_back({meet[0].second,meet[0].first});
        for(int i=1;i<n;++i){
            int start  =meet[i].second;
            int end  =meet[i].first;
            if(start>ans.back().second){
                ans.push_back({start,end});
            }
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
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends