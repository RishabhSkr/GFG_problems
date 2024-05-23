//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string postToInfix(string exp) {
        // Write your code here
        stack<string>st;
        int n = exp.length();
        for(int i = 0;i<n;++i){
            char c = exp[i];
            if(c=='+'|| c=='-' || c=='*' ||c=='/'){
                string left = st.top();
                st.pop();
                string right =st.top();
                st.pop();
                st.push("(" + right + c + left +")");
            }else st.push(string(1,c));
        }
        if(st.empty()){
            return "";
        }else return st.top();
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string postfix;
        cin >> postfix;
        // char marker; cin >> marker;

        Solution obj;
        cout << obj.postToInfix(postfix) << endl;

        // cout << "~\n";
    }
    fclose(stdout);

    return 0;
}

// } Driver Code Ends