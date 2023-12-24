//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int buyMaximumProducts(int n, int k, int price[]){
        //Write your code here
        vector<pair<int,int>>v;
        for(int i = 0 ;i<n; ++i){
            v.push_back({price[i],i+1});
            
        }
        sort(v.begin(),v.end());
        int ans = 0;
        for(auto pri : v){
            int maxiBuy=min(k/pri.first,pri.second);
            ans += maxiBuy;
            k-=pri.first*maxiBuy;
          
        }
        return ans;
    }
     
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k;
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends