//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string s) {
        
        int i =0,j = 0;
        int n = s.length();
        int zero =0,one = 0,two = 0;
        int minlen=INT_MAX;
        while(j<n){
            
            if(s[j]=='0')
                zero++;
            
            else if(s[j]=='1')
                one++;
            
            else 
                two++;
            
            
            while(zero>0 && one>0 && two>0){
                
                minlen = min(minlen,j-i+1);
                
                if(s[i]=='0')zero--;
                else if(s[i]=='1')one--;
                else two--;
                i++;
                
            }
            
            j++;
        }
        
        // if(zero==0 || one==0 || two==0)return -1;
        return (minlen == INT_MAX)?-1:minlen;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}
// } Driver Code Ends