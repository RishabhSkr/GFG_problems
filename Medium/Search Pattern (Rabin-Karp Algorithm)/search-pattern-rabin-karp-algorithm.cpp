//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
vector<int> lps;

void getlps(string &pattern) {
    int len = pattern.length();
    lps.resize(len, 0); 
    lps[0] = 0;
    int i = 1, j = 0;
    while (i < len) {
        if (pattern[i] == pattern[j]) {
            lps[i] = j + 1;
            i++;
            j++;
        } else {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

vector<int> search(string pattern, string text) {
    int n = pattern.length();
    int m = text.length();
    getlps(pattern);
    vector<int> indexes;
    int i = 0, j = 0;
    while (i < m) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        } else {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
        if (j == n) {
            indexes.push_back(i - j + 1);
            j = lps[j - 1];
        }
    }
    return indexes;
}
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends