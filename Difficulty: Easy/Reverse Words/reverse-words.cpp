//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string str) {
        // code here
        stack<string>st;
        string s = "";
        for(auto x: str){
            if(x=='.'){
                st.push(s);
                s="";
            }else s+=x;
        }
        st.push(s);
        string ans = "";
        while(st.size()>1){
            string op = st.top();
            ans+=op+".";
            st.pop();
        }
        ans+=st.top();
        st.pop();
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}
// } Driver Code Ends