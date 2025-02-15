//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        int vertexCover(int n, vector<pair<int, int>> &edges) {
                // code here
                if(n==0)return 0;
                vector<pair<int,int>>first_vertex_edges,second_vertex_edges;
                int first_vertex = edges[0].first;
                int second_vertex=edges[0].second;
                int count_first_vertex =0,count_second_vertex =0;
                
                for(auto edge : edges){
                    int u= edge.first;
                    int v=edge.second;
                    
                    if(!(u==first_vertex || v == first_vertex)){
                        first_vertex_edges.push_back({u,v});
                        count_first_vertex++;
                    }
                    
                    if(!(u==second_vertex || v == second_vertex)){
                        second_vertex_edges.push_back({u,v});
                        count_second_vertex++;
                    }
                    
                }
                return 1+min(
                    
                    vertexCover(count_first_vertex,first_vertex_edges),
                    vertexCover(count_second_vertex,second_vertex_edges)
                    
                    );
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<pair<int,int>> edges;
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            edges.push_back({a,b});
        }
        Solution s;
        cout<<s.vertexCover(n,edges)<<endl;
    }
    return 0;
}
// } Driver Code Ends