//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
  void dfs(vector<int>adj[],vector<int>&vis,int node){
      vis[node]=1;
      for(auto it : adj[node]){
          if(!vis[it]){
              dfs(adj,vis,it);
          }
      }
  }
  
//   bool isConnected(vector<int>adj[],int V){
//       int nonZeroDegreeVer = -1;
//      for(int i = 0;i<V;++i){
//          if(adj[i].size()>0){
//              nonZeroDegreeVer =i;
//              break;
//          }
//      }
//      vector<int>vis(V,0);
     
//      // apply the dfs to all nonZero are visited
//      dfs(adj,vis,nonZeroDegreeVer);
     
//      for(int i =0 ;i<V;++i){
//          if(adj[i].size()>0 && vis[i]==0)return false;
//      }
     
//      return true;
//   }
    int isCircle(vector<string> &arr) {
     vector<int>adj[26];
     vector<int>outdegree(26,0),indegree(26,0);
     for(auto s : arr){
        int u =s[0]-'a';
        int v = s.back()-'a';
        adj[u].push_back(v);
        outdegree[u]++;
        indegree[v]++;
     }
     // step:2 : //check if indegree and outdegree is same 
     for(int i =0;i<26;++i){
         if(indegree[i]!=outdegree[i])return 0;
     }
     
     // step:3 // non degree vertex all are connected or not
    //  if(!isConnected(adj,26))return 0;
     // mark all the vertex visited
     vector<int>vis(26,0);
     int start = arr[0][0]-'a';
     dfs(adj,vis,start);
     
     // // Step 4: Ensure all nodes with non-zero in-degree or out-degree are visited
     for(int i = 0;i<26;++i){
         if(indegree[i]>0 && outdegree[i]>0 && vis[i]==0)return 0;
     }
     return 1;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> A;
        string s;

        for (int i = 0; i < N; i++) {
            cin >> s;
            A.push_back(s);
        }

        Solution ob;
        cout << ob.isCircle(A) << endl;
    }
    return 0;
}
// } Driver Code Ends