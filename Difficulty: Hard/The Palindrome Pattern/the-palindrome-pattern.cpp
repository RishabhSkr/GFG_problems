//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
bool isPall(int i,int j,vector<int>&mat){
    while(i<=j){
        if(mat[i]!=mat[j])return false;
        i++,j--;
    }
    return true;
}
bool isPallCol(int col,int n,vector<vector<int>>&mat){
    int i =0,j =n-1;
    // Start from the top and bottom of the column
    while(i<=j){
        if(mat[i][col]!=mat[j][col])return false;
        i++,j--;
    }
    return true;
}
    string pattern(vector<vector<int>> &mat) {
        // Code Here
        int n = mat.size();
        string ans ="";
        bool flag = false;
        for(int i =0;i<n;++i){
            if(isPall(0,n-1,mat[i])){ // it should be 0 to n-1 // not i to n-1
                ans=to_string(i)+" R";
                flag = true;
                break;
            }
        }
        if(!flag){
            for(int i =0;i<n;++i){
                if(isPallCol(i,n,mat)){
                    ans=to_string(i)+" C";
                    break;
                }
            }
        }
        if(ans.empty())return "-1";
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t, n, i, j, flag, k;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++)
                cin >> a[i][j];
        }
        Solution ob;
        cout << ob.pattern(a) << endl;
    }
    return 0;
}
// } Driver Code Ends