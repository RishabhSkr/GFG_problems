//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
// An Euler path is a path that passes through every edge exactly once. 
// If it ends at the initial vertex then it is an Euler cycle.

// A Hamiltonian path is a path that passes through every vertex exactly once (NOT every edge). 
// If it ends at the initial vertex then it is a Hamiltonian cycle.

	int isPossible(vector<vector<int>>paths){
	    // Code here
	    int n = paths.size();
	    
	    for(int i =0 ;i<n;++i){
	        int  cnt = 0;
	        for(int j =0 ;j<n;++j){
	            if(paths[i][j]==1)cnt++;
	        }
	        if(cnt%2!=0)return false;
	    }
	    return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>paths(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				cin >> paths[i][j];
		}
		Solution obj;
		int ans = obj.isPossible(paths);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends