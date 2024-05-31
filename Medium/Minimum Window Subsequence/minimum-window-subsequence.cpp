//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string minWindow(string str1, string str2) {
        // Write your Code here
        int i =0;
        int n = str1.length(),m = str2.length();
        if(n<m)return "";
        int minLen = INT_MAX;
        int startInd =-1,patternInd=0;
        int cnt =0;
        for(int j=0;j<n;++j){
            if(str1[j]==str2[patternInd])patternInd++;
        
            
            if(patternInd == m){
                i=j;  // back match kro
                patternInd=m-1;
                while(patternInd>=0 && i>=0){
                    if(str1[i]==str2[patternInd])patternInd--;
                    i--;
                }
                i+=1;
                if(minLen >j-i+1){
                    minLen = j-i+1;
                    startInd = i;
                    
                }
                patternInd=0,j=i;
            }
        }
        return (startInd ==-1)?"":str1.substr(startInd,minLen);
    }
    
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string str1, str2;
        cin >> str1 >> str2;

        Solution obj;
        cout << obj.minWindow(str1, str2) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends