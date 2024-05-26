//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        // without stack
         // Compare and eliminate one that is not celebrity. Compare with the next number until reaching the last number.
        int cand = 0;
        for(int j =1;j <n;++j){
            if(M[cand][j]){
                cand = j;
            }
        }
        // Check if the final candidate is the celebrity
        for(int k = 0;k<n;++k){
            if(k==cand)continue;
            // If it knows someone, or someone doesn't know it, it's not a celebrity
            if(M[cand][k] ==1 || M[k][cand]==0)return -1;
        }
        return cand;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends