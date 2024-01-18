//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int min_sprinklers(int gallery[], int n)
    {
        // code here
        // imp
        vector<pair<int,int>>range;
        for(int i =0;i<n;++i){
            if(gallery[i]==-1)continue;
            pair<int,int> indRange = {max(0,i-gallery[i]),min(n-1,i+gallery[i])};
            range.push_back(indRange);
        }
        
        
        sort(range.begin(),range.end());
        
        int target = 0,tap=0;
        int i =0;
        while(target<n){
            
            int maxRight = -1;
            
            while(i<range.size()){
                if(range[i].first>target) break;
                    maxRight = max(maxRight,range[i].second);
                    i++;
            }
            
            if(target>maxRight)return -1;
            tap+=1;
            target =maxRight+1;
        }
        return tap;
        
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
        
        int gallery[n];
        for(int i=0; i<n; i++)
            cin>> gallery[i];
        Solution obj;
        cout<< obj.min_sprinklers(gallery,n) << endl;
    }
	return 1;
}

// } Driver Code Ends