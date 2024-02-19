//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        unordered_map<int,int> mp;
        for (int i = 0; i < s.size(); i++)
        {
            mp[s[i]]++;
        }
        
        vector<int> v;
        for (auto it : mp)
        {
            v.push_back(it.second);
        }
        sort(v.rbegin(), v.rend());
        
        while(k--)
        {
            v[0] = v[0] - 1;
        sort(v.rbegin(), v.rend());
            if (v[0]==0) break;
        }
        
        int sum = 0;
        for (int i = 0; i < v.size(); i++) sum += pow(v[i],2);
        
        return sum;
        
        
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends