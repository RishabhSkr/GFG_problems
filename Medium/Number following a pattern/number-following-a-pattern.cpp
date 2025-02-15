//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string s){
       
       int n = s.length();
       stack<int>st;
       string ans= "";
       for(int i =0 ;i<=n;++i){
           st.push(i+1);
           if(s[i]=='I' || i==n){
               while(!st.empty()){
                   ans+=to_string(st.top());
                   st.pop();
               }
           }
       }
       return ans;
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 

// } Driver Code Ends