//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> topoSort(int V, vector<int> adj[]){
		int indegree[V] = {0};
		for (int i = 0; i < V; i++) {
			for (auto it : adj[i]) {
				indegree[it]++;
			}
		}

		queue<int> q;
		for (int i = 0; i < V; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}
		vector<int> topo;
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			topo.push_back(node);
			// node is in your topo sort
			// so please remove it from the indegree

			for (auto it : adj[node]) {
				indegree[it]--;
				if (indegree[it] == 0) q.push(it);
			}
		}

		return topo;
	}
    string findOrder(string dict[], int n, int k) {
        // code here
        // graph making->adj list
        // understand the topo sort algorithm and how to apply here to find out 
        // apply kahn algo
        // reverse topo  and return it;
        
        
        // what are two testcase where this topo sortis not possible 
        // 1. when abc bca abd not possible a<b<a  i.e cycle present
        // 2. when testcase abc comes after abcd that invalid dict.
        
        vector<int>adj[k]; // k size ka graph construct krna h  na ki n size ka
        
        // Build the graph
        for(int i = 0; i < n - 1; ++i) {
            string s1 = dict[i];
            string s2 = dict[i + 1];
            int len1 = s1.length();
            int len2 = s2.length();
            int len = min(len1, len2);
    
            for(int k = 0; k < len; ++k) {
                if(s1[k] != s2[k]) {
                    // Edge from s1[k] to s2[k]
                    adj[s1[k] - 'a'].push_back(s2[k] - 'a');
                    break;
                }
            }
        }

        vector<int>ans = topoSort(k,adj);

        string res = "";
        for(auto x : ans){
            res+=char(x+'a');
        }
        return res;
    }
};

//{ Driver Code Starts.
string order;

bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size())
        return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++)
            cin >> dict[i];

        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++)
            order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i])
                f = false;

        if (f)
            cout << 1;
        else
            cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends