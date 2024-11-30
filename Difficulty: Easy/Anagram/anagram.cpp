//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function is to check whether two strings are anagram of each other or not.
    bool areAnagrams(string& s1, string& s2) {
        // Your code here
        unordered_map<char,int>mp1,mp2;
        int n1= s1.size();
        int n2 = s2.size();
        // step 1 first makr thhe freq of s1
        for(int i =0;i<n1;++i){
            mp1[s1[i]]++;
        }
        //step2: mark s2 
        for(auto x : s2)mp2[x]++;
        if(mp1==mp2)return true;
        return false;
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;

    cin >> t;

    while (t--) {
        string c, d;

        cin >> c >> d;
        Solution obj;
        if (obj.areAnagrams(c, d))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends