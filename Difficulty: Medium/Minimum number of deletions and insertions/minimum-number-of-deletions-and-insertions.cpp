//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    int n1 = str1.size(),n2 = str2.size();
	    vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
	    for(int i =0;i<n1;++i){
	        for(int j =0;j<n2;++j){
	            if(str1[i]==str2[j]){
	                dp[i+1][j+1]= 1+dp[i][j];
	            }else{
	                dp[i+1][j+1]= max(dp[i][j+1],dp[i+1][j]);
	            }
	        }
	    }
	    int maxi = dp[n1][n2];
	    return n1+n2-2*(maxi);
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends