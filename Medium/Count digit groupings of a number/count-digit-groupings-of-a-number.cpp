//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
    vector<vector<int>>dp;
	int solve(string str , int ind ,int sum){
	    if(ind == str.length())return 1;
	    if(dp[ind][sum]!=-1)return dp[ind][sum];
	    int currSum = 0,ans =0;
	    for(int i =ind; i<str.length();++i){
	        currSum +=str[i]-'0';
	        if(currSum>=sum){
	            ans+=solve(str,i+1,currSum);
	        }
	    }
	    return dp[ind][sum]=ans;
	    
	}
	int TotalCount(string str){
	    // Code here
	    int sum = 0;
	    int n = str.length();
	    dp.resize(n,vector<int>(901,-1));
	    return solve(str,0,0);
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution ob;
		int ans = ob.TotalCount(str);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends