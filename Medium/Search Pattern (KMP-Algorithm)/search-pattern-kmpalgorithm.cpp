//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        void lps(string pat,vector<int>&dp,int m){
            int suff = 0,pref =0;
            while(suff<m){
                // matched
                if(pat[suff]==pat[pref]){
                    dp[suff]=pref+1;
                    suff++,pref++;
                }
                else{
                 // not matched   
                    if(pref==0){
                        dp[suff]=0;
                    }else{
                        pref = dp[pref-1];
                        suff++;
                    }
                    
                }
            }
        }
        // vector <int> search(string pat, string txt)
        // {
        //     //code here
        //     int n = txt.size();
        //     int  m = pat.size();
        //     vector<int>dp(m,0);
        //     vector<int>ans;
        //     lps(pat,dp,m);
        //     int first = 0,second =0;
        //     while(second<m && first<n){
        //         if(pat[first]==txt[second]){
        //           first++,second++; 
        //         }else{
        //             if(second==0){
        //                 first++;
        //             }else{
        //                 second = dp[second-1];
        //                 first++;
        //             }
        //         }
        //         if(second==m){
        //             ans.push_back(first-second+1);
        //             second=0;
        //         }
            
        //     }
        //     if(ans.size()>0)return ans;
        //     return {-1};
            
        // }
        
         vector <int> search(string pat, string txt)
        {
            //code here
            int n = txt.size();
            int  m = pat.size();
            
            vector<int>ans;
            
            for(int i =0 ;i<=n-m;++i){
                int j;
                for( j=0;j<m;j++){
                    if(txt[i+j]!=pat[j])
                    break;
                    
                }
                    if(j==m)
                    ans.push_back(i+1);
            }
            
            
            if(ans.size()>0)return ans;
            return {-1};
            
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
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends