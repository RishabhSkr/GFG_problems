//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    //   static bool compare(const pair<pair<int,int>,int> &a, const pair<pair<int,int>,int> &b){
    //     return a.first.second < b.first.second; // Compare based on end times
    // }

    vector<int> maxMeetings(int n, vector<int> &s, vector<int> &f){
        vector<pair<pair<int,int>,int>> events;
        for(int i = 0; i < n; ++i){
            events.push_back({{f[i], s[i]}, i+1});
        }
        sort(events.begin(), events.end());
        vector<int> result;
 
        int end = events[0].first.first;
        
        result.push_back(events[0].second);
        for(int i=1;i<n;++i){
            if(events[i].first.second>end){
                result.push_back(events[i].second);
                end = events[i].first.first;
            }
        }
        sort(result.begin(),result.end());
       
        return result;
        
    }

};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends