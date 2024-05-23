//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool isSafe(bool graph[][101],int c,int v,int n,int *color){
        for(int j = 0;j<n;++j){
            if(graph[v][j]==1 && color[j]==c)return false;
        }
        return true;
    }
    bool solve(bool graph[][101],int m,int n,int v,int *color){
        if(v== n){
           return true;
        }
        for(int c = 0;c<m;++c){
            if(isSafe(graph,c,v,n,color)){
                color[v]= c;
                if(solve(graph,m,n,v+1,color))return true;
            }
        }
        return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        int arr[n];
        memset(arr,-1,sizeof(arr));
        return solve(graph,m,n,0,arr);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends