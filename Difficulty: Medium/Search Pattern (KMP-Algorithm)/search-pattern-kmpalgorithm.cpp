//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    vector<int>getlps(string &pat,int m){
        int len = 0;
        int j =1;// start from 1 becoz 0th index has lps 0
        vector<int>lps(m,0);
        lps[0]=0;
        while(j<m){
            if(pat[j]==pat[len]){
                len++;
                lps[j]=len;
                j++;
            }else{
                if(len==0){
                    lps[j]=0;
                    j++;
                }else{
                    len = lps[len-1];
                }
            }
        }
        return lps;
    }
        vector <int> search(string pat, string txt)
        {
            //code here
            vector<int>ans;
            int m = pat.size(),n = txt.size();
            // get lps of patt
            vector<int>lps =getlps(pat,m);
            
            int i= 0,j = 0;
            while(i<n){
                if(txt[i]==pat[j]){
                    i++;
                    j++;
                    if(j==m){
                        ans.push_back(i-j) ;// 0 base indexing bde text me patt minus kro
                        j = lps[j-1];
                    }
                }else{
                    
                    if(j==0){ // len 0 h i++ kr jaao nhi mila lps
                        i++;
                    }else{  // agr j!=0 means lps and j!=m h bgl wale puch lo
                        j = lps[j-1];
                    }
                    
                }
            }
            return ans;
        }
     
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector<int> res = ob.search(pat, S);
        if (res.size() == 0)
            cout << "[]" << endl;
        else {
            for (int i : res)
                cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// } Driver Code Ends