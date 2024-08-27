//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    /*You are required to complete this method */
    int findMaxDiff(vector<int> &arr) {
        // Your code here
        int n = arr.size();
        // get NSL and NSR
        vector<int>nsl(n,0),nsr(n,0);
        stack<int>st;
        // nsl
     
        for(int i =0;i<n;++i){
            while(!st.empty() && st.top()>=arr[i])st.pop();
            
            if(!st.empty())nsl[i]=st.top();
            
            st.push(arr[i]);
        }
        while(!st.empty())st.pop();
        for(int i =n-1;i>=0;--i){
            while(!st.empty() && st.top()>=arr[i]){
                st.pop();
            }
            if(!st.empty())nsr[i]=st.top();
            
            st.push(arr[i]);
        }
        
        //max diff
        int ans = 0;
        for(int i =0;i<n;++i){
            ans = max(ans ,abs(nsl[i]-nsr[i]));
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
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.findMaxDiff(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends