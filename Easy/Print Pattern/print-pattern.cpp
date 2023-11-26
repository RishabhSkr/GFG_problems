//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void print(vector<int>& ans, int curr){
        if(curr <= 0){
            ans.push_back(curr);
            return;
        }
        
        ans.push_back(curr);
        print(ans, curr-5);
    }
    
    void print2(vector<int>& ans, int curr, int original){
        if(curr == original){
            ans.push_back(curr);
            return ;
        }
        
        ans.push_back(curr);
        print2(ans, curr+5, original);
    }

    vector<int> pattern(int N){
        if(N <= 0 ) return {N};
        vector<int> ans;
        ans.push_back(N);
        print(ans, N-5);
        print2(ans, ans.back()+5, N);
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.pattern(N);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends