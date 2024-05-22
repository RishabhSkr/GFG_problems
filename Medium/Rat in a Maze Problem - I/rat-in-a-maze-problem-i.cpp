//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
public:
    int dirn[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};
    unordered_map<string, string> mp = {{"10","D"}, {"-10","U"}, {"0-1","L"}, {"01","R"}};
    vector<string> res;
    
    bool isSafe(int i, int j, int n, vector<vector<int>>& mat){
        return (i >= 0 && i < n && j >= 0 && j < n && mat[i][j] == 1);
    }
    
    void solve(int i, int j, int n, vector<vector<int>>& mat, string op){
        if(i == n-1 && j == n-1){
            res.push_back(op);
            return;
        }
        
        mat[i][j] = 0;
        for(auto dir : dirn){
            int newx = i + dir[0];
            int newy = j + dir[1];
            if(isSafe(newx, newy, n, mat)){
                string key = to_string(dir[0])+to_string(dir[1]);
                solve(newx, newy, n, mat, op + mp[key]);
            }
        }
        mat[i][j] = 1; 
    }
    
    vector<string> findPath(vector<vector<int>> &mat, int n) {
        // Your code goes here
        if(mat[0][0] == 0 || mat[n-1][n-1] == 0) return {};
        solve(0, 0, n, mat, "");
        return res;
    }
};


    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends