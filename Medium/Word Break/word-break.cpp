//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// s : given string to search
// dictionary : vector of available strings

class Solution
{
public:
    unordered_set<string>dict;
    bool solve(int ind,string &s){
        if(ind == s.length())return true;
       bool flag =false;
       string prefix = "";
       for(int i = ind ;i<s.length();++i){
           prefix+=s[i];
           if(dict.find(prefix)!=dict.end()){
               flag = flag||solve(i+1,s);
           }
       }
       return flag;
    }
    int wordBreak(int n, string s, vector<string> &dictionary) {
       
        for(auto x : dictionary){
            dict.insert(x);
        }
        return solve(0,s);
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dictionary;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dictionary.push_back(S);
        }
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.wordBreak(n, s, dictionary)<<"\n";
    }
}

// } Driver Code Ends