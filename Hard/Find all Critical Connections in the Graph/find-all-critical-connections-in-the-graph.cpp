//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    	

	int timer=1;
    void dfs(int node ,int parent,vector<int>adj[],vector<int>&vis,vector<int>&low,vector<int>&tin,vector<vector<int>>&bridges){
        vis[node]=1;
        tin[node]=low[node]=timer;
        timer++;
        for(auto it: adj[node]){
            if(parent==it)continue;
            if(vis[it]==0){
                dfs(it,node,adj,vis,low,tin,bridges);
                low[node] = min(low[node],low[it]);
                
                if(low[it]>tin[node]){
                    if(it<node)
                    bridges.push_back({it,node});
                    else 
                    bridges.push_back({node,it});
                }
                
            }
            else{
                    low[node]=min(low[node],low[it]);
            }
        }
    }
	vector<vector<int>>criticalConnections(int n, vector<int> adj[]){
	    // Code here
	  vector<int>vis(n,0),low(n,0),tin(n,0);
      vector<vector<int>>bridges;
      dfs(0,-1,adj,vis,low,tin,bridges);
      sort(bridges.begin(),bridges.end());
      return bridges;
	    
	}
};

//{ Driver Code Starts.

int main(){
	int tc;
    cin >> tc;
    while(tc--){
        int V, E;
        cin >> V >> E;
        vector<int>adj[V];
        for(int i = 0; i < E; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        vector<vector<int>>ans = obj.criticalConnections(V, adj);
        
        for(int i=0;i<ans.size();i++)
            cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }
	return 0;
}
// } Driver Code Ends