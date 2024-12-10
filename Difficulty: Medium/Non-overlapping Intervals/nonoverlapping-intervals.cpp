//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minRemoval(vector<vector<int>> &intervals) {
        // code here
        /*
            agar hm interval to end time ke basis par sort kr de
            to  agr overlap hua nhi lenge
            nhit select kreng
        isse min removal ki guarantee high(sorting +greedy(end time ke base sort kren))
        Example:
        Agar aapke intervals hain: {{1, 2}, {2, 3}, {3, 4}, {1, 3}}
        
        Sort karne ke baad: {{1, 2}, {1, 3}, {2, 3}, {3, 4}}
        Pehle interval {1, 2} ko select karte hain.
        {1, 3} overlap karta hai {1, 2} ke saath, toh remove karte hain.
        {2, 3} overlap nahi karta {1, 2} ke saath, toh select karte hain.
        {3, 4} overlap nahi karta {2, 3} ke saath, toh select karte hain.
        */
        sort(begin(intervals),end(intervals),[](vector<int>&a,vector<int>&b){
            return a[1]<b[1];
        });
        
        int n = intervals.size();
        int cnt =0;
        int end = intervals[0][1];
        
        for(int i =1;i<n;++i){
            
            int start = intervals[i][0];
            if(start<end){ // agr uss interval remove kr rhe h to uska end time update nhi krengen na
                cnt++;
            }else{
                end=intervals[i][1];
            }
           
        }
        return cnt;
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
        Solution obj;
        cout << obj.minRemoval(intervals) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends