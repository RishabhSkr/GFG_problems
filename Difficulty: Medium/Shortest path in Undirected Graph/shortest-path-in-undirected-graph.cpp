//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<int>adj[N+1];
        
        for(auto edge : edges){
            int src= edge[0];
            int dest = edge[1];
            adj[src].push_back(dest);
            adj[dest].push_back(src);
        }
        vector<int>dist(N,INT_MAX);
        queue<pair<int,int>>q;
        dist[src]=0;
        q.push({src,0});
        int visited[N]={0};
        visited[src]=1;
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            int node = front.first;
            int dis = front.second;
            visited[node]=1;
            for(auto adjNode : adj[node]){
                if(dis+1<dist[adjNode] && !visited[adjNode]){
                    dist[adjNode]=dist[node]+1;
                    q.push({adjNode,dist[adjNode]});
                }
            }
        }
        for(auto &x : dist){
            if(x==INT_MAX)x=-1;
        }
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends