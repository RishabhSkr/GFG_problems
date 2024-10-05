//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    int n ,m;
    bool isSafe(int i,int j,vector<vector<char>>&grid){
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]=='0')return false;
        return true;
    }

    void solve(int i,int j,vector<vector<char>>&grid){
        grid[i][j]='0';
        for(int dx=-1;dx<=1;++dx){
            for(int dy =-1;dy<=1;++dy){
                if(dx==0 && dy==0)continue;
                int newx = i+dx;
                int newy = j+dy;
                if(isSafe(newx,newy,grid)){
                    solve(newx,newy,grid);
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int ans = 0;
        n= grid.size();
        m = grid[0].size();
        for(int i =0;i<n;++i){
            for(int j =0;j<m;++j){ 
                if(grid[i][j]=='1'){
                    solve(i,j,grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends