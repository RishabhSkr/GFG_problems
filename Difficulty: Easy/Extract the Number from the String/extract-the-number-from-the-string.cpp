//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long ExtractNumber(string sent) {

        // code here
        long long maxi =0,curr = 0;
        bool flag =true;
        for(int i=0 ;i<sent.size();++i){
            if(isdigit(sent[i]) && sent[i]!='9' && flag==true){
                curr= curr*10+sent[i]-'0';
            }else if(sent[i]=='9'){
                curr=0;
                flag=false;
            }
            if(!isdigit(sent[i])){
                if(maxi<curr)maxi = curr;
                flag =true;
                curr=0;
            }
            if(maxi<curr)maxi = curr;
        }
        if(maxi==0)return -1;
        return maxi;
    }
};

//{ Driver Code Starts.
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;
        cout << ob.ExtractNumber(s) << "\n";
    }

    return 0;
}

// } Driver Code Ends