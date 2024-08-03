//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    // https://medium.com/@joylovemercy/277-find-the-celebrity-linear-comparison-o-n-step-by-step-explanation-w-graph-8928230c6e
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int n = mat.size();
        
        int cand = 0;
        for(int j =0;j<n;++j){
            if(mat[cand][j])cand = j;
        }
        for(int k = 0;k<n;++k){
            if(cand==k)continue;
            if(mat[cand][k]==1 || mat[k][cand]==0)return -1;
        }
        return cand;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
    }
}

// } Driver Code Ends